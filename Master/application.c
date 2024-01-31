/* 
 * File:   application.c
 * Author: Ammar Yasser
 * Created on November 28, 2023, 8:43 PM
 */

#include "application.h"

Std_ReturnType ret = E_NOT_OK;

uint8 value =0;
uint8 Pass_string[20] = {0};
uint32 pass=0;
uint8 i=0;
sint8 tries =3;
uint8 tries_string[5] = {0};
uint8 eeprom_data = 0;
uint8 flag = 0;
uint8 chose=0;
uint8 chose_value = 0;
uint16 Temp = 0;
uint8 temp_string[10] = {0};
uint8 EUART_ENABLE = 0;
uint8 counter_String[1] = {0};
uint8 counter = 0;
uint8 num = 0;
uint8 oven_on=0;

int main() { 
    
    
    application_initialize();
    ret = EEPROM_Readdata(1,&EUART_ENABLE);
    while(1){    
        ret = ADC_GetConversion_Blocking(&ADC_temp,ADC_CHANNEL0,&Temp);
        Temp = Temp * 4.8828125f;
        Temp /= 10;
        ret = EEPROM_Readdata( 0,&eeprom_data);
        if(eeprom_data!=0xFF)//Check if the pass is set
		{
            if(flag==0)
			{
                ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Enter Password :");
                if(EUART_ENABLE == 1)
                {
                    ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                }
                else 
                {
                    ret = keypad_get_value(&kp1,&value);
                }
                
            }
            if((value == '=')||(flag > 0))
            {
                pass = atoi(Pass_string);
                ret = EEPROM_Readdata( 0,&eeprom_data);
                if((pass == eeprom_data)||(flag > 0))
                {
                    if(flag == 0)
                    {
                        ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                        __delay_ms(50);
                        ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Welcome");
                        
                        __delay_ms(1000);
                        tries = 3;
                        flag = 1;
                        ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                    }
                    else
                    {
                        if(flag == 1)
                        {
                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Heating System");
                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Remote Control");
                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Garage    4-Rooms");
                            ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"5-Microwave   6-Exit");
                            if(EUART_ENABLE == 1)
                            {
                                ret = EUART_ASYNC_Read_value_Non_Blocking(&chose);
                            }
                            else 
                            {
                                ret = keypad_get_value(&kp1,&chose);
                            }
                        }
                        if(oven_on == 4)
                        {
                            ret = SPI_WriteBlocking(&spi1_obj,'A');
                            oven_on = 0;
                        }
                        else
                        {
                            ret = SPI_WriteBlocking(&spi1_obj,chose); 
                        }
                        switch(chose)
                        {
                            case '1':
                                if(flag == 1)
                                {
                                    flag = 2;
                                }
                                if(flag == 2)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    flag = 3;
                                }
                                if(flag == 3)
                                {
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Temperature : ");
                                    ret = convert_short_to_string(Temp,temp_string);
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,15,temp_string);
                                    ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"1-Air Conditioner");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"2-Heater");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"3-Auto Mode");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,15,"4-Back");
                                    if(EUART_ENABLE == 1)
                                    {
                                        ret = EUART_ASYNC_Read_value_Non_Blocking(&chose_value);
                                    }
                                    else 
                                    {
                                        ret = keypad_get_value(&kp1,&chose_value);
                                    }
                                }
                                
                                switch(chose_value)
                                {
                                    case '1':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Temperature : ");
                                            ret = convert_short_to_string(Temp,temp_string);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,15,temp_string);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"1-Turn on");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"2-Turn off");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"3-Back");
                                            if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                            if(value == '1')
                                            {
                                                ret = gpio_pin_write_logic(&Air_cond,GPIO_HIGH);
                                                ret = gpio_pin_write_logic(&Heater,GPIO_LOW);
                                            }
                                            else if(value == '2')
                                            {
                                                ret = gpio_pin_write_logic(&Air_cond,GPIO_LOW);
                                            }
                                            else if(value == '3')
                                            {
                                                flag = 2;
                                                chose_value = 0;
                                            }
                                            
                                        }
                                        break;
                                    case '2':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Temperature : ");
                                            ret = convert_short_to_string(Temp,temp_string);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,15,temp_string);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"1-Turn on");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"2-Turn off");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"3-Back");
                                            if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                            if(value == '1')
                                            {
                                                ret = gpio_pin_write_logic(&Heater,GPIO_HIGH);
                                                ret = gpio_pin_write_logic(&Air_cond,GPIO_LOW);
                                            }
                                            else if(value == '2')
                                            {
                                                ret = gpio_pin_write_logic(&Heater,GPIO_LOW);
                                            }
                                            else if(value == '3')
                                            {
                                                flag = 2;
                                                chose_value = 0;
                                            }
                                        }
                                        break;
                                    case '3':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Temperature : ");
                                            ret = convert_short_to_string(Temp,temp_string);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,15,temp_string);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"1-Back");
                                            if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                            if(Temp >= 38)
                                            {
                                                ret = gpio_pin_write_logic(&Air_cond,GPIO_HIGH);
                                                ret = gpio_pin_write_logic(&Heater,GPIO_LOW);
                                            }
                                            else if(Temp <= 15)
                                            {
                                                ret = gpio_pin_write_logic(&Heater,GPIO_HIGH);
                                                ret = gpio_pin_write_logic(&Air_cond,GPIO_LOW);
                                            }
                                            else
                                            {
                                                ret = gpio_pin_write_logic(&Heater,GPIO_LOW);
                                                ret = gpio_pin_write_logic(&Air_cond,GPIO_LOW);
                                            }
                                            if(value == '1')
                                            {
                                                flag = 2;
                                                chose_value = 0;
                                            }
                                        }
                                        break;
                                    case '4':
                                        flag =1;
                                        chose = 0;
                                        break;
                                    default :
                                        if(chose_value != 0)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Invalid Choice");
                                            __delay_ms(800);
                                        }
                                }
                                
                                break;
                            case '2':
                                if(flag == 1)
                                {
                                    flag = 2;
                                }
                                if(flag == 2)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    flag = 3;
                                }
                                if(flag == 3)
                                {
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Enable Remote");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Disable Remote");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"3-Back");
                                    if(EUART_ENABLE == 1)
                                    {
                                        ret = EUART_ASYNC_Read_value_Non_Blocking(&chose_value);
                                    }
                                    else 
                                    {
                                        ret = keypad_get_value(&kp1,&chose_value);
                                    }
                                    ret = EEPROM_Writedata(1,EUART_ENABLE);
                                    switch(chose_value)
                                    {
                                        case '1':
                                            EUART_ENABLE = 1;
                                            break;
                                        case '2':
                                            EUART_ENABLE = 0;
                                            break;
                                        case '3':
                                            flag =1;
                                            chose = 0;
                                            break;
                                        default:
                                            if(chose_value != 0)
                                            {
                                                ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                                ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Invalid Choice");
                                                __delay_ms(800);
                                            }
                                            break;
                                    }
                                            
                                }
                                break;
                            case '3':
                                if(flag == 1)
                                {
                                    flag = 2;
                                }
                                if(flag == 2)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    flag = 3;
                                }
                                if(flag == 3)
                                {
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Garage Light");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Garage Door");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"3-Back");
                                    if(EUART_ENABLE == 1)
                                    {
                                        ret = EUART_ASYNC_Read_value_Non_Blocking(&chose_value);
                                    }
                                    else 
                                    {
                                        ret = keypad_get_value(&kp1,&chose_value);
                                    }
                                }
                                ret = SPI_WriteBlocking(&spi1_obj,chose_value);
                                switch(chose_value)
                                {
                                    case '1':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Turn on light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Turn off light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Back");
                                           if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                                
                                            if(value == '3')
                                            {
                                                flag = 2;
                                            }
                                            ret = SPI_WriteBlocking(&spi1_obj,value);
                                        }
                                        break;
                                    case '2':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Open Door");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Close Door");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Back");
                                           if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                                
                                            if(value == '3')
                                            {
                                                flag = 2;
                                            }
                                            ret = SPI_WriteBlocking(&spi1_obj,value);
                                        }
                                        break;
                                    case '3':
                                        flag = 1;
                                        chose = 0;
                                        break;
                                    default:
                                        if(chose_value != 0)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Invalid Choice");
                                            __delay_ms(800);
                                        }
                                        break;
                                }
                                break;
                            case '4':
                                if(flag == 1)
                                {
                                    flag = 2;
                                }
                                if(flag == 2)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    flag = 3;
                                }
                                if(flag == 3)
                                {
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Room 1");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Room 2");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Room 3");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"4-Room 4");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,13,"5-Back");
                                    if(EUART_ENABLE == 1)
                                    {
                                        ret = EUART_ASYNC_Read_value_Non_Blocking(&chose_value);
                                    }
                                    else 
                                    {
                                        ret = keypad_get_value(&kp1,&chose_value);
                                    }
                                }
                                ret = SPI_WriteBlocking(&spi1_obj,chose_value);
                                switch(chose_value)
                                {
                                    case '1':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Turn on light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Turn off light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Back");
                                           if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                                
                                            if(value == '3')
                                            {
                                                flag = 2;
                                            }
                                            ret = SPI_WriteBlocking(&spi1_obj,value);
                                        }
                                        break;
                                    case '2':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Turn on light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Turn off light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Back");
                                            if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }                
                                            if(value == '3')
                                            {
                                                flag = 2;
                                            }
                                            ret = SPI_WriteBlocking(&spi1_obj,value);
                                        }
                                        break;
                                    case '3':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Turn on light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Turn off light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Back");
                                            if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }                     
                                            if(value == '3')
                                            {
                                                flag = 2;
                                            }
                                            ret = SPI_WriteBlocking(&spi1_obj,value);
                                        }
                                        break;
                                    case '4':
                                        if(flag == 3)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            flag = 4;
                                        }
                                        if(flag == 4)
                                        {
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Turn on light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Turn off light");
                                            ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Back");
                                            if(EUART_ENABLE == 1)
                                            {
                                                ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                            }
                                            else 
                                            {
                                                ret = keypad_get_value(&kp1,&value);
                                            }
                                            
                                            if(value == '3')
                                            {
                                                flag = 2;
                                            }
                                                ret = SPI_WriteBlocking(&spi1_obj,value);
                                            }
                                        break;
                                    case '5':
                                        flag = 1;
                                        chose = 0;
                                        break;
                                    default :
                                        if(chose_value != 0)
                                        {
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Invalid Choice");
                                            __delay_ms(800);
                                        }  
                                        break;
                                    }

                                break;
                            case '5':
                                if(flag == 1)
                                {
                                    flag = 2;
                                }
                                if(flag == 2)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    flag = 3;
                                }
                                if(flag == 3)
                                {
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"1-Set Timer");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,2,1,"2-Start Cocking");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,3,1,"3-Stop Cocking");
                                    ret = lcd_4bit_send_string_pos(&lcd_1,4,1,"4-Back");
                                    if(EUART_ENABLE == 1)
                                    {
                                        ret = EUART_ASYNC_Read_value_Non_Blocking(&chose_value);
                                    }
                                    else 
                                    {
                                        ret = keypad_get_value(&kp1,&chose_value);
                                    }
                                }
                                ret = SPI_WriteBlocking(&spi1_obj,chose_value);
                                if(chose_value == '1')
                                {
                                    if(flag == 3)
                                    {
                                        flag = 4;
                                        ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                        ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Please set Time");
                                    }
                                    if(flag == 4)
                                    {
                                                    
                                        if(EUART_ENABLE == 1)
                                        {
                                            ret = EUART_ASYNC_Read_value_Non_Blocking(&value);
                                        }
                                        else 
                                        {
                                            ret = keypad_get_value(&kp1,&value);
                                        }
                                        if(value == '=')
                                        {
                                            flag = 3;
                                            ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                            counter = 0;
                                                    
                                        }
                                        else if(value != 0)
                                        {
                                            counter_String[0] = value;
                                            if((counter == 0))
                                            {
                                                num = atoi(counter_String);
                                                ret = seven_segment_write_number(&seg_1,num);
                                                counter++;
                                                counter1 = num;
                                            }
                                            else if((counter == 1))
                                            {
                                                num = atoi(counter_String);
                                                ret = seven_segment_write_number(&seg_2,num);
                                                counter = 0;
                                                counter2 = num;
                                            }
                                        }
                                    }
                                }
                                else if(chose_value == '2')
                                {
                                    ret = Timer0_init(&tm0);
                                    oven_on = 1;
                                }
                                else if(chose_value == '3')
                                {
                                    ret = Timer0_Deinit(&tm0);
                                    oven_on = 0;
                                    flg = 0;
                                }
                                else if(chose_value == '4')
                                {
                                    flag = 1;
                                }
                                else if(chose_value != 0)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Invalid Choice");
                                    __delay_ms(800);
                                }
                                break;
                            case '6':
                                ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                flag = 0;
                                chose = 0;
                                break;
                            default :
                                if(chose != 0)
                                {
                                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                                    ret = lcd_4bit_send_string_pos(&lcd_1,1,7,"Invalid Choice");
                                    __delay_ms(800);
                                }
                        }
                    }
                    
                }
                else
                {
                    tries--;
                    if(tries < 0)
                    {
                        ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                        ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"No More Tries");
                        ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"System Shut down");
                        __delay_ms(1000);
                        ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                        break;
                    }
                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                    ret = lcd_4bit_send_string_pos(&lcd_1,1,4,"Wrong pass");
                    ret = convert_byte_to_string(tries,tries_string);
                    ret = lcd_4bit_send_string_pos(&lcd_1,2,3,tries_string);
                    ret = lcd_4bit_send_string_pos(&lcd_1,2,4,"Tries Left");
                    __delay_ms(1000);
                    ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                }
                i=0;
                memset(Pass_string,'\0',20);
            }else if(value == 'c')
            {
                ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
                i=0;
                memset(Pass_string,'\0',20);
            }
            else if(value != 0)
            {
                lcd_4bit_send_char_pos(&lcd_1,2,(i+1),value);
                Pass_string[i] = value;
                __delay_ms(300);
                lcd_4bit_send_char_pos(&lcd_1,2,(i+1),'*');
                i++;
            }
        }
        else 
        {
            ret = lcd_4bit_send_string_pos(&lcd_1,1,1,"Set Password :");
            ret = keypad_get_value(&kp1,&value);
            if(value == '=')
			{
				i=0;
				pass = atoi (Pass_string);
				ret = EEPROM_Writedata(0,pass);
				ret = lcd_4bit_send_command(&lcd_1,LCD_CLEAR_DISPLAY);
				memset(Pass_string,'\0',20);
			}
			else if(value != 0)
			{
				lcd_4bit_send_char_pos(&lcd_1,2,(i+1),value);
                Pass_string[i] = value;
                __delay_ms(300);
                lcd_4bit_send_char_pos(&lcd_1,2,(i+1),'*');
                i++;
			}
        }
        if(oven_on == 1)
        {
            ret = Timer0_init(&tm0);
            oven_on = 2;
        }
        else if((oven_on == 2)&&(flg == 1))
        {
            ret = seven_segment_write_number(&seg_1,counter1);
            ret = seven_segment_write_number(&seg_2,counter2);
            flg = 0;
        }
        else if(flg == 2)
        {
            oven_on = 4;
            ret = Timer0_Deinit(&tm0);
            flg = 0;
        }
    }
    return (EXIT_SUCCESS);
}

void application_initialize(void){
    Std_ReturnType ret = E_NOT_OK;
    ecu_initialize();
    Mcal_initialize();
}
