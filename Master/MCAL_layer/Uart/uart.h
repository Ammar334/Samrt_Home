/* 
 * File:   uart.h
 * Author: Ammar Yasser
 *
 * Created on 07/10/2023
 */

#ifndef UART_H
#define	UART_H

/******Includes**********/

#include "uart_cfg.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
#include "../GPIO/hal_gpio.h"
#include "../mcal_std_types.h"
#include "pic18f4620.h"

/*********Macro Declaration***********/

#define UART_ASSYNCHRONOUS_MODE                         0
#define UART_SYNCHRONOUS_MODE                           1

#define UART_ASSYNCHRONOUS_HIGH_SPEED                   1
#define UART_ASSYNCHRONOUS_LOW_SPEED                    0

#define UART_16BIT_BAUD_RATE                            1
#define UART_8BIT_BAUD_RATE                             0

#define UART_ASSYNCHRONOUS_TX_9BIT_ENABLE               1
#define UART_ASSYNCHRONOUS_TX_9BIT_DISABLE              0

#define UART_ASSYNCHRONOUS_TX_INTERRUBT_ENABLE          1
#define UART_ASSYNCHRONOUS_TX_INTERRUBT_DISABLE         0

#define UART_ASSYNCHRONOUS_TX_ENABLE                    1
#define UART_ASSYNCHRONOUS_TX_DISABLE                   0

#define UART_ASSYNCHRONOUS_RX_9BIT_ENABLE               1
#define UART_ASSYNCHRONOUS_RX_9BIT_DISABLE              0

#define UART_ASSYNCHRONOUS_RX_INTERRUBT_ENABLE          1
#define UART_ASSYNCHRONOUS_RX_INTERRUBT_DISABLE         0

#define UART_ASSYNCHRONOUS_RX_ENABLE                    1
#define UART_ASSYNCHRONOUS_RX_DISABLE                   0

#define UART_FRAMING_ERROR_DETECTED                     1
#define UART_FRAMING_ERROR_CLEARED                      0

#define UART_OVERRUN_ERROR_DETECTED                     1
#define UART_OVERRUN_ERROR_CLEARED                      0


/*********Macro Function Declaration***********/

#define USART_ENABLE()                                           (RCSTAbits.SPEN = 1)
#define USART_DISABLE()                                          (RCSTAbits.SPEN = 0)

#define USART_SYNCHRONIZATION_SELECT(MODE)                       (TXSTAbits.SYNC = MODE)
#define USART_ASSYNCHRONOUS_BEUDRATE_SPEED_SELECT(SPEED)         (TXSTAbits.BRGH = SPEED)
#define USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(SIZE)       (BAUDCONbits.BRG16 = SIZE)

#define USART_ASSYNCHRONOUS_TX_9BIT_ENABLE()                     (TXSTAbits.TX9 = 1)
#define USART_ASSYNCHRONOUS_TX_9BIT_DISABLE()                    (TXSTAbits.TX9 = 0)
#define USART_ASSYNCHRONOUS_TX_ENABLE()                          (TXSTAbits.TXEN = 1)
#define USART_ASSYNCHRONOUS_TX_DISABLE()                         (TXSTAbits.TXEN = 0)

#define USART_ASSYNCHRONOUS_RX_9BIT_ENABLE()                     (RCSTAbits.RX9 = 1)
#define USART_ASSYNCHRONOUS_RX_9BIT_DISABLE()                    (RCSTAbits.RX9 = 0)
#define USART_ASSYNCHRONOUS_RX_ENABLE()                          (RCSTAbits.CREN = 1)
#define USART_ASSYNCHRONOUS_RX_DISABLE()                         (RCSTAbits.CREN = 0)

#define USART_TSR_REGISTER_STATUS()                              (TXSTAbits.TRMT)
#define USART_RSR_REGISTER_STATUS()                              (PIR1bits.RCIF)





/*********Data Types Declaration***********/

typedef enum 
{
    BUADRATE_ASSYNC_8BIT_LOW_SPEED,
    BUADRATE_ASSYNC_8BIT_HIGH_SPEED,
    BUADRATE_ASSYNC_16BIT_LOW_SPEED,
    BUADRATE_ASSYNC_16BIT_HIGH_SPEED,
    BUADRATE_SYNC_8BIT,
    BUADRATE_SYNC_16BIT,
}Buadrate_t;

typedef struct
{
    uint8 uart_tx_enable            : 1;
    uint8 uart_tx_Interrubt_enable  : 1;
    uint8 uart_tx_9bit_enable       : 1;
    Intterupt_priorty_t Priorty;
}uart_tx_t;

typedef struct
{
    uint8 uart_rx_enable            : 1;
    uint8 uart_rx_Interrubt_enable  : 1;
    uint8 uart_rx_9bit_enable       : 1;
    Intterupt_priorty_t Priorty;
}uart_rx_t;

typedef union
{
    struct{
        uint8 uart_ferr_state            : 1;
        uint8 uart_rerr_state            : 1; 
    };
    uint8  uart_erorr_state;
}uart_erorr_state_t;

typedef struct
{
    uint32              BuadRate;
    Buadrate_t          BuadRate_cfg;
    uart_erorr_state_t  uart_erorr_state;
    uart_rx_t           uart_rx;
    uart_tx_t           uart_tx;
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    
    void (*Uart_TX_CallBack)(void);
    void (*Uart_RX_CallBack)(void);
    void (*Uart_FRAMING_CallBack)(void);
    void (*Uart_OVERRUN_CallBack)(void);
    
#endif
    
}uart_t;



/*********Function Declaration***********/

Std_ReturnType EUART_ASYNC_Init(const uart_t *uart_obj);
Std_ReturnType EUART_ASYNC_DeInit(const uart_t *uart_obj);

Std_ReturnType EUART_ASYNC_Read_value_Blocking(uint8 *value);
Std_ReturnType EUART_ASYNC_Read_value_Non_Blocking(uint8 *value);
Std_ReturnType EUART_ASYNC_RX_Restart(void);

Std_ReturnType EUART_ASYNC_Write_value_Blocking(uint8 value);
Std_ReturnType EUART_ASYNC_Write_String_Blocking(uint8 *string);

Std_ReturnType EUART_ASYNC_Write_value_Non_Blocking(uint8 value);
Std_ReturnType EUART_ASYNC_Write_String_Non_Blocking(uint8 *string);





#endif	/* UART_H */

