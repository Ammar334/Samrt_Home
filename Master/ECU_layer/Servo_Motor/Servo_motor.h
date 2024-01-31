/* 
 * File:   Servo_motor.h
 * Author: ACC
 *
 * Created on 12 ??????, 2023, 02:21 ?
 */

#ifndef SERVO_MOTOR_H
#define	SERVO_MOTOR_H

#include "Servo_motor.h"
#include "../../MCAL_layer/CCP/CCP1.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"


typedef struct {
    
    CCP_t Servo_ccp;
    uint8 servo_start_angle;
}Servo_t; 


 Std_ReturnType SERVO_MotorInit(const Servo_t *Servo_Obj);
 Std_ReturnType SERVO_MotorSetAngle(const Servo_t *Servo_Obj,uint8 Copy_u8Angle);

#endif	/* SERVO_MOTOR_H */

