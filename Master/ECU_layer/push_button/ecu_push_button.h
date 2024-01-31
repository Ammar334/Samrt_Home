/* 
 * File:   ecu_push_button.h
 * Author: ACC
 *
 * Created on 28 ?????, 2023, 08:19 ?
 */

#ifndef ECU_PUSH_BUTTON_H
#define	ECU_PUSH_BUTTON_H

/******Includes**********/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_push_button_cfg.h"
/*********Macro Declaration***********/

/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

typedef enum{
    BUTTON_PRESSED,
    BUTTON_RELESED
}button_state_t;

typedef enum{
    BUTTON_ACTIVE_LOW,
    BUTTON_ACTIVE_HIGH
}button_active;

typedef struct{
    pin_config button_pin;
    button_state_t button_st;
    button_active button_connection;
}button_t;
        
/*********Function Declaration***********/

Std_ReturnType push_button_initialize(const button_t *btn);
Std_ReturnType push_button_read(const button_t *btn,button_state_t *btn_state );






#endif	/* ECU_PUSH_BUTTON_H */

