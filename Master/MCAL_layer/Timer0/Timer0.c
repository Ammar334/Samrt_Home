/* 
 * File:   Timer0.c
 * Author: Ammar Yasser
 *
 * Created on 26/9/2023
 */
#include "Timer0.h"
#if TIMER0_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
static void (*Timer0InterruptHandeler)(void);
#endif

static Std_ReturnType Timer0_REGISTER_select(const TIMER0_t *TM0_obj);
static Std_ReturnType Timer0_Mode_select(const TIMER0_t *TM0_obj);
static Std_ReturnType Timer0_Prescaler_select(const TIMER0_t *TM0_obj);

static uint16 timer0_preload = 0;
/**
 * 
 * @param TM0_obj
 * @return 
 */
Std_ReturnType Timer0_init(const TIMER0_t *TM0_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM0_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Timer Disable
        TIMER0_DISABLE();
        //Timer REGISTER Size Select
        Timer0_REGISTER_select(TM0_obj);
        //Timer Mode Select
        Timer0_Mode_select(TM0_obj);
        //Timer Prescaler Select
        Timer0_Prescaler_select(TM0_obj);
        //Enable Interrupt
#if TIMER0_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_ENABLE();
        TIMER0_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(TM0_obj->Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                TIMER0_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                TIMER0_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        Timer0InterruptHandeler = TM0_obj->Timer0CallBack;
#endif        
        //Initialize Timer0
        ret = Timer0_Write_Value(TM0_obj,(TM0_obj->timer0_preload_value));
        timer0_preload = TM0_obj->timer0_preload_value;
        //Enable Timer0 
        TIMER0_ENABLE();
        
    }
    return ret;
}

/**
 * 
 * @param TM0_obj
 * @param value
 * @return 
 */
Std_ReturnType Timer0_Write_Value(const TIMER0_t *TM0_obj,uint16 value)
{
    Std_ReturnType ret = E_OK;
    if(TM0_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(TM0_obj->Timer0_register_size)
        {
            case TIMER0_8BIT_SIZE:
                TMR0L = (uint8)value;
                break;
            case TIMER0_16BIT_SIZE:
                TMR0H = value>>8;
                TMR0L = (uint8)value;
                break;
            default :
                ret = E_NOT_OK;
        }
    }
    return ret;
    
}

/**
 * 
 * @param TM0_obj
 * @param value
 * @return 
 */
Std_ReturnType Timer0_Read_Value(const TIMER0_t *TM0_obj,uint16 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 l_timerh =0 ;
    uint8 l_timerl =0 ;

    if((TM0_obj == NULL)||(value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(TM0_obj->Timer0_register_size)
        {
            case TIMER0_8BIT_SIZE:
                *value = TMR0L;
                break;
            case TIMER0_16BIT_SIZE:
                l_timerl = TMR0L;
                l_timerh = TMR0H;
                *value = (uint16)(l_timerl + (l_timerh<<8));
                break;
            default :
                ret = E_NOT_OK;
        }
    }
    return ret;
}

/**
 * 
 * @param TM0_obj
 * @return 
 */
Std_ReturnType Timer0_Deinit(const TIMER0_t *TM0_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM0_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable Interrupt
#if TIMER0_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER0_INTERRUPT_DISABLE();
#endif
        //Timer Disable
        TIMER0_DISABLE();
    }
    return ret;
}

static Std_ReturnType Timer0_REGISTER_select(const TIMER0_t *TM0_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM0_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(TM0_obj->Timer0_register_size)
        {
            case TIMER0_8BIT_SIZE:
                TIMER0_8BIT_CONFIGRATION();
                break;
            case TIMER0_16BIT_SIZE:
                TIMER0_16BIT_CONFIGRATION();
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType Timer0_Mode_select(const TIMER0_t *TM0_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM0_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(TM0_obj->Timer0_MODE)
        {
            case TIMER0_COUNTER_MODE :
                TIMER0_COUNTER_MODE_ENABLE();
                TIMER0_COUNTER_EDGE_SELECT(TM0_obj->Timer0_counter_EDGE);
                break;
            case TIMER0_TIMER_MODE :
                TIMER0_TIMER_MODE_ENABLE();
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}

static Std_ReturnType Timer0_Prescaler_select(const TIMER0_t *TM0_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM0_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(TM0_obj->prescaler_Enable)
        {
            case TIMER0_PRESCALER_ENABLE_CFG:
                TIMER0_PRESCALER_ENABLE();
                TIMER0_PRESCALER_SELECT(TM0_obj->prescaler_value);
                break;
            case TIMER0_PRESCALER_DISABLE_CFG:
                TIMER0_PRESCALER_DISABLE();
                break;
            default:
                ret = E_NOT_OK;
        }
    }
    return ret;
}
void TIMER0_ISR (void)
{
    TIMER0_INTERRUPT_CLEAR_FLAG();
    TMR0H = (uint8)(timer0_preload>>8);
    TMR0L = (uint8)(timer0_preload);
    if(Timer0InterruptHandeler != NULL)
    {
        Timer0InterruptHandeler();
    }
}