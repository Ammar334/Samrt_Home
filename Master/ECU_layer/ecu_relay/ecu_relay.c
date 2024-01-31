/* 
 * File:   ecu_relay.h
 * Author: Ammar.yasser
 *
 * Created on 31 ?????, 2023, 11:17 ?
 */

#include "ecu_relay.h"
/**
 * @brief initialize the relay 
 * @param relay
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType relay_initialize (const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    pin_config relay_pin = {.direction = GPIO_OUTPUT,
                            .pin = relay->pin,
                            .port = relay->port,
                            .logic = relay->relay_st };
    if((relay==NULL)||(relay->port >= PORT_MAX_NUMPER))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&relay_pin);
    }
    return ret;
}
/**
 * @brief turn on the relay 
 * @param relay
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType relay_turn_on(const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    pin_config relay_pin = {.direction = GPIO_OUTPUT,
                            .pin = relay->pin,
                            .port = relay->port,
                            .logic = relay->relay_st };
    if((relay==NULL)||(relay->port >= PORT_MAX_NUMPER))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&relay_pin,GPIO_HIGH);
    }
    return ret;
}
/**
 * @brief turn off the relay
 * @param relay
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType relay_turn_off (const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    pin_config relay_pin = {.direction = GPIO_OUTPUT,
                            .pin = relay->pin,
                            .port = relay->port,
                            .logic = relay->relay_st };
    if((relay==NULL)||(relay->port >= PORT_MAX_NUMPER))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&relay_pin,GPIO_LOW);
    }
    return ret;
}

/**
 * @brief toggle the relay
 * @param relay
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue
 */
Std_ReturnType relay_toggle (const relay_t *relay)
{
    Std_ReturnType ret = E_OK;
    pin_config relay_pin = {.direction = GPIO_OUTPUT,
                            .pin = relay->pin,
                            .port = relay->port,
                            .logic = relay->relay_st };
    if((relay==NULL)||(relay->port >= PORT_MAX_NUMPER))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_toggle_logic(&relay_pin);
    }
    return ret;
}