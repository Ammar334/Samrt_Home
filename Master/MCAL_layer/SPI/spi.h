/* 
 * File:   spi.h
 * Author: Ammar Yasser
 *
 * Created on 15/10/2023
 */

#ifndef SPI_H
#define	SPI_H

/******Includes**********/
#include "spi_cfg.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../GPIO/hal_gpio.h"

/*********Macro Declaration***********/

#define SPI_TRANSMIT_ON_ACTIVE_TO_IDLE              1
#define SPI_TRANSMIT_ON_IDLE_TO_ACTIVE              0

#define SPI_MASTER_SAMPLE_AT_END_OF_CLK             1
#define SPI_MASTER_SAMPLE_AT_MIDDLE_OF_CLK          0

#define SPI_IDLE_STATE_HIGH                         1
#define SPI_IDLE_STATE_LOW                          0

#define SPI_MASTER_CLK_TMR2_2                       3
#define SPI_MASTER_CLK_FOSC_64                      2
#define SPI_MASTER_CLK_FOSC_16                      1
#define SPI_MASTER_CLK_FOSC_4                       0

#define SPI_SLAVE_MODE_SS_DISABLED                  5
#define SPI_SLAVE_MODE_SS_ENABLED                   4

#define SPI_WRITE_COLLISION_DETECTED                1

#define SPI_OVER_FLOW_DETECTED                      1


/*********Macro Function Declaration***********/

#define SPI_ENABLE()                            (SSPCON1bits.SSPEN = 1)
#define SPI_DISABLE()                           (SSPCON1bits.SSPEN = 0)

#define SPI_WRITE_COLLISION_STATE()             (SSPCON1bits.WCOL)
#define SPI_WRITE_COLLISION_CLEAR()             (SSPCON1bits.WCOL = 0)

#define SPI_OVER_FLOW_STATE()                   (SSPCON1bits.SSPOV)
#define SPI_OVER_FLOW_CLEAR()                   (SSPCON1bits.SSPOV = 0)

#define SPI_IDLE_STATE_SELECT(_STATE)           (SSPCON1bits.CKP = _STATE)

#define SPI_MODE_SELECT(MODE)                   (SSPCON1bits.SSPM = MODE)

#define SPI_SAMPLE_TIME_SELECT(TIME)            (SSPSTATbits.SMP = TIME)

#define SPI_TRASMITION_TIME_SELECT(TIME)        (SSPSTATbits.CKE = TIME)

#define SPI_RECEVING_STATUS()                   (SSPSTATbits.BF)
#define SPI_INTERRUPT_STATUS()                  (PIR1bits.SSPIF)


/*********Data Types Declaration***********/

typedef struct
{
#if SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    
    void (*spi_CallBack) (void);
    Intterupt_priorty_t Priorty;
    
#endif
    uint8 spi_mode          : 3;
    uint8 spi_CLK_Polarity  : 1;
    uint8 spi_sample_time   : 1;
    uint8 spi_transmit_time : 1;  
    uint8 Reserved          : 2;
}SPI_t;

/*********Function Declaration***********/

Std_ReturnType SPI_Master_Init(const SPI_t *spi_obj);
Std_ReturnType SPI_Slave_Init(const SPI_t *spi_obj);
Std_ReturnType SPI_Deinit(const SPI_t *spi_obj);
Std_ReturnType SPI_WriteBlocking(const SPI_t *spi_obj,uint8 value);
Std_ReturnType SPI_Write_NotBlocking(const SPI_t *spi_obj,uint8 value);
Std_ReturnType SPI_ReadBlocking(const SPI_t *spi_obj,uint8 *value);
Std_ReturnType SPI_Read_NotBlocking(const SPI_t *spi_obj,uint8 *value);
Std_ReturnType SPI_Write_String_Blocking(const SPI_t *spi_obj,uint8 *string);
Std_ReturnType SPI_Write_String_NotBlocking(const SPI_t *spi_obj,uint8 *string);


#endif	/* SPI_H */

