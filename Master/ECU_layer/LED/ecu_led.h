/* 
 * File:   ecu_led.h
 * Author: ACC
 *
 * Created on 21 ?????, 2023, 03:27 ?
 */

#ifndef ECU_LED_H
#define	ECU_LED_H

/******Includes**********/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include  "ecu_led_cfg.h"
/*********Macro Declaration***********/

/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/
typedef enum{
    
    LED_OFF,
    LED_ON
    
}LED_statues;

typedef struct{
    uint8 port_name :3;
    uint8 pin_number : 3;
    uint8 pin_statues :1;
    uint8 reserved :1;
}led_t;
        
/*********Function Declaration***********/

Std_ReturnType led_initialize(const led_t *led);
Std_ReturnType led_turn_on(const led_t *led);
Std_ReturnType led_turn_off(const led_t *led);
Std_ReturnType led_toggle(const led_t *led);





#endif	/* ECU_LED_H */

