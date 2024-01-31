/* 
 * File:   ecu_Dc_motor.h
 * Author: ammar.yasser
 *
 * Created on 01 ?????, 2023, 06:56 ?
 */

#include "ecu_Dc_motor.h"
/**
 * @brief initialize the Dc motor
 * @param dc_motor
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */




Std_ReturnType dc_motor_initialize (const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
                
        ret = gpio_pin_initialize(&(dc_motor->dc_motor_pin[0]));
        ret = gpio_pin_initialize(&(dc_motor->dc_motor_pin[1]));
    }
    return ret;
}

/**
 * @brief dc_motor move in the right direction
 * @param dc_motor
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType dc_motor_move_right (const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),GPIO_HIGH);
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_LOW);
    }
    return ret;
}

/**
 * @brief dc_motor move in the left direction
 * @param dc_motor
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType dc_motor_move_left (const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
       
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_HIGH);
    }
    return ret;
}

/**
 * @brief stop the motor
 * @param dc_motor
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */


Std_ReturnType dc_motor_stop (const dc_motor_t *dc_motor)
{
    Std_ReturnType ret = E_OK;
    if(dc_motor == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
       
        
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[0]),GPIO_LOW);
        ret = gpio_pin_write_logic(&(dc_motor->dc_motor_pin[1]),GPIO_LOW);
    }
    return ret;
}


