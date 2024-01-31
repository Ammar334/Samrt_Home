/* 
 * File:   mcal_Interrupt_manger.h
 * Author: Ammar Yasser
 *
 * Created on 17 Decemper, 2023, 04:27 ?
 */

#ifndef MCAL_INTERRUPT_MANGER_H
#define	MCAL_INTERRUPT_MANGER_H

/******Includes**********/
#include "mcal_Interrupt_cfg.h"
/*********Macro Declaration***********/

/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

/*********Function Declaration***********/
void INT0_ISR (void);
void INT1_ISR (void);
void INT2_ISR (void);
void RB4_ISR  (uint8 RB4_source);
void RB5_ISR  (uint8 RB5_source);
void RB6_ISR  (uint8 RB6_source);
void RB7_ISR  (uint8 RB7_source);
void ADC_ISR  (void);
void TIMER0_ISR (void);
void TIMER1_ISR (void);
void TIMER2_ISR (void);
void TIMER3_ISR (void);
void CCP1_ISR (void);
void CCP2_ISR (void);
void EUSART_TX_ISR (void);
void EUSART_RX_ISR (void);
void SPI_ISR(void);
void I2C_ISR(void);
void I2C_Bus_Collision_ISR(void);


#endif	/* MCAL_INTERRUPT_MANGER_H */

