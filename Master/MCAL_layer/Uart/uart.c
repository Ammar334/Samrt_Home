/* 
 * File:   uart.c
 * Author: Ammar Yasser
 *
 * Created on 07/10/2023
 */

#include "uart.h"

#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE

static void (*Uart_TX_CallBack)(void);
static void (*Uart_RX_CallBack)(void);
static void (*Uart_FRAMING_CallBack)(void);
static void (*Uart_OVERRUN_CallBack)(void);

#endif

static Std_ReturnType EUART_Beudrate_Init(const uart_t *uart_obj);
static Std_ReturnType EUART_ASYNC_RX_Init(const uart_t *uart_obj);
static Std_ReturnType EUART_ASYNC_TX_Init(const uart_t *uart_obj);

Std_ReturnType EUART_ASYNC_Init(const uart_t *uart_obj)
{
    Std_ReturnType ret = E_OK;
    pin_config tx_pin = {.direction=GPIO_INPUT,.logic=GPIO_LOW,.pin = GPIO_PIN6,.port = GPIO_PORT_C};
    pin_config rx_pin = {.direction=GPIO_INPUT,.logic=GPIO_LOW,.pin = GPIO_PIN7,.port = GPIO_PORT_C};
    if(uart_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        USART_DISABLE();
        ret = EUART_Beudrate_Init(uart_obj);
        ret = gpio_pin_direction_initialize(&tx_pin);
        ret = gpio_pin_direction_initialize(&rx_pin);
        EUART_ASYNC_TX_Init(uart_obj);
        EUART_ASYNC_RX_Init(uart_obj);       
        USART_ENABLE();
        
    }
    return ret;
}
Std_ReturnType EUART_ASYNC_DeInit(const uart_t *uart_obj)
{
    Std_ReturnType ret = E_OK;
    if(uart_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
    }
    return ret;
}
Std_ReturnType EUART_ASYNC_Read_value_Blocking(uint8 *value)
{
    Std_ReturnType ret = E_OK;
    
    while(!(USART_RSR_REGISTER_STATUS()));    
    *value = RCREG;
    
    return ret;
}
Std_ReturnType EUART_ASYNC_Read_value_Non_Blocking(uint8 *value)
{
    Std_ReturnType ret = E_OK;
    
   if(USART_RSR_REGISTER_STATUS())
   {
       *value = RCREG;
   }
   else
   {
       *value = 0;
       ret = E_NOT_OK;
   }
    
    
    return ret;
}

Std_ReturnType EUART_ASYNC_RX_Restart(void)
{
    Std_ReturnType ret = E_OK;
    
    USART_ASSYNCHRONOUS_RX_DISABLE();
    USART_ASSYNCHRONOUS_RX_ENABLE();
    
    return ret;
}

Std_ReturnType EUART_ASYNC_Write_value_Blocking(uint8 value)
{
    Std_ReturnType ret = E_OK;
        while (!(USART_TSR_REGISTER_STATUS()));
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        EUSART_TX_INTERRUPT_ENABLE();
#endif       
        TXREG = value;
        
    return ret;
}

Std_ReturnType EUART_ASYNC_Write_String_Blocking(uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint16 l_char_Counter = 0;
    
    for(l_char_Counter=0;string[l_char_Counter]!='\0';l_char_Counter++)
    {
        ret = EUART_ASYNC_Write_value_Blocking(string[l_char_Counter]);
    }
    
    
    return ret;
}

Std_ReturnType EUART_ASYNC_Write_value_Non_Blocking(uint8 value)
{
    Std_ReturnType ret = E_OK;
    
   if(USART_TSR_REGISTER_STATUS())
   {
       TXREG = value;
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        EUSART_TX_INTERRUPT_ENABLE();
#endif 
   }
   else
   {
       ret = E_NOT_OK;
   }
    
    
    return ret;
}
Std_ReturnType EUART_ASYNC_Write_String_Non_Blocking(uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint16 l_char_Counter = 0;
    
    for(l_char_Counter=0;string[l_char_Counter]!='\0';l_char_Counter++)
    {
        ret = EUART_ASYNC_Write_value_Non_Blocking(string[l_char_Counter]);
        if(ret == E_NOT_OK)
        {
            l_char_Counter--;
        }
    }
    
    
    return ret;
}

static Std_ReturnType EUART_Beudrate_Init(const uart_t *uart_obj)
{
    Std_ReturnType ret = E_OK;
    float32 Baudrate_temp=0;
    if(uart_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(uart_obj->BuadRate_cfg)
        {
            case BUADRATE_ASSYNC_8BIT_LOW_SPEED:
                USART_SYNCHRONIZATION_SELECT(UART_ASSYNCHRONOUS_MODE);
                USART_ASSYNCHRONOUS_BEUDRATE_SPEED_SELECT(UART_ASSYNCHRONOUS_LOW_SPEED);
                USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(UART_8BIT_BAUD_RATE);
                Baudrate_temp = ((_XTAL_FREQ/uart_obj->BuadRate)/64)-1;
                break;                
            case BUADRATE_ASSYNC_8BIT_HIGH_SPEED:
                USART_SYNCHRONIZATION_SELECT(UART_ASSYNCHRONOUS_MODE);
                USART_ASSYNCHRONOUS_BEUDRATE_SPEED_SELECT(UART_ASSYNCHRONOUS_HIGH_SPEED);
                USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(UART_8BIT_BAUD_RATE);
                Baudrate_temp = ((_XTAL_FREQ/uart_obj->BuadRate)/16)-1;
                break;
            case BUADRATE_ASSYNC_16BIT_LOW_SPEED:
                USART_SYNCHRONIZATION_SELECT(UART_ASSYNCHRONOUS_MODE);
                USART_ASSYNCHRONOUS_BEUDRATE_SPEED_SELECT(UART_ASSYNCHRONOUS_LOW_SPEED);
                USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(UART_16BIT_BAUD_RATE);
                Baudrate_temp = ((_XTAL_FREQ/uart_obj->BuadRate)/16)-1;
                break;    
            case BUADRATE_ASSYNC_16BIT_HIGH_SPEED:
                USART_SYNCHRONIZATION_SELECT(UART_ASSYNCHRONOUS_MODE);
                USART_ASSYNCHRONOUS_BEUDRATE_SPEED_SELECT(UART_ASSYNCHRONOUS_HIGH_SPEED);
                USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(UART_16BIT_BAUD_RATE);
                Baudrate_temp = ((_XTAL_FREQ/uart_obj->BuadRate)/4)-1;
                break;    
            case BUADRATE_SYNC_8BIT:
                USART_SYNCHRONIZATION_SELECT(UART_SYNCHRONOUS_MODE);
                USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(UART_8BIT_BAUD_RATE);
                Baudrate_temp = ((_XTAL_FREQ/uart_obj->BuadRate)/4)-1;
                break;   
            case BUADRATE_SYNC_16BIT:
                USART_SYNCHRONIZATION_SELECT(UART_SYNCHRONOUS_MODE);
                USART_ASSYNCHRONOUS_BEUDRATE_BIT_SIZE_SELECT(UART_16BIT_BAUD_RATE);
                Baudrate_temp = ((_XTAL_FREQ/uart_obj->BuadRate)/4)-1;
                break;  
            default :
                ret  = E_NOT_OK;
        }
        
        SPBRG  = (uint8)((uint32)Baudrate_temp);
        SPBRGH = (uint8)(((uint32)Baudrate_temp)>>8);
    }
    return ret;
}
static Std_ReturnType EUART_ASYNC_TX_Init(const uart_t *uart_obj)
{
    Std_ReturnType ret = E_OK;
    if(uart_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(uart_obj->uart_tx.uart_tx_enable == UART_ASSYNCHRONOUS_TX_ENABLE)
        {
            if(uart_obj->uart_tx.uart_tx_Interrubt_enable == UART_ASSYNCHRONOUS_TX_ENABLE)
            {
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
                EUSART_TX_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORTYINTERRUPTEnable();
                switch(uart_obj->uart_tx.Priorty)
                {
                    case HIGH_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTHighEnable();
                        EUSART_TX_INTERRUPT_HIGH_PRIORTY_SET();
                        break;
                    case LOW_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTLowEnable();
                        EUSART_TX_INTERRUPT_LOW_PRIORTY_SET();
                        break;
                    default:
                        ret = E_NOT_OK;
                }
#else
                INTERRUPT_GlobalINTERRUPTEnable();
                INTERRUPT_PeripheralINTERRUPTEnable();
#endif
                Uart_TX_CallBack = uart_obj->Uart_TX_CallBack;
#endif 

            }
            else if(uart_obj->uart_tx.uart_tx_Interrubt_enable == UART_ASSYNCHRONOUS_TX_DISABLE)
            {
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
                EUSART_TX_INTERRUPT_DISABLE();
#endif
            }
            else
            {
                ret = E_NOT_OK;
            }

            if(uart_obj->uart_tx.uart_tx_9bit_enable == UART_ASSYNCHRONOUS_TX_9BIT_ENABLE)
            {
                USART_ASSYNCHRONOUS_TX_9BIT_ENABLE();
            }
            else if(uart_obj->uart_tx.uart_tx_9bit_enable == UART_ASSYNCHRONOUS_TX_9BIT_DISABLE)
            {
                USART_ASSYNCHRONOUS_TX_9BIT_DISABLE();
            }
            else
            {
                ret = E_NOT_OK;
            }
            USART_ASSYNCHRONOUS_TX_ENABLE();
        }
        else
        {
            USART_ASSYNCHRONOUS_TX_DISABLE();
        }
    }
    return ret;
}

static Std_ReturnType EUART_ASYNC_RX_Init(const uart_t *uart_obj)
{
    Std_ReturnType ret = E_OK;
    if(uart_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if(uart_obj->uart_rx.uart_rx_enable == UART_ASSYNCHRONOUS_RX_ENABLE)
        {
            
            
            if(uart_obj->uart_rx.uart_rx_Interrubt_enable == UART_ASSYNCHRONOUS_RX_ENABLE)
            {
                
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
                EUSART_RX_INTERRUPT_ENABLE();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORTYINTERRUPTEnable();
                switch(uart_obj->uart_rx.Priorty)
                {
                    case HIGH_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTHighEnable();
                        EUSART_RX_INTERRUPT_HIGH_PRIORTY_SET();
                        break;
                    case LOW_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTLowEnable();
                        EUSART_RX_INTERRUPT_LOW_PRIORTY_SET();
                        break;
                    default:
                        ret = E_NOT_OK;
                }
#else
                INTERRUPT_GlobalINTERRUPTEnable();
                INTERRUPT_PeripheralINTERRUPTEnable();
#endif
                Uart_RX_CallBack = uart_obj->Uart_RX_CallBack;
                Uart_FRAMING_CallBack = uart_obj->Uart_FRAMING_CallBack;
                Uart_OVERRUN_CallBack = uart_obj->Uart_OVERRUN_CallBack;
#endif   
            }
            else if(uart_obj->uart_rx.uart_rx_Interrubt_enable == UART_ASSYNCHRONOUS_RX_DISABLE)
            {
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
                EUSART_RX_INTERRUPT_DISABLE();
#endif
            }
            else
            {
                ret = E_NOT_OK;
            }

            if(uart_obj->uart_tx.uart_tx_9bit_enable == UART_ASSYNCHRONOUS_RX_9BIT_ENABLE)
            {
                USART_ASSYNCHRONOUS_RX_9BIT_ENABLE();
            }
            else if(uart_obj->uart_tx.uart_tx_9bit_enable == UART_ASSYNCHRONOUS_RX_9BIT_DISABLE)
            {
                USART_ASSYNCHRONOUS_RX_9BIT_DISABLE();
            }
            else
            {
                ret = E_NOT_OK;
            }
            USART_ASSYNCHRONOUS_RX_ENABLE();
        }
        else
        {
            USART_ASSYNCHRONOUS_RX_DISABLE();
        }
    }
    return ret;
}



void EUSART_TX_ISR (void)
{
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    EUSART_TX_INTERRUPT_DISABLE();
    if(Uart_TX_CallBack != NULL)
    {
        Uart_TX_CallBack();
    }
    else{/*No Thing*/}
#endif
}

void EUSART_RX_ISR (void)
{
#if EUSART_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    if(Uart_RX_CallBack != NULL)
    {
        Uart_RX_CallBack();
    }
    else{/*No Thing*/}
    if(Uart_FRAMING_CallBack != NULL)
    {
        Uart_FRAMING_CallBack();
    }
    else{/*No Thing*/}
    if(Uart_OVERRUN_CallBack != NULL)
    {
        Uart_OVERRUN_CallBack();
    }
    else{/*No Thing*/}
#endif
}

