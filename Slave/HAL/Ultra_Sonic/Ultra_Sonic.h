/*
 * Ultra_Sonic.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: ACC
 */

#ifndef ULTRA_SONIC_H_
#define ULTRA_SONIC_H_

#include "../../MCAL/Timers/Timer1/TIMER1.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/data_types.h"
#include "../../LIB/Bit_math.h"
#include "util/delay.h"

#define TRIGGER_PORT		DIO_PORTD
#define TRIGGER_PIN			DIO_PIN1

#define ULTRASONIC_TIMER1_PRESCALER_1				1
#define ULTRASONIC_TIMER1_PRESCALER_8				8
#define ULTRASONIC_TIMER1_PRESCALER_64				64
#define ULTRASONIC_TIMER1_PRESCALER_256				256
#define ULTRASONIC_TIMER1_PRESCALER_1024			1024

void UltraSonic_voidInit(void);
u16 UltraSonic_u16ReadValue(u8 Timer1_prescaler);


#endif /* ULTRA_SONIC_H_ */
