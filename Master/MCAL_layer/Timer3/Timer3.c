/* 
 * File:   Timer3.c
 * Author: Ammar Yasser
 *
 * Created on 28/9/2023
 */
#include "Timer3.h"

#if TIMER3_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
static void (*Timer3InterruptHandeler)(void);
#endif

static uint16 timer3_preload = 0;


Std_ReturnType Timer3_init(const Timer3_t *TM3_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM3_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TIMER3_DISABLE();
        TIMER3_PRESCALER_SELECT(TM3_obj->prescaler_value);
        TIMER3_MODE_SELECT(TM3_obj->Timer3_MODE);
        if(TM3_obj->Timer3_MODE == TIMER3_COUNTER_MODE)
        {
            TIMER3_COUNTER_MODE_SYNC_SELECT(TM3_obj->Timer3_Counter_Mode_SYNC);
        }
        TIMER3_READ_WRITE_REG_SIZE_SELECT(TM3_obj->Timer3_wr_register_size);
        TMR3H = (TM3_obj->Timer3_preload_value)>>8;
        TMR3L = (uint8)(TM3_obj->Timer3_preload_value);
        timer3_preload = TM3_obj->Timer3_preload_value;
#if TIMER3_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_ENABLE();
        TIMER3_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(TM3_obj->Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                TIMER3_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                TIMER3_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        Timer3InterruptHandeler = TM3_obj->Timer3CallBack;
#endif
        
        TIMER3_ENABLE();
    }
    return ret;
}
Std_ReturnType Timer3_Write_Value(const Timer3_t *TM3_obj,uint16 value)
{
    Std_ReturnType ret = E_OK;
    if(TM3_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TMR3H = value>>8;
        TMR3L = (uint8)value;
    }
    return ret;
}
Std_ReturnType Timer3_Read_Value(const Timer3_t *TM3_obj,uint16 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 l_timerh =0 ;
    uint8 l_timerl =0 ;
    if((TM3_obj == NULL)||(value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        l_timerl = TMR3L;
        l_timerh = TMR3H;
        *value = (uint16)(l_timerl + (l_timerh<<8));
    }
    return ret;
}
Std_ReturnType Timer3_Deinit(const Timer3_t *TM3_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM3_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable Interrupt
#if TIMER3_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER3_INTERRUPT_DISABLE();
#endif
        //Timer Disable
        TIMER3_DISABLE();
    }
    return ret;
}

void TIMER3_ISR (void)
{
    TIMER3_INTERRUPT_CLEAR_FLAG();
    TMR3H = (uint8)(timer3_preload>>8);
    TMR3L = (uint8)(timer3_preload);
    if(Timer3InterruptHandeler != NULL)
    {
        Timer3InterruptHandeler();
    }
}