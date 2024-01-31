/* 
 * File:   hal_adc.c
 * Author: Ammar Yasser
 *
 * Created on 22/9/2023
 */

#include "hall_ADC.h"

#if ADC_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE

void (*ADC_InterruptCallBack) (void);

#endif

static Std_ReturnType ADC_configure_Channel(ADC_Channel_t channel);

/**
 * 
 * @param ADC_obj
 * @return 
 */
Std_ReturnType ADC_init(const ADC_t* ADC_obj)
{
    Std_ReturnType ret = E_OK;
    if(ADC_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //ADC disable
        ADC_DISABLE();
        //configure Acquisition time
        ADC_CHOSE_ACQUISITION_TIME(ADC_obj->Acquisition_Time);
        //configure prescaler
        ADC_PRESCALER_SELECT(ADC_obj->Prescaler);
        //configure the default channel
        ADC_CHOSE_CHANNEL(ADC_obj->ADC_Channel);
        ADC_configure_Channel(ADC_obj->ADC_Channel);
        //configure interrupt
#if ADC_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        ADC_INTERRUPT_ENABLE();
        ADC_INTERRUPT_CLEAR_FLAG(); 
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(ADC_obj->priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                ADC_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                ADC_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        ADC_InterruptCallBack = ADC_obj->ADC_CallBack;
#endif
        //configure result format
        ADC_ADJUST_SELECT(ADC_obj->Result_format);
        //configure voltage reference
        if(ADC_obj->voltage_refrence == ADC_INTERNAL_VREF)
        {
            ADC_INTERNAL_VOLTAGE_REFRANCE();
        }
        else if(ADC_obj->voltage_refrence == ADC_EXTERNAL_VREF)
        {
            ADC_EXTERNAL_VOLTAGE_REFRANCE();
        }
        else
        {
            ADC_INTERNAL_VOLTAGE_REFRANCE();
        }
        //enable ADC
        ADC_ENABLE();
        
    }
    return ret;
}

/**
 * 
 * @param ADC_obj
 * @return 
 */
Std_ReturnType ADC_deinit(const ADC_t* ADC_obj)
{
    Std_ReturnType ret = E_OK;
    if(ADC_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //Disable Interrupt
#if ADC_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        ADC_INTERRUPT_DISABLE();
#endif
        //disable ADC
        ADC_DISABLE();
    }
    return ret;
}

/**
 * 
 * @param ADC_obj
 * @param channel
 * @return 
 */
Std_ReturnType ADC_Select_Channel(const ADC_t* ADC_obj,ADC_Channel_t channel)
{
    Std_ReturnType ret = E_OK;
    if(ADC_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ADC_CHOSE_CHANNEL(channel);
        ADC_configure_Channel(channel);
    }
    return ret;
}

/**
 * 
 * @param ADC_obj
 * @return 
 */
Std_ReturnType ADC_Start_Conversion(const ADC_t* ADC_obj)
{
    Std_ReturnType ret = E_OK;
    if(ADC_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ADC_START_CONVERSION();
    }
    return ret;
}

/**
 * 
 * @param ADC_obj
 * @param conversion_status
 * @return 
 */
Std_ReturnType ADC_ISConversionDone(const ADC_t* ADC_obj,uint8 *conversion_status)
{
    Std_ReturnType ret = E_OK;
    if((ADC_obj == NULL)||(conversion_status == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        *conversion_status = (uint8)(!(ADC_CONVERSION_STATUS()));
    }
    return ret;
}

/**
 * 
 * @param ADC_obj
 * @param Resualt
 * @return 
 */
Std_ReturnType ADC_Read_Result(const ADC_t* ADC_obj,uint16 *Resualt)
{
    Std_ReturnType ret = E_OK;
    if((ADC_obj == NULL)||(Resualt == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(ADC_obj->Result_format == ADC_RIGHT_ADJUST)
        {
            // *Resualt = (uint16) ((ADRESH<<8) + ADRESL)
            *Resualt =  ADC_RESULT;
        }
        else if(ADC_obj->Result_format == ADC_LEFT_ADJUST)
        {
            *Resualt = (uint16) (((ADRESH<<8) + ADRESL)>>6);
        }
        else 
        {
            *Resualt =  ADC_RESULT;
        }
        
    }
    return ret;
}

/**
 * 
 * @param ADC_obj
 * @param conversion_status
 * @param channel
 * @param Resualt
 * @return 
 */
Std_ReturnType ADC_GetConversion_Blocking(const ADC_t* ADC_obj,ADC_Channel_t channel,uint16 *Resualt)
{
    Std_ReturnType ret = E_OK;
    if((ADC_obj == NULL)||(Resualt == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = ADC_Select_Channel(ADC_obj,channel);
        
        ret = ADC_Start_Conversion(ADC_obj);
        
        while(ADC_CONVERSION_STATUS());
        
        ret = ADC_Read_Result(ADC_obj,Resualt);
        
    }
    return ret;
}

Std_ReturnType ADC_StartConversion_INT(const ADC_t* ADC_obj,ADC_Channel_t channel)
{
    Std_ReturnType ret = E_OK;
    uint8 l_conversion_status = 0;
    if(ADC_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = ADC_Select_Channel(ADC_obj,channel);
        
        ret = ADC_Start_Conversion(ADC_obj);
        
    }
    return ret;
}

static Std_ReturnType ADC_configure_Channel(ADC_Channel_t channel)
{
    Std_ReturnType ret = E_OK;
   
        switch(channel)
        {
            case ADC_CHANNEL0:
                SET_BIT(TRISA,_TRISA_RA0_POSN);
                break;
            case ADC_CHANNEL1:
                SET_BIT(TRISA,_TRISA_RA1_POSN);
                break;
              case ADC_CHANNEL2:
                SET_BIT(TRISA,_TRISA_RA2_POSN);
                break;
            case ADC_CHANNEL3:
                SET_BIT(TRISA,_TRISA_RA3_POSN);
                break;
            case ADC_CHANNEL4:
                SET_BIT(TRISA,_TRISA_RA5_POSN);
                break;
            case ADC_CHANNEL5:
                SET_BIT(TRISE,_TRISE_RE0_POSN);
                break;
            case ADC_CHANNEL6:
                SET_BIT(TRISE,_TRISE_RE1_POSN);
                break;
            case ADC_CHANNEL7:
                SET_BIT(TRISE,_TRISE_RE2_POSN);
                break;
            case ADC_CHANNEL8:
                SET_BIT(TRISB,_TRISB_RB2_POSN);
                break;
            case ADC_CHANNEL9:
                SET_BIT(TRISB,_TRISB_RB3_POSN);
                break;
            case ADC_CHANNEL10:
                SET_BIT(TRISB,_TRISB_RB1_POSN);
                break;
            case ADC_CHANNEL11:
                SET_BIT(TRISB,_TRISB_RB4_POSN);
                break;
            case ADC_CHANNEL12:
                SET_BIT(TRISB,_TRISB_RB0_POSN);
                break;
            default:
                ret = E_NOT_OK;
                
        }
        return ret;
    
}

void ADC_ISR  (void)
{
    ADC_INTERRUPT_CLEAR_FLAG();
    if(ADC_InterruptCallBack != NULL)
    {
        ADC_InterruptCallBack();
    }
}