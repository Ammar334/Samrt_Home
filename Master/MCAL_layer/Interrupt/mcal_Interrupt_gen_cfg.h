/* 
 * File:   mcal_Interrupt_gen_cfg.h
 * Author: ACC
 *
 * Created on 17 ??????, 2023, 05:32 ?
 */

#ifndef MCAL_INTERRUPT_GEN_CFG_H
#define	MCAL_INTERRUPT_GEN_CFG_H

/******Includes*********************/

/*********Macro Declaration***********/

#define INTERRUPT_FEATURE_ENABLE         1
#define INTERRUPT_FEATURE_DISABLE        0

#define INTERRUPT_PRIORTY_LEVEL               INTERRUPT_FEATURE_DISABLE

#define EXTERNAL_INTERRUPT_INTx_FEATURE       INTERRUPT_FEATURE_ENABLE
#define EXTERNAL_INTERRUPT_ONCHANGE_FEATURE   INTERRUPT_FEATURE_ENABLE
#define ADC_INTERRUPT_FEATURE                 INTERRUPT_FEATURE_ENABLE
#define TIMER0_INTERRUPT_FEATURE              INTERRUPT_FEATURE_ENABLE
#define TIMER1_INTERRUPT_FEATURE              INTERRUPT_FEATURE_ENABLE
#define TIMER2_INTERRUPT_FEATURE              INTERRUPT_FEATURE_ENABLE
#define TIMER3_INTERRUPT_FEATURE              INTERRUPT_FEATURE_ENABLE
#define CCP1_INTERRUPT_FEATURE                INTERRUPT_FEATURE_ENABLE
#define CCP2_INTERRUPT_FEATURE                INTERRUPT_FEATURE_ENABLE
#define EUSART_INTERRUPT_FEATURE              INTERRUPT_FEATURE_ENABLE
#define SPI_INTERRUPT_FEATURE                 INTERRUPT_FEATURE_DISABLE
#define I2C_INTERRUPT_FEATURE                 INTERRUPT_FEATURE_ENABLE










/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

/*********Function Declaration***********/

#endif	/* MCAL_INTERRUPT_GEN_CFG_H */

