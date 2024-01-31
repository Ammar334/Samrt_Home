


#include "Servo_motor.h"
 Std_ReturnType SERVO_MotorInit(const Servo_t *Servo_Obj)
 {
    Std_ReturnType ret = E_OK;
    uint16 Angle_value = 0;
    if(Servo_Obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        //min 811 && max 1809
        Angle_value = ((Servo_Obj->servo_start_angle * 1000UL)/180)+811;
        CCP1_Compare_write_value(&(Servo_Obj->Servo_ccp),Angle_value);
        CCP_Init(&(Servo_Obj->Servo_ccp));
        
        
        
    }
    return ret;
 }
 Std_ReturnType SERVO_MotorSetAngle(const Servo_t *Servo_Obj,uint8 Copy_u8Angle)
 {
    Std_ReturnType ret = E_OK;
    uint16 Angle_value = 0;
    if(Servo_Obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
        CCP_Deinit(&(Servo_Obj->Servo_ccp));
        Angle_value = ((Copy_u8Angle * 1000UL)/180)+811;
        CCP1_Compare_write_value(&(Servo_Obj->Servo_ccp),Angle_value);
        CCP_Init(&(Servo_Obj->Servo_ccp));
        
    }
    return ret;
 }