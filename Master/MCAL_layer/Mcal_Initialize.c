/* 
 * File:   Mcal_Initialize.h
 * Author: AMMAR Yasser
 *
 * Created on 03/10/2023
 */


#include "Mcal_Initialize.h"
Std_ReturnType ret = E_NOT_OK;
void rbx_int_High(void);
void rbx_int_Low(void);
void timer0_interrubt (void);

uint8 counter1 = 0;
uint8 counter2 = 0;
uint8 flg = 0;
TIMER0_t tm0 = {
    .Timer0CallBack = timer0_interrubt,
    .Timer0_MODE = TIMER0_TIMER_MODE,
    .Timer0_register_size = TIMER0_16BIT_SIZE,
    .prescaler_Enable = TIMER0_PRESCALER_ENABLE_CFG,
    .prescaler_value = TIMER0_prescaler_Div_16,
    .timer0_preload_value = 3036
};

pin_config alarm ={
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW,
    .pin = GPIO_PIN0,
    .port = GPIO_PORT_E
};

pin_config Air_cond ={
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW,
    .pin = GPIO_PIN1,
    .port = GPIO_PORT_E
};

pin_config Heater ={
    .direction = GPIO_OUTPUT,
    .logic = GPIO_LOW,
    .pin = GPIO_PIN2,
    .port = GPIO_PORT_E
};



Intterupt_RBx_t fire_Alarm = {
    .RBx_CallBack_High = rbx_int_High,
    .RBx_CallBack_Low = rbx_int_Low,
    .pin.direction = GPIO_INPUT,
    .pin.pin = GPIO_PIN7,
    .pin.port = GPIO_PORT_B
};

SPI_t spi1_obj = 
{
    .spi_CLK_Polarity = SPI_IDLE_STATE_LOW,
    .spi_mode = SPI_MASTER_CLK_FOSC_64,
    .spi_sample_time = SPI_MASTER_SAMPLE_AT_MIDDLE_OF_CLK,
    .spi_transmit_time = SPI_TRANSMIT_ON_IDLE_TO_ACTIVE
};

ADC_t ADC_temp = {
    .ADC_CallBack = NULL,
    .ADC_Channel = ADC_CHANNEL0,
    .Acquisition_Time = ADC_16TAD,
    .Prescaler = ADC_16FOSC,
    .Result_format = ADC_RIGHT_ADJUST,
    .voltage_refrence = ADC_INTERNAL_VREF
};

uart_t bluetooth = {
    .BuadRate = 9600,
    .BuadRate_cfg = BUADRATE_ASSYNC_8BIT_LOW_SPEED,
    .uart_rx.uart_rx_9bit_enable = UART_ASSYNCHRONOUS_RX_9BIT_DISABLE,
    .uart_rx.uart_rx_enable = UART_ASSYNCHRONOUS_RX_ENABLE,
    .uart_rx.uart_rx_Interrubt_enable = UART_ASSYNCHRONOUS_RX_INTERRUBT_DISABLE,
    .uart_tx.uart_tx_9bit_enable = UART_ASSYNCHRONOUS_TX_9BIT_DISABLE,
    .uart_tx.uart_tx_Interrubt_enable = UART_ASSYNCHRONOUS_TX_INTERRUBT_DISABLE,
    .uart_tx.uart_tx_enable = UART_ASSYNCHRONOUS_TX_ENABLE
};


void Mcal_initialize (void)
{
    
    ret = SPI_Master_Init(&spi1_obj);
    ret = gpio_pin_direction_initialize(&alarm);
    ret = Interrupt_RBx_Init(&fire_Alarm);
    ret = ADC_init(&ADC_temp); 
    ret = EUART_ASYNC_Init(&bluetooth);
    ret = gpio_pin_initialize(&Air_cond);
    ret = gpio_pin_initialize(&Heater);

    
}

void rbx_int_High(void)
{
    ret = gpio_pin_write_logic(&alarm,GPIO_HIGH);
}

void rbx_int_Low(void)
{
    ret = gpio_pin_write_logic(&alarm,GPIO_LOW);
}

void timer0_interrubt (void)
{
    if(counter1 == 0)
    {
        counter1 = 9;
        flg = 1;
        if(counter2 != 0)
        {
            counter2--;
        }
        else
        {
            flg = 2;
        }
    }
    else
    {
        flg = 1;
        counter1--;
    }
}