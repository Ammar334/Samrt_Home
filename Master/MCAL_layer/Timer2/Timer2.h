/* 
 * File:   Timer2g.h
 * Author: Ammar Yasser
 *
 * Created on 28/9/2023
 */


#ifndef TIMER2_H
#define	TIMER2_H

/******Includes**********/
#include "Timer2_cfg.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"

/*********Macro Declaration***********/

#define TIMER2_POSTSCALER_DIV_1                             0
#define TIMER2_POSTSCALER_DIV_2                             1
#define TIMER2_POSTSCALER_DIV_3                             2
#define TIMER2_POSTSCALER_DIV_4                             3
#define TIMER2_POSTSCALER_DIV_5                             4
#define TIMER2_POSTSCALER_DIV_6                             5
#define TIMER2_POSTSCALER_DIV_7                             6
#define TIMER2_POSTSCALER_DIV_8                             7
#define TIMER2_POSTSCALER_DIV_9                             8
#define TIMER2_POSTSCALER_DIV_10                            9
#define TIMER2_POSTSCALER_DIV_11                            10
#define TIMER2_POSTSCALER_DIV_12                            11
#define TIMER2_POSTSCALER_DIV_13                            12
#define TIMER2_POSTSCALER_DIV_14                            13
#define TIMER2_POSTSCALER_DIV_15                            14
#define TIMER2_POSTSCALER_DIV_16                            15

#define TIMER2_PRESCALER_DIV_1                              0
#define TIMER2_PRESCALER_DIV_4                              1
#define TIMER2_PRESCALER_DIV_16                             2


/*********Macro Function Declaration***********/

#define TIMER2_POSTSCALER_SELECT(POSTSCALER)                (T2CONbits.TOUTPS = POSTSCALER)
#define TIMER2_PRESCALER_SELECT(PRESCALER)                  (T2CONbits.T2CKPS = PRESCALER)

#define TIMER2_ENABLE()                                      (T2CONbits.TMR2ON = 1)
#define TIMER2_DISABLE()                                     (T2CONbits.TMR2ON = 0)




/*********Data Types Declaration***********/

typedef struct
{
#if TIMER2_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*Timer2CallBack)(void);
    Intterupt_priorty_t Priorty;
#endif
    uint8  preload_value;
    uint8  prescaler_value   : 2;
    uint8  postcaler_value   : 4;
    uint8  Reserved          : 2;
}Timer2_t;

/*********Function Declaration***********/

Std_ReturnType Timer2_init(const Timer2_t *TM2_obj);
Std_ReturnType Timer2_Write_Value(const Timer2_t *TM2_obj,uint8 value);
Std_ReturnType Timer2_Read_Value(const Timer2_t *TM2_obj,uint8 *value);
Std_ReturnType Timer2_Deinit(const Timer2_t *TM2_obj);

#endif	/* TIMER2_H */

