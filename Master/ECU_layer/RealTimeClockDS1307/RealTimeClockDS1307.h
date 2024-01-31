/* 
 * File:   RealTimeClockDS1307.h
 * Author: Ammar Yasser 
 *
 * Created on December 1, 2023, 11:24 PM
 */

#ifndef REALTIMECLOCKDS1307_H
#define	REALTIMECLOCKDS1307_H

#include "../../MCAL_layer/I2C/I2C.h"


typedef struct {
    uint8 _Hours;
    uint8 _Mintes;
    uint8 _Seconds;
    uint8 _Years;
    uint8 _Month;
    uint8 _Days;
}RTC_t;

RTC_t RealTimeClockDS1307_Get_Time_Date(const mssp_i2c_t *i2c_obj );
void RealTimeClockDS1307_Convert_Time(uint8_t *Rtc_Time);
void RealTimeClockDS1307_Convert_Date(uint8_t *Rtc_Time);


#endif	/* REALTIMECLOCKDS1307_H */

