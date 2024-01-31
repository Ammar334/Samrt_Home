/* 
 * File:   hal_adc.h
 * Author: Ammar Yasser
 *
 * Created on 22/9/2023
 */

#ifndef HAL_ADC_H
#define	HAL_ADC_H

/******Includes**********/
#include "hal_ADC_cfg.h"
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "../GPIO/hal_gpio.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../Interrupt/mcal_external_Interrupt.h"
/*********Macro Declaration***********/

#define ADC_RESULT                              (HWREG16(0xFC3))

#define ADC_AN0_ANALOG                          0x0E
#define ADC_FROM_AN0_TO_AN1_ANALOG              0x0D
#define ADC_FROM_AN0_TO_AN2_ANALOG              0x0C
#define ADC_FROM_AN0_TO_AN3_ANALOG              0x0B
#define ADC_FROM_AN0_TO_AN4_ANALOG              0x0A
#define ADC_FROM_AN0_TO_AN5_ANALOG              0x09
#define ADC_FROM_AN0_TO_AN6_ANALOG              0x08
#define ADC_FROM_AN0_TO_AN7_ANALOG              0x07
#define ADC_FROM_AN0_TO_AN8_ANALOG              0x06
#define ADC_FROM_AN0_TO_AN9_ANALOG              0x05
#define ADC_FROM_AN0_TO_AN10_ANALOG             0x04
#define ADC_FROM_AN0_TO_AN11_ANALOG             0x03
#define ADC_FROM_AN0_TO_AN12_ANALOG             0x02
#define ADC_ALL_ANALOG                          0x00
#define ADC_ALL_DIGITAL                         0x0F

#define ADC_RIGHT_ADJUST                        1U
#define ADC_LEFT_ADJUST                         0U

#define ADC_INTERNAL_VREF                       1U
#define ADC_EXTERNAL_VREF                       0U

#define ADC_CONVERSION_COMPLETED                1U
#define ADC_CONVERSION_INPROGRESS               0U


/*********Macro Function Declaration***********/


#define ADC_PORT_CONFIG(CONFIG)                         (ADCON1bits.PCFG = CONFIG)


#define ADC_CHOSE_CHANNEL(ADC_CHANNEL)                  (ADCON0bits.CHS = ADC_CHANNEL)

#define ADC_CHOSE_ACQUISITION_TIME(ACQUISITION)         (ADCON2bits.ACQT = ACQUISITION)

#define ADC_PRESCALER_SELECT(PRESCALER)                 (ADCON2bits.ADCS = PRESCALER)

/**
 * @brief  Analog-To-Digital Control
 * @note   ADC_START_CONVERSION()  : Start Analog-To-Digital Conversion
 *         ADC_CONVERSION_STATUS() : STATUS the Analog-To-Digital Converter
 */
#define ADC_START_CONVERSION()                          (ADCON0bits.GODONE = 1)
#define ADC_CONVERSION_STATUS()                         (ADCON0bits.GODONE)
/**
 * @brief  Analog-To-Digital Control
 * @note   ADC_ENABLE()  : Enable the Analog-To-Digital
 *         ADC_DISABLE() : Disable the Analog-To-Digital
 */
#define ADC_ENABLE()                                    (ADCON0bits.ADON = 1)
#define ADC_DISABLE()                                   (ADCON0bits.ADON = 0)

/**
 * @brief  Analog-To-Digital Voltage reference
 * @note   ADC_INTERNAL_VOLTAGE_REFRANCE()  : Voltage reference from VDD and VSS
 *         ADC_EXTERNAL_VOLTAGE_REFRANCE() : External Voltage reference from VREF+ and VREF-
 */
#define ADC_INTERNAL_VOLTAGE_REFRANCE()                 do{ADCON1bits.VCFG0 = 0;\
                                                           ADCON1bits.VCFG1 = 0;\
                                                        }while(0)

#define ADC_EXTERNAL_VOLTAGE_REFRANCE()                 do{ADCON1bits.VCFG0 = 1;\
                                                           ADCON1bits.VCFG1 = 1;\
                                                        }while(0)

#define ADC_ADJUST_SELECT(ADJUST)                       (ADCON2bits.ADFM = ADJUST)                

/*********Data Types Declaration***********/

typedef enum 
{
    ADC_CHANNEL0 = 0,
    ADC_CHANNEL1,
    ADC_CHANNEL2,
    ADC_CHANNEL3,
    ADC_CHANNEL4,
    ADC_CHANNEL5,
    ADC_CHANNEL6,
    ADC_CHANNEL7,
    ADC_CHANNEL8,
    ADC_CHANNEL9,
    ADC_CHANNEL10,
    ADC_CHANNEL11,
    ADC_CHANNEL12   
            
}ADC_Channel_t;

typedef enum
{
    ADC_0TAD = 0,
    ADC_2TAD,
    ADC_4TAD,
    ADC_6TAD,
    ADC_8TAD,
    ADC_12TAD,
    ADC_16TAD,
    ADC_20TAD
            
}ADC_Acquisition_Time_t;

typedef enum
{
    ADC_2FOSC = 0,
    ADC_8FOSC,
    ADC_32FOSC,
    ADC_FRC,
    ADC_4FOSC,
    ADC_16FOSC,
    ADC_64FOSC
            
}ADC_Prescaler_t;

typedef struct
{
#if ADC_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*ADC_CallBack) (void);
    Intterupt_priorty_t priorty;
#endif
    ADC_Channel_t ADC_Channel;                           //@ref ADC_Channel_t
    ADC_Acquisition_Time_t   Acquisition_Time;           //@ref ADC_Acquisition_Time_t
    ADC_Prescaler_t  Prescaler;                         //@ref ADC_Prescaler_t 
    uint8 voltage_refrence  : 1;
    uint8 Result_format     : 1;  
    uint8 Reserved          : 6;
}ADC_t;

/*********Function Declaration***********/

Std_ReturnType ADC_init(const ADC_t* ADC_obj);
Std_ReturnType ADC_deinit(const ADC_t* ADC_obj);
Std_ReturnType ADC_Select_Channel(const ADC_t* ADC_obj,ADC_Channel_t channel);
Std_ReturnType ADC_Start_Conversion(const ADC_t* ADC_obj);
Std_ReturnType ADC_ISConversionDone(const ADC_t* ADC_obj,uint8 *conversion_status);
Std_ReturnType ADC_Read_Result(const ADC_t* ADC_obj,uint16 *Resualt);
Std_ReturnType ADC_GetConversion_Blocking(const ADC_t* ADC_obj,ADC_Channel_t channel,uint16 *Resualt);
Std_ReturnType ADC_StartConversion_INT(const ADC_t* ADC_obj,ADC_Channel_t channel);




#endif	/* HAL_ADC_H */

