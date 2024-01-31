/* 
 * File:   Timer2c.
 * Author: Ammar Yasser
 *
 * Created on 28/9/2023
 */

#include "Timer2.h"

#if TIMER2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
static void (*Timer2InterruptHandeler)(void);
#endif

static uint8 timer2_preload = 0;

Std_ReturnType Timer2_init(const Timer2_t *TM2_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM2_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TIMER2_DISABLE();
        TIMER2_PRESCALER_SELECT(TM2_obj->prescaler_value);
        TIMER2_POSTSCALER_SELECT(TM2_obj->postcaler_value);
        TMR2 = TM2_obj->preload_value;
        timer2_preload = TM2_obj->preload_value;
#if TIMER2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_ENABLE();
        TIMER2_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(TM2_obj->Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                TIMER2_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                TIMER2_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        Timer2InterruptHandeler = TM2_obj->Timer2CallBack;
#endif
        TIMER2_ENABLE();
    }
    return ret;
}
Std_ReturnType Timer2_Write_Value(const Timer2_t *TM2_obj,uint8 value)
{
    Std_ReturnType ret = E_OK;
    if(TM2_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        TMR2 = TM2_obj->preload_value;
    }
    return ret;
}
Std_ReturnType Timer2_Read_Value(const Timer2_t *TM2_obj,uint8 *value)
{
    Std_ReturnType ret = E_OK;
    if((TM2_obj == NULL)||(value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *value = TMR2;
    }
    return ret;
}
Std_ReturnType Timer2_Deinit(const Timer2_t *TM2_obj)
{
    Std_ReturnType ret = E_OK;
    if(TM2_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable Interrupt
#if TIMER2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        TIMER2_INTERRUPT_DISABLE();
#endif
        //Timer Disable
        TIMER2_DISABLE();
    }
    return ret;
}

void TIMER2_ISR  (void)
{
    TIMER2_INTERRUPT_CLEAR_FLAG();
    TMR2 = timer2_preload;
    if(Timer2InterruptHandeler != NULL)
    {
        Timer2InterruptHandeler();
    }
}