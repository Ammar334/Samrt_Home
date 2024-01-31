/* 
 * File:   Timer3.h
 * Author: Ammar Yasser
 *
 * Created on 28/9/2023
 */

#ifndef TIMER3_H
#define	TIMER3_H

/*************Includes***************/
#include "Timer3_cfg.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"


/*********Macro Declaration***********/

#define TIMER3_8BIT_READ_WRITE_REG_SIZE                     0
#define TIMER3_16BIT_READ_WRITE_REG_SIZE                    1

#define TIMER3_SYNCHRONIZE                                  0
#define TIMER3_ASSYNCHRONIZE                                1

#define TIMER3_TIMER_MODE                                   0
#define TIMER3_COUNTER_MODE                                 1

#define TIMER3_prescaler_Div_1                              0
#define TIMER3_prescaler_Div_2                              1
#define TIMER3_prescaler_Div_4                              2
#define TIMER3_prescaler_Div_8                              3


/*********Macro Function Declaration***********/

#define TIMER3_READ_WRITE_REG_SIZE_SELECT(SIZE)             (T3CONbits.RD16 = SIZE)


#define TIMER3_PRESCALER_SELECT(PRESCALER)                  (T3CONbits.T3CKPS = PRESCALER)

#define TIMER3_COUNTER_MODE_SYNC_SELECT(SYNC)               (T3CONbits.T3SYNC = SYNC)

#define TIMER3_MODE_SELECT(MODE)                            (T3CONbits.TMR3CS = MODE)

#define TIMER3_ENABLE()                                     (T3CONbits.TMR3ON = 1)
#define TIMER3_DISABLE()                                    (T3CONbits.TMR3ON = 0)
/*********Data Types Declaration***********/

typedef struct
{
#if TIMER3_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    void (*Timer3CallBack)(void);
    Intterupt_priorty_t Priorty;
#endif
    uint16  Timer3_preload_value;
    uint8  prescaler_value              : 2;
    uint8  Timer3_MODE                  : 1;
    uint8  Timer3_wr_register_size      : 1;
    uint8  Timer3_Counter_Mode_SYNC     : 1;
    uint8  Reserved                     : 3;
}Timer3_t;



/*********Function Declaration***********/

Std_ReturnType Timer3_init(const Timer3_t *TM3_obj);
Std_ReturnType Timer3_Write_Value(const Timer3_t *TM3_obj,uint16 value);
Std_ReturnType Timer3_Read_Value(const Timer3_t *TM3_obj,uint16 *value);
Std_ReturnType Timer3_Deinit(const Timer3_t *TM3_obj);


#endif	/* TIMER3_H */

