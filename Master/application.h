/* 
 * File:   applications.h
 * Author: Ammar.Yasser
 *
 * Created on 21 ?????, 2023, 06:18 ?
 */

#ifndef APPLICATIONS_H
#define	APPLICATIONS_H


/******Includes**********/
#include "ECU_layer/ecu_initialize.h"
#include "MCAL_layer/Mcal_Initialize.h"


/*********Macro Declaration***********/

/*********Macro Function Declaration***********/
/*********Data Types Declaration***********/
extern lcd_4bit_t lcd_1; 
extern keypad_t kp1;
extern segment_t seg_1;
extern segment_t seg_2;
extern pin_config alarm;
extern ADC_t ADC_temp;
extern uart_t bluetooth;
extern pin_config Air_cond;
extern pin_config Heater;
extern SPI_t spi1_obj;
extern uint8 counter1;
extern uint8 counter2;
extern uint8 flg;
extern TIMER0_t tm0;


        
/*********Function Declaration***********/
void application_initialize (void);
void ecu_initialize (void);
void Mcal_initialize(void);

#endif	/* APPLICATIONS_H */

