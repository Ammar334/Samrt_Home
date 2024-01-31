/* 
 * File:   CCP1.h
 * Author: Ammar Yasser
 *
 * Created on 30/9/2023
 */

#ifndef CCP1_H
#define	CCP1_H

/******Includes**********/

#include "CCP1_cfg.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"

/*********Macro Declaration***********/

#define CCP_POSTSCALER_DIV_1                             1
#define CCP_POSTSCALER_DIV_2                             2
#define CCP_POSTSCALER_DIV_3                             3
#define CCP_POSTSCALER_DIV_4                             4
#define CCP_POSTSCALER_DIV_5                             5
#define CCP_POSTSCALER_DIV_6                             6
#define CCP_POSTSCALER_DIV_7                             7
#define CCP_POSTSCALER_DIV_8                             8
#define CCP_POSTSCALER_DIV_9                             9
#define CCP_POSTSCALER_DIV_10                            10
#define CCP_POSTSCALER_DIV_11                            11
#define CCP_POSTSCALER_DIV_12                            12
#define CCP_POSTSCALER_DIV_13                            13
#define CCP_POSTSCALER_DIV_14                            14
#define CCP_POSTSCALER_DIV_15                            15
#define CCP_POSTSCALER_DIV_16                            16

#define CCP_PRESCALER_DIV_1                              1
#define CCP_PRESCALER_DIV_4                              4
#define CCP_PRESCALER_DIV_16                             16

#define CCP_MODULE_DISABLED                        (uint8)0
#define CCP_CAPTURE_1_FALING                       (uint8)4
#define CCP_CAPTURE_1_RISING                       (uint8)5
#define CCP_CAPTURE_EVREY_4_RISING                 (uint8)6
#define CCP_CAPTURE_EVREY_16_RISING                (uint8)7
#define CCP_COMPARE_TOGGLE                         (uint8)2
#define CCP_COMPARE_SET_HIGH                       (uint8)8
#define CCP_COMPARE_SET_LOW                        (uint8)9
#define CCP_COMPARE_SOFTWARE_INT_NO_REFLECT        (uint8)10
#define CCP_COMPARE_TRIGGER_SPECIAL_EVENT          (uint8)11
#define CCP_PWM_MODE                               (uint8)12

#define CCP_CAPTURE_READY                          1
#define CCP_CAPTURE_NOT_READY                      0

#define CCP_COMPARE_READY                          1
#define CCP_COMPARE_NOT_READY                      0

/*********Macro Function Declaration***********/

#define CCP1_MODE_SELECT(MODE)                      (CCP1CONbits.CCP1M = MODE)
#define CCP2_MODE_SELECT(MODE)                      (CCP2CONbits.CCP2M = MODE)


/*********Data Types Declaration***********/

typedef enum
{
    CCP_COMPARE_MODE_SELECT,
    CCP_CAPTURE_MODE_SELECT,
    CCP_PWM_MODE_SELECT
}ccp_mode_t;

typedef enum
{
    CCP1_inst,
    CCP2_inst
}ccp_inst_t;

typedef enum{
    CCP1_CCP2_TIMER3 = 0,
    CCP1_TIMER1_CCP2_TIMER3,
    CCP1_CCP2_TIMER1
}ccp_capture_timer_t;

typedef union
{
    struct
    {
        uint8 ccp_low;
        uint8 ccp_high;
    };
    struct
    {
        uint16 ccp_16bit_value;
    };
}CCP_reg_t;

typedef struct
{
    ccp_mode_t cpp_mode;
    ccp_inst_t ccp_inst;
    uint8 ccp_spacific_mode;
    pin_config pin;
    ccp_capture_timer_t ccp_capture_timer;
#if CCP1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*CCP1CallBack)(void);
    Intterupt_priorty_t CCP1_Priorty;
#endif
#if CCP2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*CCP2CallBack)(void);
    Intterupt_priorty_t CCP2_Priorty;
#endif
#if (CCP1_MODE_SELECTED == CCP_PWM_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_PWM_MODE_SELECTED)
    uint32 PWM_Freq;
    uint8  Timer2_Prescaler_value                  : 2;
    uint8  Timer2_Postscaler_value                 : 4;
#endif
    
}CCP_t;



/*********Function Declaration***********/

Std_ReturnType CCP_Init(const CCP_t *ccp_obj);
Std_ReturnType CCP_Deinit(const CCP_t *ccp_obj);


#if (CCP1_MODE_SELECTED == CCP_CAPTURE_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_CAPTURE_MODE_SELECTED)
Std_ReturnType CCP1_IsCaptureReady(const CCP_t *ccp_obj,uint8 *capture_status);
Std_ReturnType CCP1_Capture_read_value(const CCP_t *ccp_obj,uint16 *Capture_value);

#endif
#if (CCP1_MODE_SELECTED == CCP_COMPARE_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_COMPARE_MODE_SELECTED)
Std_ReturnType CCP1_IsCompareReady(const CCP_t *ccp_obj,uint8 *Compare_status);
Std_ReturnType CCP1_Compare_write_value(const CCP_t *ccp_obj,uint16 Compare_value);
#endif
#if (CCP1_MODE_SELECTED == CCP_PWM_MODE_SELECTED)||(CCP2_MODE_SELECTED == CCP_PWM_MODE_SELECTED)
Std_ReturnType CCP_PWM_set_DutyCycle(const CCP_t *ccp_obj,uint8 Duty_value);
Std_ReturnType CCP_PWM_Start(const CCP_t *ccp_obj);
Std_ReturnType CCP_PWM_Stop(const CCP_t *ccp_obj);

#endif


#endif	/* CCP1_H */

