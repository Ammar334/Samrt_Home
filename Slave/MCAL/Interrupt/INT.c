/* 
 * File    : INT.c
 * Author  : Ammar.Yasser
 * SWC     : INT
 * Version : V1
 * Created on Wensday : 23,8,2023 
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "../../LIB/Bit_math.h"
#include "../../LIB/data_types.h"
#include "INT.h"
#include "../../MCAL/DIO/DIO.h"




static void (*INT_PFCall[3])(void);

void INT_voidEnable (u8 Copy_u8INTIndex,u8 Copy_u8EdgeIndex)
{
	switch(Copy_u8INTIndex)
	{
		case EXT_INT0:
			switch(Copy_u8EdgeIndex)
			{
				case INT_FALING_EDGE:
					CLEAR_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				break;
				case INT_RAISING_EDGE:
					SET_BIT(MCUCR,ISC00);
					SET_BIT(MCUCR,ISC01);
				break;
				case INT_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);
				break;
				case INT_LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC00);
					CLEAR_BIT(MCUCR,ISC01);	
				break;
				default : ;
			}
			SET_BIT(GICR,INT0);
			break;
		case EXT_INT1:
			switch(Copy_u8EdgeIndex)
			{
				case INT_FALING_EDGE:
					CLEAR_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				break;
				case INT_RAISING_EDGE:
					SET_BIT(MCUCR,ISC10);
					SET_BIT(MCUCR,ISC11);
				break;
				case INT_ANY_LOGICAL_CHANGE:
					SET_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);
				break;
				case INT_LOW_LEVEL:
					CLEAR_BIT(MCUCR,ISC10);
					CLEAR_BIT(MCUCR,ISC11);	
				break;
				default : ;
			}
			SET_BIT(GICR,INT1);
			break;
		case EXT_INT2:
			switch(Copy_u8EdgeIndex)
			{
				case INT_FALING_EDGE:
					CLEAR_BIT(MCUCSR,ISC2);
				break;
				case INT_RAISING_EDGE:
					SET_BIT(MCUCSR,ISC2);
				break;
				default : ;
			}
			SET_BIT(GICR,INT2);
			break;
		default : ;
		
		
	}
}
void INT_voidDisable(u8 Copy_u8INTIndex)
{
	switch(Copy_u8INTIndex)
	{
		case EXT_INT0:
			CLEAR_BIT(GICR,INT0);
		break;
		case EXT_INT1:
			CLEAR_BIT(GICR,INT1);
		break;
		case EXT_INT2:
			CLEAR_BIT(GICR,INT2);		
		break;	
		default : ;
	}
}
void INT_voidSetCallBack(u8 Copy_u8INTIndex ,void(*Copy_voidPFunName)(void))
{
	INT_PFCall[Copy_u8INTIndex] = Copy_voidPFunName;
	
}


ISR(INT0_vect)
{
	INT_PFCall[0]();
}

ISR(INT1_vect)
{
	INT_PFCall[1]();
}

ISR(INT2_vect)
{
	INT_PFCall[2]();
}






































