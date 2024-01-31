/* 
 * File:   spi.c
 * Author: Ammar Yasser
 *
 * Created on 15/10/2023
 */

#include "spi.h"

#if SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE

static void (*SPI_CallBack)(void);

#endif

Std_ReturnType SPI_Master_Init(const SPI_t *spi_obj)
{
    Std_ReturnType ret = E_OK;
    pin_config MOSI_pin = {.direction=GPIO_OUTPUT,.logic=GPIO_LOW,.pin = GPIO_PIN5,.port = GPIO_PORT_C};
    pin_config MISO_pin = {.direction=GPIO_INPUT,.logic=GPIO_LOW,.pin = GPIO_PIN4,.port = GPIO_PORT_C};
    pin_config CLK_pin  = {.direction=GPIO_OUTPUT,.logic=GPIO_LOW,.pin = GPIO_PIN3,.port = GPIO_PORT_C};
    pin_config SS_pin   = {.direction=GPIO_OUTPUT,.logic=GPIO_LOW,.pin = GPIO_PIN3,.port = GPIO_PORT_A};

    if(spi_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_DISABLE();
        
        ret = gpio_pin_direction_initialize(&MOSI_pin);
        ret = gpio_pin_direction_initialize(&MISO_pin);
        ret = gpio_pin_direction_initialize(&CLK_pin);
        ret = gpio_pin_direction_initialize(&SS_pin);
        
        SPI_MODE_SELECT(spi_obj->spi_mode);
        SPI_IDLE_STATE_SELECT(spi_obj->spi_CLK_Polarity);    
        SPI_TRASMITION_TIME_SELECT(spi_obj->spi_transmit_time);
        SPI_SAMPLE_TIME_SELECT(spi_obj->spi_sample_time);
        
#if SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        SPI_INTERRUPT_ENABLE();
        SPI_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(spi_obj->Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                SPI_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                SPI_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        SPI_CallBack = spi_obj->spi_CallBack;
#endif 
        
        SPI_ENABLE();            
        
    }   
    return ret;
}

Std_ReturnType SPI_Slave_Init(const SPI_t *spi_obj)
{
    Std_ReturnType ret = E_OK;
    pin_config MOSI_pin = {.direction=GPIO_OUTPUT,.logic=GPIO_LOW,.pin = GPIO_PIN5,.port = GPIO_PORT_C};
    pin_config MISO_pin = {.direction=GPIO_INPUT,.logic=GPIO_LOW,.pin = GPIO_PIN4,.port = GPIO_PORT_C};
    pin_config CLK_pin  = {.direction=GPIO_INPUT,.logic=GPIO_LOW,.pin = GPIO_PIN3,.port = GPIO_PORT_C};
    pin_config SS_pin   = {.direction=GPIO_INPUT,.logic=GPIO_LOW,.pin = GPIO_PIN5,.port = GPIO_PORT_A};
    if(spi_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_DISABLE();
        
        ret = gpio_pin_direction_initialize(&MOSI_pin);
        ret = gpio_pin_direction_initialize(&MISO_pin);
        ret = gpio_pin_direction_initialize(&CLK_pin);
        ret = gpio_pin_direction_initialize(&SS_pin);
        
        SPI_MODE_SELECT(spi_obj->spi_mode);
        SPI_IDLE_STATE_SELECT(spi_obj->spi_CLK_Polarity);    
        SPI_TRASMITION_TIME_SELECT(spi_obj->spi_transmit_time);
        SPI_SAMPLE_TIME_SELECT(0);
        
#if SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        SPI_INTERRUPT_ENABLE();
        SPI_INTERRUPT_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(spi_obj->Priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTHighEnable();
                SPI_INTERRUPT_HIGH_PRIORTY_SET();
                break;
            case LOW_PRIORTY:
                INTERRUPT_GLOBALINTERRUPTLowEnable();
                SPI_INTERRUPT_LOW_PRIORTY_SET();
                break;
            default:
                ret = E_NOT_OK;
        }
#else
        INTERRUPT_GlobalINTERRUPTEnable();
        INTERRUPT_PeripheralINTERRUPTEnable();
#endif
        SPI_CallBack = spi_obj->spi_CallBack;
#endif 
        
        SPI_ENABLE();   
    }   
    return ret;
}


Std_ReturnType SPI_Deinit(const SPI_t *spi_obj)
{
    Std_ReturnType ret = E_OK;
    if(spi_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SPI_DISABLE();
#if SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
        SPI_INTERRUPT_DISABLE();
#endif
        
    }   
    return ret;
}
Std_ReturnType SPI_WriteBlocking(const SPI_t *spi_obj,uint8 value)
{
    Std_ReturnType ret = E_OK;
    uint8 buff_removed = 0;
    if(spi_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        SSPBUF = value;
        while(!(SPI_RECEVING_STATUS()));
        PIR1bits.SSPIF = 0;
        buff_removed = SSPBUF;
                
    }   
    return ret;
}
Std_ReturnType SPI_ReadBlocking(const SPI_t *spi_obj,uint8 *value)
{
    Std_ReturnType ret = E_OK;
    if((spi_obj == NULL)||(value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        while(!(SPI_RECEVING_STATUS()));
        *value = SSPBUF;
        PIR1bits.SSPIF = 0;
    }   
    return ret;
}

Std_ReturnType SPI_Write_NotBlocking(const SPI_t *spi_obj,uint8 value)
{
    Std_ReturnType ret = E_OK;
    if(spi_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((SPI_RECEVING_STATUS()==1) || (SPI_INTERRUPT_STATUS() == 0))
        {
            SSPBUF = value;
            PIR1bits.SSPIF = 0;
        }
        else
        {
            ret = E_NOT_OK;
        }
                
    }   
    return ret;
}

Std_ReturnType SPI_Read_NotBlocking(const SPI_t *spi_obj,uint8 *value)
{
    Std_ReturnType ret = E_OK;
    if((spi_obj == NULL)||(value == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        if((SPI_RECEVING_STATUS()))
        {
            *value = SSPBUF;
            ret = E_OK;
        }
        else
        {
            ret = E_NOT_OK;
        }
        
    }   
    return ret;
}

Std_ReturnType SPI_Write_String_Blocking(const SPI_t *spi_obj,uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint8 l_counter = 0;
    if((spi_obj == NULL)&&(string == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(l_counter = 0;string[l_counter]!='\0';l_counter++)
        {
            ret = SPI_WriteBlocking(spi_obj,string[l_counter]);
        }
                
    }   
    return ret;
}
Std_ReturnType SPI_Write_String_NotBlocking(const SPI_t *spi_obj,uint8 *string)
{
    Std_ReturnType ret = E_OK;
    uint8 l_counter = 0;
    if((spi_obj == NULL)&&(string == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        for(l_counter = 0;string[l_counter]!='\0';l_counter++)
        {
            ret = SPI_Write_NotBlocking(spi_obj,string[l_counter]);
            if(ret == E_NOT_OK)
            {
                l_counter--;
            }
        }
                
    }   
    return ret;
}
void SPI_ISR(void)
{
#if SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE
    SPI_INTERRUPT_CLEAR_FLAG();
    if(SPI_CallBack!=NULL)
    {
        SPI_CallBack();
    }
#endif
}
