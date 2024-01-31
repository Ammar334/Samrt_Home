/* 
 * File:   ecu_initialize.h
 * Author: ammar.yasser
 *
 * Created on 06 ?????, 2023, 05:59 ?
 */

#include "ecu_initialize.h"

keypad_t kp1 = {
    .keypad_ROWS_pins[0].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[0].logic = GPIO_LOW,
    .keypad_ROWS_pins[0].pin = GPIO_PIN0,
    .keypad_ROWS_pins[0].port = GPIO_PORT_B,
    .keypad_ROWS_pins[1].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[1].logic = GPIO_LOW,
    .keypad_ROWS_pins[1].pin = GPIO_PIN1,
    .keypad_ROWS_pins[1].port = GPIO_PORT_B,
    .keypad_ROWS_pins[2].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[2].logic = GPIO_LOW,
    .keypad_ROWS_pins[2].pin = GPIO_PIN2,
    .keypad_ROWS_pins[2].port = GPIO_PORT_B,
    .keypad_ROWS_pins[3].direction = GPIO_OUTPUT,
    .keypad_ROWS_pins[3].logic = GPIO_LOW,
    .keypad_ROWS_pins[3].pin = GPIO_PIN3,
    .keypad_ROWS_pins[3].port = GPIO_PORT_B,
    .keypad_coulmns_pins[0].direction = GPIO_INPUT,
    .keypad_coulmns_pins[0].logic = GPIO_LOW,
    .keypad_coulmns_pins[0].pin = GPIO_PIN4,
    .keypad_coulmns_pins[0].port = GPIO_PORT_B,
    .keypad_coulmns_pins[1].direction = GPIO_INPUT,
    .keypad_coulmns_pins[1].logic = GPIO_LOW,
    .keypad_coulmns_pins[1].pin = GPIO_PIN5,
    .keypad_coulmns_pins[1].port = GPIO_PORT_B,
    .keypad_coulmns_pins[2].direction = GPIO_INPUT,
    .keypad_coulmns_pins[2].logic = GPIO_LOW,
    .keypad_coulmns_pins[2].pin = GPIO_PIN6,
    .keypad_coulmns_pins[2].port = GPIO_PORT_B,
};

lcd_4bit_t lcd_1 = {
    .lcd_rs.direction = GPIO_OUTPUT,
    .lcd_rs.logic = GPIO_LOW,
    .lcd_rs.pin = GPIO_PIN0,
    .lcd_rs.port = GPIO_PORT_C,
    .lcd_enable.direction = GPIO_OUTPUT,
    .lcd_enable.logic = GPIO_LOW,
    .lcd_enable.pin = GPIO_PIN1,
    .lcd_enable.port = GPIO_PORT_C,
    .lcd_data[0].direction = GPIO_OUTPUT,
    .lcd_data[0].logic = GPIO_LOW,
    .lcd_data[0].pin = GPIO_PIN4,
    .lcd_data[0].port = GPIO_PORT_D,
    .lcd_data[1].direction = GPIO_OUTPUT,
    .lcd_data[1].logic = GPIO_LOW,
    .lcd_data[1].pin = GPIO_PIN5,
    .lcd_data[1].port = GPIO_PORT_D,
    .lcd_data[2].direction = GPIO_OUTPUT,
    .lcd_data[2].logic = GPIO_LOW,
    .lcd_data[2].pin = GPIO_PIN6,
    .lcd_data[2].port = GPIO_PORT_D,
    .lcd_data[3].direction = GPIO_OUTPUT,
    .lcd_data[3].logic = GPIO_LOW,
    .lcd_data[3].pin = GPIO_PIN7,
    .lcd_data[3].port = GPIO_PORT_D
    
};

dc_motor_t motor_1 = {
  
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN2,
    .dc_motor_pin[0].port = GPIO_PORT_C,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN3,
    .dc_motor_pin[1].port = GPIO_PORT_C,
    
};

dc_motor_t motor_2 = {
  
    .dc_motor_pin[0].direction = GPIO_OUTPUT,
    .dc_motor_pin[0].logic = GPIO_LOW,
    .dc_motor_pin[0].pin = GPIO_PIN4,
    .dc_motor_pin[0].port = GPIO_PORT_C,
    .dc_motor_pin[1].direction = GPIO_OUTPUT,
    .dc_motor_pin[1].logic = GPIO_LOW,
    .dc_motor_pin[1].pin = GPIO_PIN5,
    .dc_motor_pin[1].port = GPIO_PORT_C,
    
};

button_t btn_1 = {
    .button_connection = BUTTON_ACTIVE_HIGH,
    .button_pin.direction = GPIO_INPUT,
    .button_pin.logic = GPIO_LOW,
    .button_pin.pin = GPIO_PIN0,
    .button_pin.port=GPIO_PORT_B,
    .button_st = BUTTON_RELESED
};
segment_t seg_1={
    .segment[0].direction = GPIO_OUTPUT,
    .segment[0].logic = GPIO_LOW,
    .segment[0].pin = GPIO_PIN0,
    .segment[0].port = GPIO_PORT_D,
    .segment[1].direction = GPIO_OUTPUT,
    .segment[1].logic = GPIO_LOW,
    .segment[1].pin = GPIO_PIN1,
    .segment[1].port = GPIO_PORT_D,
    .segment[2].direction = GPIO_OUTPUT,
    .segment[2].logic = GPIO_LOW,
    .segment[2].pin = GPIO_PIN2,
    .segment[2].port = GPIO_PORT_D,
    .segment[3].direction = GPIO_OUTPUT,
    .segment[3].logic = GPIO_LOW,
    .segment[3].pin = GPIO_PIN3,
    .segment[3].port = GPIO_PORT_D,
    .segment_type = SEGMENT_COMMON_CATHODE
};
segment_t seg_2={
    .segment[0].direction = GPIO_OUTPUT,
    .segment[0].logic = GPIO_LOW,
    .segment[0].pin = GPIO_PIN1,
    .segment[0].port = GPIO_PORT_A,
    .segment[1].direction = GPIO_OUTPUT,
    .segment[1].logic = GPIO_LOW,
    .segment[1].pin = GPIO_PIN5,
    .segment[1].port = GPIO_PORT_A,
    .segment[2].direction = GPIO_OUTPUT,
    .segment[2].logic = GPIO_LOW,
    .segment[2].pin = GPIO_PIN6,
    .segment[2].port = GPIO_PORT_A,
    .segment[3].direction = GPIO_OUTPUT,
    .segment[3].logic = GPIO_LOW,
    .segment[3].pin = GPIO_PIN2,
    .segment[3].port = GPIO_PORT_A,
    .segment_type = SEGMENT_COMMON_CATHODE
};

led_t led1 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN2, .pin_statues = GPIO_LOW};
led_t led2 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN3, .pin_statues = GPIO_LOW};
led_t led3 = {.port_name = GPIO_PORT_B, .pin_number = GPIO_PIN2, .pin_statues = GPIO_LOW};
led_t led4 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN5, .pin_statues = GPIO_LOW};
led_t led5 = {.port_name = GPIO_PORT_A, .pin_number = GPIO_PIN6, .pin_statues = GPIO_LOW};
led_t led6 = {.port_name = GPIO_PORT_B, .pin_number = GPIO_PIN1, .pin_statues = GPIO_LOW};


void ecu_initialize (void)
{
    Std_ReturnType ret = E_NOT_OK;
    ret = lcd_4bit_initialize(&lcd_1);
    ret = keypad_initialize(&kp1);
    ret = initialize_seven_segment(&seg_1);
    ret = initialize_seven_segment(&seg_2);

}