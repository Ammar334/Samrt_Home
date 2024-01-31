/* 
 * File:   ecu_Dc_motor.h
 * Author: ammar.yasser
 *
 * Created on 01 ?????, 2023, 06:56 ?
 */

#ifndef ECU_DC_MOTOR_H
#define	ECU_DC_MOTOR_H

/******Includes**********/
#include "ecu_Dc_mottor_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
/*********Macro Declaration***********/
#define DC_MOTOR_ON      1U
#define DC_MOTOR_OFF     0U
#define DC_MOTOR_PIN_1   0U
#define DC_MOTOR_PIN_2   1U

/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/


typedef struct
{
    pin_config dc_motor_pin[2];
}dc_motor_t;


/*********Function Declaration***********/

Std_ReturnType dc_motor_initialize (const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_right (const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_move_left (const dc_motor_t *dc_motor);
Std_ReturnType dc_motor_stop (const dc_motor_t *dc_motor);








#endif	/* ECU_DC_MOTOR_H */

