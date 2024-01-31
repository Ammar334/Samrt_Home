/* 
 * File:   TC74_TempSensor.h
 * Author: Ammar Yasser
 *
 * Created on 05 ??????, 2023, 06:14 ?
 */

#include "TC74_TempSensor.h"


Std_ReturnType TC74_Temp_Sensor_Read(const mssp_i2c_t *i2c_obj,uint8 *Temp_vlaue,uint8 TC74_Modle)
{
    Std_ReturnType ret = E_OK;
    if(Temp_vlaue == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,Temp_vlaue,0x00,TC74_Modle);
    }
    return ret;
}