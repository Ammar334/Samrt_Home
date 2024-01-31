/* 
 * File:   ecu_relay.h
 * Author: Ammar.yasser
 *
 * Created on 31 ?????, 2023, 11:17 ?
 */

#ifndef ECU_RELAY_H
#define	ECU_RELAY_H

/******Includes**********/
#include "ecu_relay_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
/*********Macro Declaration***********/
#define RELAY_ON    1U
#define RElAY_OFF   0U
/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

typedef struct{
    uint8 port : 3;
    uint8 pin  : 3;
    uint8 relay_st : 1;
    uint8 reserved : 1;
}relay_t;

/*********Function Declaration***********/
Std_ReturnType relay_initialize (const relay_t *relay);
Std_ReturnType relay_turn_on(const relay_t *relay);
Std_ReturnType relay_turn_off (const relay_t *relay);
Std_ReturnType relay_toggle (const relay_t *relay);



#endif	/* ECU_RELAY_H */

