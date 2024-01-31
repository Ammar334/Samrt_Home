/* 
 * File:   CCP1.c
 * Author: Ammar Yasser
 *
 * Created on 30/9/2023
 */

#include "CCP1.h"

#if CCP1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
static void (*CCP1_InterruptHandeler)(void);
#endif

#if CCP2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
static void (*CCP2_InterruptHandeler)(void);
#endif
static void CCP_Timer_config(const CCP_t *ccp_obj);

Std_ReturnType CCP_Init(const CCP_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        CCP1_MODE_SELECT(CCP_MODULE_DISABLED);
        if(ccp_obj->cpp_mode == CCP_CAPTURE_MODE_SELECT)
        {
            CCP_Timer_config(ccp_obj);
            if(ccp_obj->ccp_inst == CCP1_inst)
            {
                switch(ccp_obj->ccp_spacific_mode)
                {
                    case CCP_CAPTURE_1_FALING:
                        CCP1_MODE_SELECT(CCP_CAPTURE_1_FALING);
                        break;
                    case CCP_CAPTURE_1_RISING:
                        CCP1_MODE_SELECT(CCP_CAPTURE_1_RISING);
                        break;
                    case CCP_CAPTURE_EVREY_4_RISING:
                        CCP1_MODE_SELECT(CCP_CAPTURE_EVREY_4_RISING);
                        break;
                    case CCP_CAPTURE_EVREY_16_RISING:
                        CCP1_MODE_SELECT(CCP_CAPTURE_EVREY_16_RISING);
                        break;
                    default :
                        ret = E_NOT_OK;
                }
            }
            else if(ccp_obj->ccp_inst == CCP2_inst)
            {
                switch(ccp_obj->ccp_spacific_mode)
                {
                    case CCP_CAPTURE_1_FALING:
                        CCP2_MODE_SELECT(CCP_CAPTURE_1_FALING);
                        break;
                    case CCP_CAPTURE_1_RISING:
                        CCP2_MODE_SELECT(CCP_CAPTURE_1_RISING);
                        break;
                    case CCP_CAPTURE_EVREY_4_RISING:
                        CCP2_MODE_SELECT(CCP_CAPTURE_EVREY_4_RISING);
                        break;
                    case CCP_CAPTURE_EVREY_16_RISING:
                        CCP2_MODE_SELECT(CCP_CAPTURE_EVREY_16_RISING);
                        break;
                    default :
                        ret = E_NOT_OK;
                }
            }
            
        }
        else if(ccp_obj->cpp_mode == CCP_COMPARE_MODE_SELECT)
        {
            CCP_Timer_config(ccp_obj);
            if(ccp_obj->ccp_inst == CCP1_inst)
            {
                switch(ccp_obj->ccp_spacific_mode)
                {
                    case CCP_COMPARE_TOGGLE:
                        CCP1_MODE_SELECT(CCP_COMPARE_TOGGLE);
                        break;
                    case CCP_COMPARE_SET_HIGH:
                        CCP1_MODE_SELECT(CCP_COMPARE_SET_HIGH);
                        break;
                    case CCP_COMPARE_SET_LOW:
                        CCP1_MODE_SELECT(CCP_COMPARE_SET_LOW);
                        break;
                    case CCP_COMPARE_SOFTWARE_INT_NO_REFLECT:
                        CCP1_MODE_SELECT(CCP_COMPARE_SOFTWARE_INT_NO_REFLECT);
                        break;
                    case CCP_COMPARE_TRIGGER_SPECIAL_EVENT:
                        CCP1_MODE_SELECT(CCP_COMPARE_TRIGGER_SPECIAL_EVENT);
                        break;
                    default :
                        ret = E_NOT_OK;
                }
            }
            else if(ccp_obj->ccp_inst == CCP2_inst)
            {
                switch(ccp_obj->ccp_spacific_mode)
                {
                    case CCP_COMPARE_TOGGLE:
                        CCP2_MODE_SELECT(CCP_COMPARE_TOGGLE);
                        break;
                    case CCP_COMPARE_SET_HIGH:
                        CCP2_MODE_SELECT(CCP_COMPARE_SET_HIGH);
                        break;
                    case CCP_COMPARE_SET_LOW:
                        CCP2_MODE_SELECT(CCP_COMPARE_SET_LOW);
                        break;
                    case CCP_COMPARE_SOFTWARE_INT_NO_REFLECT:
                        CCP2_MODE_SELECT(CCP_COMPARE_SOFTWARE_INT_NO_REFLECT);
                        break;
                    case CCP_COMPARE_TRIGGER_SPECIAL_EVENT:
                        CCP2_MODE_SELECT(CCP_COMPARE_TRIGGER_SPECIAL_EVENT);
                        break;
                    default :
                        ret = E_NOT_OK;
                }
            }
            
        }
        else if(ccp_obj->cpp_mode == CCP_PWM_MODE_SELECT)
        {
#if (CCP1_MODE_SELECTED == CCP_PWM_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_PWM_MODE_SELECTED)
            
            if(ccp_obj->ccp_spacific_mode == CCP_PWM_MODE)
            {
                if(ccp_obj->ccp_inst == CCP1_inst)
                {
                    CCP1_MODE_SELECT(CCP_PWM_MODE);
                }
                else if(ccp_obj->ccp_inst == CCP2_inst)
                {
                    CCP2_MODE_SELECT(CCP_PWM_MODE);
                }
                PR2 = (uint8)(((float)_XTAL_FREQ / ((float)ccp_obj->PWM_Freq * 4.0 * (float)ccp_obj->Timer2_Prescaler_value * 
                    (float)ccp_obj->Timer2_Postscaler_value)) - 1);
            }
            else
            {
                ret = E_NOT_OK;
            }
#endif
        }
        
        ret = gpio_pin_initialize(&(ccp_obj->pin));
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
#if CCP1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        CCP1_INTERRUPT_ENABLE();
        CCP1_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(ccp_obj->CCP1_Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                CCP1_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                CCP1_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        CCP1_InterruptHandeler = ccp_obj->CCP1CallBack;
#endif        
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
#if CCP2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        CCP2_INTERRUPT_ENABLE();
        CCP2_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(ccp_obj->CCP2_Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                CCP2_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                CCP2_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        CCP2_InterruptHandeler = ccp_obj->CCP2CallBack;
#endif        
        }

    }
    return ret;
}
Std_ReturnType CCP_Deinit(const CCP_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            CCP1_MODE_SELECT(CCP_MODULE_DISABLED);
        
#if CCP1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
            CCP1_INTERRUPT_DISABLE();
#endif
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            CCP2_MODE_SELECT(CCP_MODULE_DISABLED);
        
#if CCP2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
            CCP2_INTERRUPT_DISABLE();
#endif
        }

        
    }
    return ret;
}


#if (CCP1_MODE_SELECTED == CCP_CAPTURE_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_CAPTURE_MODE_SELECTED)
Std_ReturnType CCP1_IsCaptureReady(const CCP_t *ccp_obj,uint8 *capture_status)
{
    Std_ReturnType ret = E_OK;
    if((ccp_obj == NULL)||(capture_status == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            if(PIR1bits.CCP1IF == CCP_CAPTURE_READY)
            {
                *capture_status = CCP_CAPTURE_READY;
            }
            else
            {
                *capture_status = CCP_CAPTURE_NOT_READY;            
            }
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            if(PIR2bits.CCP2IF == CCP_CAPTURE_READY)
            {
                *capture_status = CCP_CAPTURE_READY;
            }
            else
            {
                *capture_status = CCP_CAPTURE_NOT_READY;            
            }
        }
    }
    return ret;
}
Std_ReturnType CCP1_Capture_read_value(const CCP_t *ccp_obj,uint16 *Capture_value)
{
    Std_ReturnType ret = E_OK;
    CCP_reg_t ccp_value= {.ccp_16bit_value = 0};
    if((ccp_obj == NULL)||(Capture_value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            ccp_value.ccp_high = CCPR1H;
            ccp_value.ccp_low  = CCPR1L; 

            *Capture_value = ccp_value.ccp_16bit_value;
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            ccp_value.ccp_high = CCPR2H;
            ccp_value.ccp_low  = CCPR2L; 

            *Capture_value = ccp_value.ccp_16bit_value;
        }
        
    }
    return ret;
}

#endif
#if (CCP1_MODE_SELECTED == CCP_COMPARE_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_COMPARE_MODE_SELECTED)
Std_ReturnType CCP1_IsCompareReady(const CCP_t *ccp_obj,uint8 *Compare_status)
{
    Std_ReturnType ret = E_OK;
    if((ccp_obj == NULL)||(Compare_status == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            if(PIR1bits.CCP1IF == CCP_COMPARE_READY)
            {
                *Compare_status = CCP_COMPARE_READY;
            }
            else
            {
                *Compare_status = CCP_COMPARE_NOT_READY;            
            }
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            if(PIR2bits.CCP2IF == CCP_COMPARE_READY)
            {
                *Compare_status = CCP_COMPARE_READY;
            }
            else
            {
                *Compare_status = CCP_COMPARE_NOT_READY;            
            }
        }
        
    }
    return ret;
}
Std_ReturnType CCP1_Compare_write_value(const CCP_t *ccp_obj,uint16 Compare_value)
{
    Std_ReturnType ret = E_OK;
    CCP_reg_t ccp_value= {.ccp_16bit_value = 0};
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            ccp_value.ccp_16bit_value = Compare_value;
            CCPR1H = ccp_value.ccp_high;
            CCPR1L = ccp_value.ccp_low;
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            ccp_value.ccp_16bit_value = Compare_value;
            CCPR2H = ccp_value.ccp_high;
            CCPR2L = ccp_value.ccp_low;
        }
        
    }
    return ret;
}
#endif
#if (CCP1_MODE_SELECTED == CCP_PWM_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_PWM_MODE_SELECTED)
Std_ReturnType CCP_PWM_set_DutyCycle(const CCP_t *ccp_obj,uint8 Duty_value)
{
    Std_ReturnType ret = E_OK;
    uint16 l_duty_temp = 0;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            l_duty_temp = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)Duty_value / 100.0));
            CCP1CONbits.DC1B = (uint8)(l_duty_temp & 0x0003);
            CCPR1L = (uint8)(l_duty_temp >> 2);
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            l_duty_temp = (uint16)((float)4 * ((float)PR2 + 1.0) * ((float)Duty_value / 100.0));
            CCP2CONbits.DC2B = (uint8)(l_duty_temp & 0x0003);
            CCPR2L = (uint8)(l_duty_temp >> 2);
        }
        
    }
    return ret;
}
Std_ReturnType CCP_PWM_Start(const CCP_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            CCP1_MODE_SELECT(CCP_PWM_MODE);
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            CCP2_MODE_SELECT(CCP_PWM_MODE);
        }
        
    }
    return ret;
}
Std_ReturnType CCP_PWM_Stop(const CCP_t *ccp_obj)
{
    Std_ReturnType ret = E_OK;
    if(ccp_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ccp_obj->ccp_inst == CCP1_inst)
        {
            CCP1_MODE_SELECT(CCP_MODULE_DISABLED);
        }
        else if(ccp_obj->ccp_inst == CCP2_inst)
        {
            CCP2_MODE_SELECT(CCP_MODULE_DISABLED);
        }
    }
    return ret;
}

#endif

void CCP1_ISR (void)
{
#if CCP1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    CCP1_INTERRUPT_CLEAR_FLAG();
    if(CCP1_InterruptHandeler != NULL)
    {
        CCP1_InterruptHandeler();
    }
#endif
}

void CCP2_ISR (void)
{
    CCP2_INTERRUPT_CLEAR_FLAG();
    if(CCP2_InterruptHandeler != NULL)
    {
        CCP2_InterruptHandeler();
    }
}

static void CCP_Timer_config(const CCP_t *ccp_obj)
{
    switch(ccp_obj->ccp_capture_timer)
    {
        case CCP1_CCP2_TIMER3:
            T3CONbits.T3CCP1 = 0; 
            T3CONbits.T3CCP2 = 1;
            break;
        case CCP1_TIMER1_CCP2_TIMER3:
            T3CONbits.T3CCP1 = 1;
            T3CONbits.T3CCP2 = 0;
            break;
        case CCP1_CCP2_TIMER1:
            T3CONbits.T3CCP1 = 0;
            T3CONbits.T3CCP2 = 0;          
    }
}
