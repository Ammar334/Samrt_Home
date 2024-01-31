/* 
 * File:   ecu_seven_segment.h
 * Author: ammar.yasser
 *
 * Created on 05 ?????, 2023, 02:01 ?
 */

#ifndef ECU_SEVEN_SEGMENT_H
#define	ECU_SEVEN_SEGMENT_H

/******Includes**********/
#include "ecu_seven_segment_cfg.h"
#include "../../MCAL_layer/GPIO/hal_gpio.h"
/*********Macro Declaration***********/

#define SEGMENT_PIN0   0
#define SEGMENT_PIN1   1
#define SEGMENT_PIN2   2
#define SEGMENT_PIN3   3


/*********Macro Function Declaration***********/

/*********Data Types Declaration***********/
typedef enum{
    SEGMENT_COMMON_ANODE,
    SEGMENT_COMMON_CATHODE
}segment_type_t;

typedef struct{
    pin_config segment[4];
    segment_type_t segment_type;
}segment_t;

/*********Function Declaration***********/
Std_ReturnType initialize_seven_segment(const segment_t *segment);
Std_ReturnType seven_segment_write_number(const segment_t *segment,uint8 number);


#endif	/* ECU_SEVEN_SEGMENT_H */

