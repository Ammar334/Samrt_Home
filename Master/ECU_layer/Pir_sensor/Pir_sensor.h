/* 
 * File:   Pir_sensor.h
 * Author: Ammar Yasser
 *
 * Created on 04/10/2023
 */

#ifndef PIR_SENSOR_H
#define	PIR_SENSOR_H

/******Includes**********/

#include "Pir_sensor_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"


/*********Macro Declaration***********/

#define PIR_SENSOR_ON               1
#define PIR_SENSOR_OFF              0


/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/

typedef struct
{
    pin_config pin;
    
}PIR_sensor_t;

/*********Function Declaration***********/

Std_ReturnType PIR_sensor_initialize(const PIR_sensor_t *Pir_obj);
Std_ReturnType PIR_sensor_read(const PIR_sensor_t *Pir_obj,uint8 *pir_state );

#endif	/* PIR_SENSOR_H */

