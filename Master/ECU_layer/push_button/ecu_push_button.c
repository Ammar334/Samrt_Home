
/* 
 * File:   ecu_push_button.h
 * Author: ACC
 *
 * Created on 28 ?????, 2023, 08:19 ?
 */


#include "ecu_push_button.h"

/**
 * @brief  initialize the button
 * @param btn
 * @return ret statues of the function 
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue
 */
Std_ReturnType push_button_initialize(const button_t *btn)
{
    Std_ReturnType ret = E_OK;
   
    if(btn==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_direction_initialize(&(btn->button_pin));
    }
    return ret;
}
    

/**
 * @brief read the state of the button
 * @param btn
 * @param btn_state
 * @return ret statues of the function 
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue
 */
Std_ReturnType push_button_read(const button_t *btn,button_state_t *btn_state )
{
    Std_ReturnType ret = E_OK;
    
    logic_t btn_l = GPIO_LOW ;
    if((btn==NULL)||(btn_state == NULL))
    {
        ret = E_NOT_OK;
    }
    else
    {
        gpio_pin_read_logic(&(btn->button_pin),&btn_l);
        if(btn->button_connection == BUTTON_ACTIVE_LOW)
        {
            
            if(btn_l==GPIO_LOW)
            {
                *btn_state = BUTTON_PRESSED;
            }
           else if(btn_l==GPIO_HIGH)
            {
                *btn_state = BUTTON_RELESED;
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
        else if(btn->button_connection == BUTTON_ACTIVE_HIGH)
        {
            if(btn_l==GPIO_LOW)
            {
                *btn_state = BUTTON_RELESED;
            }
            else if(btn_l==GPIO_HIGH)
            {
                *btn_state = BUTTON_PRESSED;
            }
            else
            {
                ret = E_NOT_OK;
            }
        }
        else
        {
            ret = E_NOT_OK;
        }
        
    }
    return ret;
}

