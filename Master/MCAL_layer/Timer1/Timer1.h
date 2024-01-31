/* 
 * File:   Timer1.h
 * Author: AMMAR YASSER
 *
 * Created on 27/9/2023
 */

#ifndef TIMER1_H
#define	TIMER1_H

/*************Includes***************/
#include "Timer1_cfg.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"
#include "../Interrupt/mcal_external_Interrupt.h"


/*********Macro Declaration***********/

#define TIMER1_8BIT_READ_WRITE_REG_SIZE                     0
#define TIMER1_16BIT_READ_WRITE_REG_SIZE                    1

#define TIMER1_SYNCHRONIZE                                  0
#define TIMER1_ASSYNCHRONIZE                                1

#define TIMER1_TIMER_MODE                                   0
#define TIMER1_COUNTER_MODE                                 1

#define TIMER1_prescaler_Div_1                              0
#define TIMER1_prescaler_Div_2                              1
#define TIMER1_prescaler_Div_4                              2
#define TIMER1_prescaler_Div_8                              3


/*********Macro Function Declaration***********/

#define TIMER1_READ_WRITE_REG_SIZE_SELECT(SIZE)             (T1CONbits.RD16 = SIZE)

#define TIMER1_SYSTEM_CLK_SOURCE_STATUS()                   (T1CONbits.T1RUN)

#define TIMER1_PRESCALER_SELECT(PRESCALER)                  (T1CONbits.T1CKPS = PRESCALER)

#define TIMER1_OSCILLATOR_ENABLE()                          (T1CONbits.T1OSCEN = 1)
#define TIMER1_OSCILLATOR_DISABLE()                         (T1CONbits.T1OSCEN = 0)

#define TIMER1_COUNTER_MODE_SYNC_SELECT(SYNC)               (T1CONbits.T1SYNC = SYNC)

#define TIMER1_MODE_SELECT(MODE)                            (T1CONbits.TMR1CS = MODE)

#define TIMER1_ENABLE()                                     (T1CONbits.TMR1ON = 1)
#define TIMER1_DISABLE()                                    (T1CONbits.TMR1ON = 0)
/*********Data Types Declaration***********/

typedef struct
{
#if TIMER1_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*Timer1CallBack)(void);
    Intterupt_priorty_t Priorty;
#endif
    uint16  Timer1_preload_value;
    uint8  prescaler_value              : 2;
    uint8  Timer1_MODE                  : 1;
    uint8  Timer1_wr_register_size      : 1;
    uint8  Timer1_Counter_Mode_SYNC     : 1;
    uint8  Timer1_OSC_cfg               : 1;
    uint8  Reserved                     : 2;
}Timer1_t;



/*********Function Declaration***********/

Std_ReturnType Timer1_init(const Timer1_t *TM1_obj);
Std_ReturnType Timer1_Write_Value(const Timer1_t *TM1_obj,uint16 value);
Std_ReturnType Timer1_Read_Value(const Timer1_t *TM1_obj,uint16 *value);
Std_ReturnType Timer1_Deinit(const Timer1_t *TM1_obj);


#endif	/* TIMER1_H */

