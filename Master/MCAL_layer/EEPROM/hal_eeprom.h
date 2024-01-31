/* 
 * File:   mcal_eeprom.h
 * Author: Ammar yasser
 *
 * Created on 20/9/2023
 */

#ifndef MCAL_EEPROM_H
#define	MCAL_EEPROM_H

/******Includes**********/
#include "../mcal_std_types.h"
#include "pic18f4620.h"
#include "../Interrupt/mcal_internal_Interrupt.h"
/*********Macro Declaration***********/

#define ACCESS_FLASH_MEMORY         1
#define ACCESS_EEPROM_MEMORY        0

#define ACCESS_Configuration_BITS                               1
#define ACCESS_FLASH_OR_EEPROM_MEMORY                           0

#define ALLOWS_WRITE_CYCLES_FLASH_OR_EEPROM_MEMORY              1
#define INHIBiTS_WRITE_CYCLES_FLASH_OR_EEPROM_MEMORY            0   

#define INITIATES_DATA_EEPROM_WRITE_ERASE                       1   
#define DATA_EEPROM_WRITE_ERASE_COMPLETED                       0   

#define INITIATES_DATA_EEPROM_READ_ERASE                        1   
#define DATA_EEPROM_READ_ERASE_COMPLETED                        0  

/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

/*********Function Declaration***********/
Std_ReturnType EEPROM_Writedata(uint16 address,uint8 Data);
Std_ReturnType EEPROM_Readdata(uint16 address,uint8 *Data);


#endif	/* MCAL_EEPROM_H */

