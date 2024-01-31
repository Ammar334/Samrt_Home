

#include "DC_Motor.h"


void DC_Motor_voidInit(void)
{
	DIO_voidSetPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_OUTPUT);
	DIO_voidSetPinDirection(DC_MOTOR_PORT,DC_MOTOR_PIN2,DIO_OUTPUT);
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_LOW);
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN2,DIO_LOW);
}
void DC_Motor_voidMoveRight(void)
{
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_HIGH);
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN2,DIO_LOW);
}
void DC_Motor_voidMoveLeft(void)
{
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_LOW);
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN2,DIO_HIGH);
}
void DC_Motor_voidStop(void)
{
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN1,DIO_LOW);
	DIO_voidSetPinvalue(DC_MOTOR_PORT,DC_MOTOR_PIN2,DIO_LOW);
}
