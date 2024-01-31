/* 
 * File:   TC74_TempSensor.h
 * Author: Ammar Yasser
 *
 * Created on 05 ??????, 2023, 06:14 ?
 */

#ifndef TC74_TEMPSENSOR_H
#define	TC74_TEMPSENSOR_H

/******Includes**********/
#include "../../MCAL_layer/I2C/I2C.h"
/*********Macro Declaration***********/

#define TC74_A0_Modle                       0x90
#define TC74_A1_Modle                       0x92
#define TC74_A2_Modle                       0x94
#define TC74_A3_Modle                       0x96
#define TC74_A4_Modle                       0x98
#define TC74_A5_Modle                       0x9A
#define TC74_A6_Modle                       0x9C
#define TC74_A7_Modle                       0x9E


/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

/*********Function Declaration***********/
Std_ReturnType TC74_Temp_Sensor_Read(const mssp_i2c_t *i2c_obj,uint8 *Temp_vlaue,uint8 TC74_Modle);

#endif	/* TC74_TEMPSENSOR_H */

