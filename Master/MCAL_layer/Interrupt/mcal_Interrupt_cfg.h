/* 
 * File:   mcal_Interrupt_cfg.h
 * Author: ACC
 *
 * Created on 17 ??????, 2023, 04:34 ?
 */

#ifndef MCAL_INTERRUPT_CFG_H
#define	MCAL_INTERRUPT_CFG_H

/******Includes**********/
#include "pic18f4620.h"
#include "../mcal_std_types.h"
#include "mcal_Interrupt_gen_cfg.h"
#include "../GPIO/hal_gpio.h"

/*********Macro Declaration***********/

#define INTERRUPT_ENABLE            1
#define INTERRUPT_DISABLE           0

#define INTERRUPT_OCCUR             1
#define INTERRUPT_NOT_OCCUR         1

#define INTERRUPT_PRIORTY_ENABLE    1
#define INTERRUPT_PRIORTY_DISABLE   0

/*********Macro Function Declaration***********/

#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
#define INTERRUPT_PRIORTYINTERRUPTEnable()           (RCONbits.IPEN = 1)
#define INTERRUPT_PRIORTYINTERRUPTDisable()          (RCONbits.IPEN = 0)

#define INTERRUPT_GLOBALINTERRUPTHighEnable()        (INTCONbits.GIEH = 1)
#define INTERRUPT_GLOBALINTERRUPTHighDisable()       (INTCONbits.GIEH = 0)

#define INTERRUPT_GLOBALINTERRUPTLowEnable()         (INTCONbits.GIEL = 1)
#define INTERRUPT_GLOBALINTERRUPTLowDisable()        (INTCONbits.GIEL = 0)

#else

#define INTERRUPT_PeripheralINTERRUPTEnable()        (INTCONbits.PEIE = 1)
#define INTERRUPT_PeripheralINTERRUPTDisable()       (INTCONbits.PEIE = 0)

#define INTERRUPT_GlobalINTERRUPTEnable()            (INTCONbits.GIE = 1)
#define INTERRUPT_GlobalINTERRUPTDisable()           (INTCONbits.GIE = 0)

#endif

/*********Data Types Declaration***********/
typedef enum
{
    HIGH_PRIORTY,
    LOW_PRIORTY
            
}Intterupt_priorty_t;
/*********Function Declaration***********/


#endif	/* MCAL_INTERRUPT_CFG_H */

