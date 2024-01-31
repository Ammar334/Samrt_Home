
/* 
 * File:   RealTimeClockDS1307.c
 * Author: Ammar Yasser 
 *
 * Created on December 1, 2023, 11:24 PM
 */
#include "RealTimeClockDS1307.h"

static RTC_t rtc ;

RTC_t RealTimeClockDS1307_Get_Time_Date(const mssp_i2c_t *i2c_obj )
{
    Std_ReturnType ret = E_OK;
    if((NULL == i2c_obj)){
        ret = E_NOT_OK;
    }
    else{
        
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,&(rtc._Seconds),0x00,0xD0);
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,&(rtc._Mintes),0x01,0xD0);
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,&(rtc._Hours),0x02,0xD0);
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,&(rtc._Days),0x04,0xD0);
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,&(rtc._Month),0x05,0xD0);
        ret = MSSP_I2C_Master_Read_Register_Blocking(i2c_obj,&(rtc._Years),0x06,0xD0);
    }
    
    return rtc;

}

void RealTimeClockDS1307_Convert_Time(uint8_t *Rtc_Time)
{
     
    Rtc_Time[0] = ((rtc._Hours >> 4) + 0x30);
    Rtc_Time[1] = (rtc._Hours & 0x0F) + 0x30;
    Rtc_Time[2] = ':';
    Rtc_Time[3] = ((rtc._Mintes >> 4) + 0x30);
    Rtc_Time[4] = (rtc._Mintes & 0x0F) + 0x30;
    Rtc_Time[5] = ':';
    Rtc_Time[6] = ((rtc._Seconds >> 4) + 0x30);
    Rtc_Time[7] = (rtc._Seconds & 0x0F) + 0x30;
    Rtc_Time[8] = '\r';
}
void RealTimeClockDS1307_Convert_Date(uint8_t *Rtc_Time)
{
    Rtc_Time[0] = ((rtc._Days >> 4) + 0x30);
    Rtc_Time[1] = (rtc._Days & 0x0F) + 0x30;
    Rtc_Time[2] = '-';
    Rtc_Time[3] = ((rtc._Month >> 4) + 0x30);
    Rtc_Time[4] = (rtc._Month & 0x0F) + 0x30;
    Rtc_Time[5] = '-';
    Rtc_Time[6] = ((rtc._Years >> 4) + 0x30);
    Rtc_Time[7] = (rtc._Years & 0x0F) + 0x30;
    Rtc_Time[8] = '\r';
}