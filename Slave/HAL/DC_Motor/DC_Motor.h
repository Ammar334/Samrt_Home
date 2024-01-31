/*
 * DC_Motor.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ACC
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

#include "../../LIB/Bit_math.h"
#include "../../LIB/data_types.h"
#include "../../MCAL/DIO/DIO.h"

#define DC_MOTOR_PORT			DIO_PORTD
#define DC_MOTOR_PIN1			DIO_PIN4
#define DC_MOTOR_PIN2			DIO_PIN7


void DC_Motor_voidInit(void);
void DC_Motor_voidMoveRight(void);
void DC_Motor_voidMoveLeft(void);
void DC_Motor_voidStop(void);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
