
#include "ecu_led.h"

/**
 * @brif initialize the pin to be output and turn off
 * @param led
 * @return statues of the Function
 *         (E_OK) : the function done successfully
 *         (E_NOT_OK) : the function failed
 */
Std_ReturnType led_initialize(const led_t *led)
{
    Std_ReturnType ret = E_OK;
   
    if(led==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = {
            .direction = GPIO_OUTPUT,
            .port      = led->port_name,
            .logic     = led->pin_statues,
            .pin       = led->pin_number
        };
        gpio_pin_initialize(&pin_obj);
        
    }
    return ret;
}

/**
 * @brif turn on the led
 * @param led
 * @return statues of the Function
 *         (E_OK) : the function done successfully
 *         (E_NOT_OK) : the function failed
 */
Std_ReturnType led_turn_on(const led_t *led)
{
    Std_ReturnType ret = E_OK;
   
    if(led==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = {
            .direction = GPIO_OUTPUT,
            .port      = led->port_name,
            .logic     = led->pin_statues,
            .pin       = led->pin_number
        };
        gpio_pin_write_logic(&pin_obj,GPIO_HIGH);
    }
    return ret;

}
/**
 * 
 * @brif turn off the led
 * @param led
 * @return statues of the Function
 *         (E_OK) : the function done successfully
 *         (E_NOT_OK) : the function failed
 */
Std_ReturnType led_turn_off(const led_t *led)
{
    Std_ReturnType ret = E_OK;
    if(led==NULL)
    {
        
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = {
            .direction = GPIO_OUTPUT,
            .port      = led->port_name,
            .logic     = led->pin_statues,
            .pin       = led->pin_number
        };
        gpio_pin_write_logic(&pin_obj,GPIO_LOW);
    }
    return ret;
}

/**
 * @brif toggle the led
 * @param led
 * @return statues of the Function
 *         (E_OK) : the function done successfully
 *         (E_NOT_OK) : the function failed
 */
Std_ReturnType led_toggle(const led_t *led)
{
    Std_ReturnType ret = E_OK;
    
    if(led==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        pin_config pin_obj = {
            .direction = GPIO_OUTPUT,
            .port      = led->port_name,
            .logic     = led->pin_statues,
            .pin       = led->pin_number
        };
        gpio_pin_toggle_logic(&pin_obj);
    }
    return ret;
}