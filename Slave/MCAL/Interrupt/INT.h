/* 
 * File    : INT.c
 * Author  : Ammar.Yasser
 * SWC     : INT
 * Version : V1
 * Created on Wensday : 23,8,2023 
 */
 
 #ifndef INT_H
 #define INT_H
 
 
/*********Macro Declaration***********/

#define EXT_INT0					0
#define EXT_INT1					1	
#define EXT_INT2					2

#define INT_RAISING_EDGE			3
#define INT_FALING_EDGE				2
#define INT_ANY_LOGICAL_CHANGE		1
#define INT_LOW_LEVEL				0
 
 
 /*********Function Declaration***********/

void INT_voidEnable (u8 Copy_u8INTIndex,u8 Copy_u8EdgeIndex);
void INT_voidDisable(u8 Copy_u8INTIndex);
void INT_voidSetCallBack(u8 Copy_u8INTIndex ,void(*Copy_voidPFunName)(void));











 
 #endif
