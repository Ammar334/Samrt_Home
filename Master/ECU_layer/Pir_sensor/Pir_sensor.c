/* 
 * File:   Pir_sensor.c
 * Author: Ammar Yasser
 *
 * Created on 04/10/2023
 */

#include "Pir_sensor.h"

Std_ReturnType PIR_sensor_initialize(const PIR_sensor_t *Pir_obj)
{
    Std_ReturnType ret = E_OK;
    if(Pir_obj==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&(Pir_obj->pin));
    }
    return ret;
}
Std_ReturnType PIR_sensor_read(const PIR_sensor_t *Pir_obj,uint8 *pir_state )
{
    Std_ReturnType ret = E_OK;
    logic_t log = GPIO_LOW;  
    if((Pir_obj==NULL)||(pir_state==NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_read_logic(&(Pir_obj->pin),&log);
        if(log == GPIO_HIGH)
        {
            *pir_state = PIR_SENSOR_ON;
        }
        else if(log == GPIO_LOW)
        {
            *pir_state = PIR_SENSOR_OFF;
        }
        else
        {
            ret = E_NOT_OK;
        }
    }
    return ret;
}
