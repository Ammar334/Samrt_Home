/* 
 * File:   Timer1.c
 * Author: AMMAR YASSER
 *
 * Created on 27/9/2023
 */

#include "Timer1.h"

#if TIMER1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
static void (*Timer1InterruptHandeler)(void);
#endif

static uint16 timer1_preload = 0;


Std_ReturnType Timer1_init(const Timer1_t *TM1_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM1_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TIMER1_DISABLE();
        TIMER1_MODE_SELECT(TM1_obj->Timer1_MODE);
        if(TM1_obj->Timer1_MODE == TIMER1_COUNTER_MODE)
        {
            TIMER1_COUNTER_MODE_SYNC_SELECT(TM1_obj->Timer1_Counter_Mode_SYNC);
        }

        TIMER1_READ_WRITE_REG_SIZE_SELECT(TM1_obj->Timer1_wr_register_size);
        TIMER1_PRESCALER_SELECT(TM1_obj->prescaler_value);
        TMR1H = (TM1_obj->Timer1_preload_value)>>8;
        TMR1L = (uint8)(TM1_obj->Timer1_preload_value);
        timer1_preload = TM1_obj->Timer1_preload_value;
#if TIMER1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER1_INTERRUPT_ENABLE();
        TIMER1_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(TM1_obj->Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                TIMER1_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                TIMER1_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        Timer1InterruptHandeler = TM1_obj->Timer1CallBack;
#endif
        TIMER1_ENABLE();
    }
    return ret;
}
Std_ReturnType Timer1_Write_Value(const Timer1_t *TM1_obj,uint16 value)
{
    Std_ReturnType ret = E_OK;
    if(TM1_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TMR1H = value>>8;
        TMR1L = (uint8)value;
    }
    return ret;
}
Std_ReturnType Timer1_Read_Value(const Timer1_t *TM1_obj,uint16 *value)
{
    Std_ReturnType ret = E_OK;
    uint8 l_timerh =0 ;
    uint8 l_timerl =0 ;
    if((TM1_obj == NULL)||(value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        l_timerl = TMR1L;
        l_timerh = TMR1H;
        *value = (uint16)(l_timerl + (l_timerh<<8));
    }
    return ret;
}
Std_ReturnType Timer1_Deinit(const Timer1_t *TM1_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM1_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable Interrupt
#if TIMER1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER1_INTERRUPT_DISABLE();
#endif
        //Timer Disable
        TIMER1_DISABLE();
    }
    return ret;
}

void TIMER1_ISR  (void)
{
    TIMER1_INTERRUPT_CLEAR_FLAG();
    TMR1H = (uint8)(timer1_preload>>8);
    TMR1L = (uint8)(timer1_preload);
    if(Timer1InterruptHandeler != NULL)
    {
        Timer1InterruptHandeler();
    }
}