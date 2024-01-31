/*
 * Slave_Main.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ACC
 */

#include <avr/io.h>
#include <stdio.h>
#include "MCAL/DIO/DIO.h"
#include <util/delay.h>
#include "HAL/LCD/LCD.h"
#include <string.h>
#include <avr/interrupt.h>
#include "MCAL/ADC/ADC.h"
#include "MCAL/SPI/SPI.h"
#include "HAL/EEPROM/EEPROM.h"
#include "MCAL/I2C/I2C.h"
#include "LIB/Bit_math.h"
#include "LIB/data_types.h"
#include "HAL/KEYPAD/KEYPAD.h"
#include "HAL/DC_Motor/DC_Motor.h"
#include "MCAL/Timers/Timer1/TIMER1.h"
#include "HAL/Ultra_Sonic/Ultra_Sonic.h"

u8 mode = 0;
u8 mode_f = 0;
u8 room = 0;
u8 garage_Flag = 0;
u8 switch_flag = 0;
u16 distance = 0;
int main(void)
{
	SPI_voidInit();
	DC_Motor_voidInit();
	UltraSonic_voidInit();
	Timer1_voidInit(TIMER1_NORMAL_MODE,TIMER1_SCALER_8,TIMER1_OC1A_DISCONNECTED,TIMER1_OC1B_DISCONNECTED);
	sei();
	LCD_8BitvoidInit();
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN2,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN3,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN3,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN4,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN5,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTA,DIO_PIN6,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN0,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
	DIO_voidSetPinDirection(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
	DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN6,DIO_HIGH);
	while(1)
	{

		mode = SPI_u8Tranceive(0xff);
		switch(mode)
		{
			case 'A':
				DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN5,DIO_LOW);
				DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN3,DIO_LOW);
				DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN6,DIO_HIGH);
				break;
			case '3':
				room = SPI_u8Tranceive(0xff);
				switch(room)
				{
					case '1':
						mode_f = SPI_u8Tranceive(0xff);
						switch(mode_f)
						{
							case '1':
								DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN4,DIO_HIGH);
								break;
							case '2':
								DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN4,DIO_LOW);
								break;
						}
						break;
					case '2':
						mode_f = SPI_u8Tranceive(0xff);
						switch(mode_f)
						{
							case '1':
								garage_Flag = 1;
								DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN2,DIO_HIGH);
								DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN3,DIO_LOW);
								DC_Motor_voidMoveRight();
								_delay_ms(1000);
								DC_Motor_voidStop();
								break;
							case '2':
								garage_Flag = 0;
								DC_Motor_voidMoveLeft();
								_delay_ms(1000);
								DC_Motor_voidStop();
								DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN2,DIO_LOW);
								DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
								break;
						}
						break;
					default:

						break;
				}
				break;
			case '4':
				room = SPI_u8Tranceive(0xff);
				switch(room)
				{
					case '1':
						mode_f = SPI_u8Tranceive(0xff);
						switch(mode_f)
						{
							case '1':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN0,DIO_HIGH);
								break;
							case '2':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN0,DIO_LOW);
								break;
						}
						break;
					case '2':
						mode_f = SPI_u8Tranceive(0xff);
						switch(mode_f)
						{
							case '1':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN1,DIO_HIGH);
								break;
							case '2':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN1,DIO_LOW);
								break;
						}
						break;
					case '3':
						mode_f = SPI_u8Tranceive(0xff);
						switch(mode_f)
						{
							case '1':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN2,DIO_HIGH);
								break;
							case '2':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN2,DIO_LOW);
								break;
						}
						break;
					case '4':
						mode_f = SPI_u8Tranceive(0xff);
						switch(mode_f)
						{
							case '1':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN3,DIO_HIGH);
								break;
							case '2':
								DIO_voidSetPinvalue(DIO_PORTB,DIO_PIN3,DIO_LOW);
								break;
						}
						break;
				}
				break;
			case '5':
				room = SPI_u8Tranceive(0xff);
				switch(room)
				{
					case'2':
						DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN5,DIO_HIGH);
						DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN3,DIO_HIGH);
						DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN6,DIO_LOW);
						break;
					case '3':
						mode_f = SPI_u8Tranceive(0xff);
						DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN5,DIO_LOW);
						DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN3,DIO_LOW);
						DIO_voidSetPinvalue(DIO_PORTA,DIO_PIN6,DIO_HIGH);
						break;
				}
				break;

		}
		if(garage_Flag == 1)
		{
			distance = UltraSonic_u16ReadValue(ULTRASONIC_TIMER1_PRESCALER_8);
			LCD_voidSendStringPos("Distance = ",1,1);
			LCD_voidSendNumberPos(distance,1,12);
			if(distance > 20)
			{
				if(switch_flag != 1)
				{
					LCD_voidSendCommand(LCD_CLEAR_DISBLAY);
				}

				LCD_voidSendStringPos("Move Backward",2,1);
				switch_flag = 1;
			}
			else if ((distance <= 20)&&(distance > 15))
			{
				if(switch_flag != 2)
				{
					LCD_voidSendCommand(LCD_CLEAR_DISBLAY);
				}
				LCD_voidSendStringPos("Stop",1,7);
				garage_Flag = 0;
				DC_Motor_voidMoveLeft();
				_delay_ms(1000);
				DC_Motor_voidStop();
				LCD_voidSendCommand(LCD_CLEAR_DISBLAY);
				LCD_voidSendStringPos("Parking Done",1,1);
				DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN2,DIO_LOW);
				DIO_voidSetPinvalue(DIO_PORTD,DIO_PIN3,DIO_HIGH);
				switch_flag = 2;
			}
			else
			{
				if(switch_flag != 3)
				{
					LCD_voidSendCommand(LCD_CLEAR_DISBLAY);
				}
				LCD_voidSendStringPos("Move Forward",2,1);
				switch_flag = 3;
			}
		}
	}

	return 0;
}



