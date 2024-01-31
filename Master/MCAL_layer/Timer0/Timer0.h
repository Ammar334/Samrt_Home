/* 
 * File:   Timer0.h
 * Author: Ammar Yasser
 *
 * Created on 26 /9/2023
 */
#ifndef TIMER0_H
#define	TIMER0_H

/******Includes**********/
#include "Timer0_cfg.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
/*********Macro Declaration***********/

#define TIMER0_RISING_EDGE                  0
#define TIMER0_FALLING_EDGE                 1

#define TIMER0_PRESCALER_ENABLE_CFG         1
#define TIMER0_PRESCALER_DISABLE_CFG        0

#define TIMER0_8BIT_SIZE                    1
#define TIMER0_16BIT_SIZE                   0

#define TIMER0_COUNTER_MODE                 1
#define TIMER0_TIMER_MODE                   0


/*********Macro Function Declaration***********/

#define TIMER0_ENABLE()                     (T0CONbits.TMR0ON = 1)
#define TIMER0_DISABLE()                    (T0CONbits.TMR0ON = 0)

#define TIMER0_COUNTER_MODE_ENABLE()               (T0CONbits.T0CS = 1)
#define TIMER0_TIMER_MODE_ENABLE()                 (T0CONbits.T0CS = 0)

#define TIMER0_8BIT_CONFIGRATION()          (T0CONbits.T08BIT = 1)
#define TIMER0_16BIT_CONFIGRATION()         (T0CONbits.T08BIT = 0)

#define TIMER0_COUNTER_EDGE_SELECT(EDGE)    (T0CONbits.T0SE = EDGE)

#define TIMER0_PRESCALER_ENABLE()           (T0CONbits.PSA = 0)
#define TIMER0_PRESCALER_DISABLE()          (T0CONbits.PSA = 1)

#define TIMER0_PRESCALER_SELECT(PRESCALER)  (T0CONbits.T0PS = PRESCALER)


/*********Data Types Declaration***********/

typedef enum
{
    TIMER0_prescaler_Div_2 = 0,
    TIMER0_prescaler_Div_4,
    TIMER0_prescaler_Div_8,
    TIMER0_prescaler_Div_16,
    TIMER0_prescaler_Div_32,
    TIMER0_prescaler_Div_64,
    TIMER0_prescaler_Div_128,
    TIMER0_prescaler_Div_256
}Prescaler_t;

typedef struct
{
#if TIMER0_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*Timer0CallBack) (void);
    Intterupt_priorty_t Priorty;
#endif
    uint16  timer0_preload_value;
    Prescaler_t prescaler_value;
    uint8 Timer0_MODE               : 1;
    uint8 Timer0_counter_EDGE       : 1;
    uint8 Timer0_register_size      : 1;
    uint8 prescaler_Enable          : 1;
    uint8 Reserved                  : 4;   
}TIMER0_t;


/*********Function Declaration***********/

Std_ReturnType Timer0_init(const TIMER0_t *TM0_obj);
Std_ReturnType Timer0_Write_Value(const TIMER0_t *TM0_obj,uint16 value);
Std_ReturnType Timer0_Read_Value(const TIMER0_t *TM0_obj,uint16 *value);
Std_ReturnType Timer0_Deinit(const TIMER0_t *TM0_obj);





#endif	/* TIMER0_H */

