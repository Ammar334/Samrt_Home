/*
 * Ultra_Sonic.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: ACC
 */

#include "Ultra_Sonic.h"
static void icu_callBack(void);
static volatile u16 high =0;

static void icu_callBack(void)
{
	static u8 f = 0;
	static u16 a = 0;
	static u16 b = 0;
	if(f==0)
	{
		a = Timer1_u16ReadICR1Value();
		Timer1_voidICUSetTriggerEdge(ICU_FALLING_EDGE);
		f=1;
	}
	else if(f==1)
	{
		b = Timer1_u16ReadICR1Value();
		Timer1_voidICUSetTriggerEdge(ICU_RISING_EDGE);
		f=0;
		high = b - a;
	}

}


void UltraSonic_voidInit(void)
{
	DIO_voidSetPinDirection(DIO_PORTD,DIO_PIN6,DIO_INPUT);
	DIO_voidSetPinDirection(TRIGGER_PORT,TRIGGER_PIN,DIO_OUTPUT);
	Timer1_voidICUSetCallBack(icu_callBack);
	Timer1_voidICUSetTriggerEdge(ICU_RISING_EDGE);
	Timer1_voidICUInterruptEnable();
}
u16 UltraSonic_u16ReadValue(u8 Timer1_prescaler)
{
	u16 distance = 0;
	DIO_voidSetPinvalue(TRIGGER_PORT,TRIGGER_PIN,DIO_HIGH);
	_delay_us(10);
	DIO_voidSetPinvalue(TRIGGER_PORT,TRIGGER_PIN,DIO_LOW);
	_delay_ms(5);

	distance=((Timer1_prescaler*high*34600UL)/(F_CPU*2)) ;

	return distance;
}
