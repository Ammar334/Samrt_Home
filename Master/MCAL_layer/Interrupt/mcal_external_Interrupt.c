/* 
 * File:   mcal_external_Interrupt.c
 * Author: Ammar Yasser
 *
 * Created on 17 Decemper, 2023, 04:27 ?
 */

#include "mcal_external_Interrupt.h"

static void (*INTx_Call_Back[3]) (void) = {NULL};
static void (*RBx_Call_Back[8]) (void) = {NULL};

static Std_ReturnType Interrupt_INTx_Enable(const Intterupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Disable(const Intterupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Priorty_init(const Intterupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Edge_init(const Intterupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Pin_init(const Intterupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Clear_flag(const Intterupt_INTx_t *int_obj);
static Std_ReturnType Interrupt_INTx_Call_Back(const Intterupt_INTx_t *int_obj);

static Std_ReturnType Interrupt_RBx_Enable(const Intterupt_RBx_t *RB_obj);
static Std_ReturnType Interrupt_RBx_Priorty_init(const Intterupt_RBx_t *RB_obj);
static Std_ReturnType Interrupt_RBx_Call_Back(const Intterupt_RBx_t *RB_obj);

/**
 * @brief  Initialize the interrupt INTx
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType Interrupt_INTx_Init (const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {   
        
        ret = Interrupt_INTx_Disable(int_obj);
        ret = Interrupt_INTx_Clear_flag(int_obj);
        ret = Interrupt_INTx_Edge_init(int_obj);
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        ret = Interrupt_INTx_Priorty_init(int_obj);
#endif  
        ret = Interrupt_INTx_Pin_init(int_obj);
        ret = Interrupt_INTx_Call_Back(int_obj);
        ret = Interrupt_INTx_Enable(int_obj);
    }
    return ret;
}

void INT0_ISR (void)
{
    //Clear flag
    INTERRUPT_INT0_CLEAR_FLAG();
    //Code from mcal you want to do
    
    // call back function
    if(INTx_Call_Back[0] != NULL)
    {
        INTx_Call_Back[0]();
    } 
}

void INT1_ISR (void)
{
    //Clear flag
    INTERRUPT_INT1_CLEAR_FLAG();
    //Code from mcal you want to do
    
    // call back function
    if(INTx_Call_Back[1] != NULL)
    {
        INTx_Call_Back[1]();
    } 
}

void INT2_ISR (void)
{
    //Clear flag
    INTERRUPT_INT2_CLEAR_FLAG();
    //Code from mcal you want to do
    
    // call back function
    if(INTx_Call_Back[2] != NULL)
    {
        INTx_Call_Back[2]();
    } 
}

/**
 *  @brief  deInitialize the interrupt INTx
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType Interrupt_INTx_DInit(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = Interrupt_INTx_Disable(int_obj);    
    }
    return ret;
    
}
/**
 * @brief  Initialize the interrupt RBx
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType Interrupt_RBx_Init  (const Intterupt_RBx_t *RB_obj)
{
    Std_ReturnType ret = E_OK;
    if(RB_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INTERRUPT_RBx_DISABLE();
        INTERRUPT_RBx_CLEAR_FLAG();
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        ret = Interrupt_RBx_Priorty_init(RB_obj);
#endif  
        ret = gpio_pin_initialize(&(RB_obj->pin));
        ret = Interrupt_RBx_Call_Back(RB_obj);
        ret = Interrupt_RBx_Enable(RB_obj);
                
    }
    return ret;
}

void RB4_ISR(uint8 RB4_source)
{
    INTERRUPT_RBx_CLEAR_FLAG();
    if(RB4_source == 0)
    {
        if( RBx_Call_Back[0] != NULL)
        {
            RBx_Call_Back[0]();
        }
    }
    else if(RB4_source == 1)
    {
        if( RBx_Call_Back[1] != NULL)
        {
            RBx_Call_Back[1]();
        }
    }
    
}

void RB5_ISR(uint8 RB5_source)
{
    INTERRUPT_RBx_CLEAR_FLAG();
    if(RB5_source == 0)
    {
        if( RBx_Call_Back[2] != NULL)
        {
            RBx_Call_Back[2]();
        }
    }
    else if(RB5_source == 1)
    {
        if( RBx_Call_Back[3] != NULL)
        {
            RBx_Call_Back[3]();
        }
    }
    
}

void RB6_ISR(uint8 RB6_source)
{
    INTERRUPT_RBx_CLEAR_FLAG();
    if(RB6_source == 0)
    {
        if( RBx_Call_Back[4] != NULL)
        {
            RBx_Call_Back[4]();
        }
    }
    else if(RB6_source == 1)
    {
        if( RBx_Call_Back[5] != NULL)
        {
            RBx_Call_Back[5]();
        }
    }
    
}

void RB7_ISR(uint8 RB7_source)
{
    INTERRUPT_RBx_CLEAR_FLAG();
    if(RB7_source == 0)
    {
        if( RBx_Call_Back[6] != NULL)
        {
            RBx_Call_Back[6]();
        }
    }
    else if(RB7_source == 1)
    {
        if( RBx_Call_Back[7] != NULL)
        {
            RBx_Call_Back[7]();
        }
    }
    
}

/**
 * @brief deInitialize the interrupt RBx
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
Std_ReturnType Interrupt_RBx_DInit (const Intterupt_RBx_t *RB_obj)
{
    Std_ReturnType ret = E_OK;
    if(RB_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        INTERRUPT_RBx_DISABLE();
    }
    return ret;
}

/**
 * @brief  enable the interrupt 
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_INTx_Enable(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->index)
        {
            case EXT_INT0:
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
               INTERRUPT_PRIORTYINTERRUPTEnable();
               INTERRUPT_GLOBALINTERRUPTHighEnable();
#else
                INTERRUPT_PeripheralINTERRUPTEnable();
                INTERRUPT_GlobalINTERRUPTEnable();
#endif
                INTERRUPT_INT0_ENABLE();
                break;
            case EXT_INT1:
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORTYINTERRUPTEnable();
                switch(int_obj->priorty)
                {
                    case HIGH_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTHighEnable();
                        break;
                    case LOW_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTLowEnable();
                        break;
                    default :
                         ret = E_NOT_OK;
                        break;
                } 
#else
                INTERRUPT_PeripheralINTERRUPTEnable();
                INTERRUPT_GlobalINTERRUPTEnable();
#endif
                INTERRUPT_INT1_ENABLE();     
                break;
            case EXT_INT2:
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
                INTERRUPT_PRIORTYINTERRUPTEnable();
                switch(int_obj->priorty)
                {
                    case HIGH_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTHighEnable();
                        break;
                    case LOW_PRIORTY:
                        INTERRUPT_GLOBALINTERRUPTLowEnable();
                        break;
                    default :
                         ret = E_NOT_OK;
                        break;
                } 
#else
                INTERRUPT_PeripheralINTERRUPTEnable();
                INTERRUPT_GlobalINTERRUPTEnable();
#endif
                INTERRUPT_INT2_ENABLE();  
                break;
            default :
                ret = E_NOT_OK;
                break;
        }
                
    }
    return ret;
}
/**
 * @brief  enable the interrupt 
 * @param  int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_INTx_Disable(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->index)
        {
            case EXT_INT0:
                INTERRUPT_INT0_DISABLE();
                
                break;
            case EXT_INT1:
                INTERRUPT_INT1_DISABLE();     
                break;
            case EXT_INT2:
                INTERRUPT_INT2_DISABLE();    
                break;
            default :
                ret = E_NOT_OK;
                break;
        }
                
    }
    return ret;
}
/**
 * 
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE

static Std_ReturnType Interrupt_INTx_Priorty_init(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->index)
        {
            case EXT_INT0:
                
                ret = E_NOT_OK;
                
                break;
            case EXT_INT1:
                switch(int_obj->priorty)
                {
                    case HIGH_PRIORTY:
                        INTERRUPT_INT1_HIGH_PRIORTY();
                        break;
                    case LOW_PRIORTY:
                        INTERRUPT_INT1_LOW_PRIORTY();
                        break;
                    default :
                         ret = E_NOT_OK;
                        break;
                }     
                break;
            case EXT_INT2:
                switch(int_obj->priorty)
                {
                    case HIGH_PRIORTY:
                        INTERRUPT_INT2_HIGH_PRIORTY();
                        break;
                    case LOW_PRIORTY:
                        INTERRUPT_INT2_LOW_PRIORTY();
                        break;
                    default :
                         ret = E_NOT_OK;
                        break;
                }        
            default :
                ret = E_NOT_OK;
                break;
        }        
    }
    return ret;
}
#endif

/**
 * 
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_INTx_Edge_init(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->index)
        {
            case EXT_INT0:
                switch(int_obj->edge)
                {
                    case RISING_EDGE:
                        INTERRUPT_INT0_RISING_EDGE();
                        break;
                    case FALING_EDGE:
                        INTERRUPT_INT0_FALING_EDGE();
                        break;
                    default :
                        ret = E_NOT_OK;
                        break;
                }
                break;
            case EXT_INT1:
                switch(int_obj->edge)
                {
                    case RISING_EDGE:
                        INTERRUPT_INT1_RISING_EDGE();
                        break;
                    case FALING_EDGE:
                        INTERRUPT_INT1_FALING_EDGE();
                        break;
                    default :
                        ret = E_NOT_OK;
                        break;
                }     
                break;
            case EXT_INT2:
                switch(int_obj->edge)
                {
                    case RISING_EDGE:
                        INTERRUPT_INT2_RISING_EDGE();
                        break;
                    case FALING_EDGE:
                        INTERRUPT_INT2_FALING_EDGE();
                        break;
                    default :
                        ret = E_NOT_OK;
                        break;
                }        
            default :
                ret = E_NOT_OK;
                break;
        }
                
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_INTx_Pin_init(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        ret = gpio_pin_initialize(&(int_obj->pin));
    }
    return ret;
}

/**
 * 
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_INTx_Clear_flag(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->index)
        {
            case EXT_INT0:
                INTERRUPT_INT0_CLEAR_FLAG();
                
                break;
            case EXT_INT1:
                INTERRUPT_INT1_CLEAR_FLAG();     
                break;
            case EXT_INT2:
                INTERRUPT_INT2_CLEAR_FLAG();  
                break;
            default :
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
    
}
/**
 * 
 * @param int_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_INTx_Call_Back(const Intterupt_INTx_t *int_obj)
{
    Std_ReturnType ret = E_OK;
    if(int_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(int_obj->index)
        {
            case EXT_INT0:
                INTx_Call_Back[0] = int_obj->INTx_CallBack;
                break;
            case EXT_INT1:
                INTx_Call_Back[1] = int_obj->INTx_CallBack;     
                break;
            case EXT_INT2:
                INTx_Call_Back[2] = int_obj->INTx_CallBack;     
                break;
            default :
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
    
}

/**
 * 
 * @param rb_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */
static Std_ReturnType Interrupt_RBx_Enable(const Intterupt_RBx_t *RB_obj)
{
    Std_ReturnType ret = E_OK;
    if(RB_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        
#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE
        
        INTERRUPT_PRIORTYINTERRUPTEnable();
        switch(RB_obj->priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_RBx_HIGH_PRIORTY();
                break;
            case LOW_PRIORTY:
                INTERRUPT_RBx_LOW_PRIORTY();
                break;
            default : ;
                
        }
#else
        INTERRUPT_PeripheralINTERRUPTEnable();
        INTERRUPT_GlobalINTERRUPTEnable();
        
        
#endif
        INTERRUPT_RBx_ENABLE();
    }
    return ret;
}
/**
 * 
 * @param rb_obj
 * @return statues of the function
 *         (E_OK) : function done successfully
 *         (E_NOT_OK) : the function has issue 
 */

#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE

static Std_ReturnType Interrupt_RBx_Priorty_init(const Intterupt_RBx_t *RB_obj)
{
    Std_ReturnType ret = E_OK;
    if(RB_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(RB_obj->priorty)
        {
            case HIGH_PRIORTY:
                INTERRUPT_RBx_HIGH_PRIORTY();
                break;
            case LOW_PRIORTY:
                INTERRUPT_RBx_LOW_PRIORTY();
                break;   
            default :
                ret = E_NOT_OK;
        }
    }
    return ret;
    
}
#endif

static Std_ReturnType Interrupt_RBx_Call_Back(const Intterupt_RBx_t *RB_obj)
{
    Std_ReturnType ret = E_OK;
    if(RB_obj == NULL)
    {
        ret = E_NOT_OK;
    }
    else
    {
        switch(RB_obj->pin.pin)
        {
            case GPIO_PIN4:
                RBx_Call_Back[0] = RB_obj->RBx_CallBack_High;
                RBx_Call_Back[1] = RB_obj->RBx_CallBack_Low;
                break;
            case GPIO_PIN5:
                RBx_Call_Back[2] = RB_obj->RBx_CallBack_High;
                RBx_Call_Back[3] = RB_obj->RBx_CallBack_Low;     
                break;
            case GPIO_PIN6:
                RBx_Call_Back[4] = RB_obj->RBx_CallBack_High;
                RBx_Call_Back[5] = RB_obj->RBx_CallBack_Low; 
                break;
            case GPIO_PIN7:
                RBx_Call_Back[6] = RB_obj->RBx_CallBack_High;
                RBx_Call_Back[7] = RB_obj->RBx_CallBack_Low;
                break;
            default :
                ret = E_NOT_OK;
                break;
        }
    }
    return ret;
}
