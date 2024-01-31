/* 
 * File:   mcal_external_Interrupt.h
 * Author: Ammar Yasser
 *
 * Created on 17 Decemper, 2023, 04:27 ?
 */

#ifndef MCAL_EXTERNAL_INTERRUPT_H
#define	MCAL_EXTERNAL_INTERRUPT_H

/******Includes**********/
#include "mcal_Interrupt_cfg.h"
/*********Macro Declaration***********/

/*********Macro Function Declaration***********/

#if EXTERNAL_INTERRUPT_INTx_FEATURE == INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_INT0_ENABLE()             (INTCONbits.INT0IE = 1)
#define INTERRUPT_INT0_DISABLE()            (INTCONbits.INT0IE = 0)

#define INTERRUPT_INT0_CLEAR_FLAG()         (INTCONbits.INT0IF = 0)

#define INTERRUPT_INT0_RISING_EDGE()        (INTCON2bits.INTEDG0 = 1)
#define INTERRUPT_INT0_FALING_EDGE()        (INTCON2bits.INTEDG0 = 0)

#define INTERRUPT_INT1_ENABLE()             (INTCON3bits.INT1IE = 1)
#define INTERRUPT_INT1_DISABLE()            (INTCON3bits.INT1IE = 0)

#define INTERRUPT_INT1_CLEAR_FLAG()         (INTCON3bits.INT1IF = 0)

#define INTERRUPT_INT1_RISING_EDGE()        (INTCON2bits.INTEDG1 = 1)
#define INTERRUPT_INT1_FALING_EDGE()        (INTCON2bits.INTEDG1 = 0)

#define INTERRUPT_INT2_ENABLE()             (INTCON3bits.INT2IE = 1)
#define INTERRUPT_INT2_DISABLE()            (INTCON3bits.INT2IE = 0)

#define INTERRUPT_INT2_CLEAR_FLAG()         (INTCON3bits.INT2IF = 0)

#define INTERRUPT_INT2_RISING_EDGE()        (INTCON2bits.INTEDG2 = 1)
#define INTERRUPT_INT2_FALING_EDGE()        (INTCON2bits.INTEDG2 = 0)

#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_INT1_HIGH_PRIORTY()       (INTCON3bits.INT1IP = 1) 
#define INTERRUPT_INT1_LOW_PRIORTY()        (INTCON3bits.INT1IP = 0)

#define INTERRUPT_INT2_HIGH_PRIORTY()       (INTCON3bits.INT2IP = 1)
#define INTERRUPT_INT2_LOW_PRIORTY()        (INTCON3bits.INT2IP = 0)
#endif

#endif

#if EXTERNAL_INTERRUPT_ONCHANGE_FEATURE == INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_RBx_ENABLE()             (INTCONbits.RBIE = 1)
#define INTERRUPT_RBx_DISABLE()            (INTCONbits.RBIE = 0)

#define INTERRUPT_RBx_CLEAR_FLAG()         (INTCONbits.RBIF = 0)

#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE

#define INTERRUPT_RBx_HIGH_PRIORTY()       (INTCON2bits.RBIP = 1)
#define INTERRUPT_RBx_LOW_PRIORTY()        (INTCON2bits.RBIP = 0)

#endif

#endif

/*********Data Types Declaration***********/

typedef enum
{
    EXT_INT0,
    EXT_INT1,
    EXT_INT2
            
}Intterupt_INTx_Index_t;

typedef enum
{
    RISING_EDGE,
    FALING_EDGE
            
}Intterupt_INTx_Edge_t;

typedef struct 
{ 
    void (*INTx_CallBack)(void);
    pin_config pin;
    Intterupt_INTx_Index_t index;
    Intterupt_INTx_Edge_t edge;
    Intterupt_priorty_t priorty;
    
}Intterupt_INTx_t;

typedef struct 
{
    void (*RBx_CallBack_High)(void);
    void (*RBx_CallBack_Low)(void);
    pin_config pin;
    Intterupt_priorty_t priorty;
 
}Intterupt_RBx_t;

/*********Function Declaration***********/

Std_ReturnType Interrupt_INTx_Init (const Intterupt_INTx_t *int_obj);
Std_ReturnType Interrupt_INTx_DInit(const Intterupt_INTx_t *int_obj);
Std_ReturnType Interrupt_RBx_Init  (const Intterupt_RBx_t *RB_obj);
Std_ReturnType Interrupt_RBx_DInit (const Intterupt_RBx_t *RB_obj);






#endif	/* MCAL_EXTERNAL_INTERRUPT_H */

