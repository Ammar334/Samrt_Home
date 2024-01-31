/* 
 * File:   ecu_seven_segment.h
 * Author: ammar.yasser
 *
 * Created on 05 ?????, 2023, 02:01 ?
 */


#include "ecu_seven_segment.h"

/**
 * @brief initialize the seven segment
 * @param segment
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType initialize_seven_segment(const segment_t *segment)
{
    Std_ReturnType ret = E_OK;
    if(segment==NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&(segment->segment[SEGMENT_PIN0]));
        ret = gpio_pin_initialize(&(segment->segment[SEGMENT_PIN1]));
        ret = gpio_pin_initialize(&(segment->segment[SEGMENT_PIN2]));
        ret = gpio_pin_initialize(&(segment->segment[SEGMENT_PIN3]));

    }
    return ret;
}

/**
 * @brief write a number on the seven segment
 * @param segment
 * @param number
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType seven_segment_write_number(const segment_t *segment,uint8 number)
{
    Std_ReturnType ret = E_OK;
    if((segment==NULL)&&(number>9))
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_write_logic(&(segment->segment[SEGMENT_PIN0]),(number & 0x01));
        ret = gpio_pin_write_logic(&(segment->segment[SEGMENT_PIN1]),((number >>1)& 0x01));
        ret = gpio_pin_write_logic(&(segment->segment[SEGMENT_PIN2]),((number >>2) & 0x01));
        ret = gpio_pin_write_logic(&(segment->segment[SEGMENT_PIN3]),((number >>3) & 0x01));


    }
    return ret;
}


