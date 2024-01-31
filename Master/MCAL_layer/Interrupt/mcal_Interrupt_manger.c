/* 
 * File:   mcal_Interrupt_manger.c
 * Author: Ammar Yasser
 *
 * Created on 17 Decemper, 2023, 04:27 ?
 */

#include "mcal_Interrupt_manger.h"

static volatile uint8 RBx_flag[4]={0};

#if INTERRUPT_PRIORTY_LEVEL == INTERRUPT_FEATURE_ENABLE

void __interrupt() Interrupt_manager_high(void)
{
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE)&&(INTCONbits.INT0F == INTERRUPT_OCCUR))
    {
        INT0_ISR();
    }
    else
    {/*Nothing*/}
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF == INTERRUPT_OCCUR))
    {
        INT2_ISR();
    }
    else
    {/*Nothing*/}
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE)&&(INTCONbits.TMR0IF == INTERRUPT_OCCUR))
    {
        TIMER0_ISR();
    }
    else
    {/*Nothing*/}
}

void __interrupt(low_priority) Interrupt_manager_low(void)
{
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT1F == INTERRUPT_OCCUR))
    {
        INT1_ISR();
    }
    else
    {/*Nothing*/}
}
#else

void __interrupt() Interrupt_manager(void)
{
    /*==========================EXTERNAL INTERRUPT Section Start==========================*/
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE)&&(INTCONbits.INT0F == INTERRUPT_OCCUR))
    {
        INT0_ISR();
    }
    else
    {/*Nothing*/}
    if((INTCON3bits.INT1IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT1F == INTERRUPT_OCCUR))
    {
        INT1_ISR();
    }
    else
    {/*Nothing*/}
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE)&&(INTCON3bits.INT2IF == INTERRUPT_OCCUR))
    {
        INT2_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================EXTERNAL INTERRUPT Section End==========================*/
    
    /*==========================RB INTERRUPT Section Start==========================*/
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB4 == GPIO_HIGH)&&(RBx_flag[0] == 0))
    {
        RBx_flag[0] = 1;
        RB4_ISR(0);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB4 == GPIO_LOW)&&(RBx_flag[0] == 1))
    {
        RBx_flag[0] = 0;
        RB4_ISR(1);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB5 == GPIO_HIGH)&&(RBx_flag[1] == 0))
    {
        RBx_flag[1] = 1;
        RB5_ISR(0);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB5 == GPIO_LOW)&&(RBx_flag[1] == 1))
    {
        RBx_flag[1] = 0;
        RB5_ISR(1);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB6 == GPIO_HIGH)&&(RBx_flag[2] == 0))
    {
        RBx_flag[2] = 1;
        RB6_ISR(0);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB6 == GPIO_LOW)&&(RBx_flag[2] == 1))
    {
        RBx_flag[2] = 0;
        RB6_ISR(1);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB7 == GPIO_HIGH)&&(RBx_flag[3] == 0))
    {
        RBx_flag[3] = 1;
        RB7_ISR(0);
    }
    else
    {/*Nothing*/}
    if((INTCONbits.RBIE == INTERRUPT_ENABLE)&&(INTCONbits.RBIF == INTERRUPT_OCCUR)&&(PORTBbits.RB7 == GPIO_LOW)&&(RBx_flag[3] == 1))
    {
        RBx_flag[3] = 0;
        RB7_ISR(1);
    }
    else
    {/*Nothing*/}
    
    /*==========================RB INTERRUPT Section End==========================*/
    
    /*==========================ADC INTERRUPT Section Start==========================*/
    if((PIE1bits.ADIE == INTERRUPT_ENABLE)&&(PIR1bits.ADIF == INTERRUPT_OCCUR))
    {
        ADC_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================ADC INTERRUPT Section End==========================*/
    
    /*==========================TIMER0 INTERRUPT Section Start==========================*/
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE)&&(INTCONbits.TMR0IF == INTERRUPT_OCCUR))
    {
        TIMER0_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================TIMER0 INTERRUPT Section End==========================*/
    
    /*==========================TIMER1 INTERRUPT Section Start==========================*/
    if((PIE1bits.TMR1IE == INTERRUPT_ENABLE)&&(PIR1bits.TMR1IF == INTERRUPT_OCCUR))
    {
        TIMER1_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================TIMER1 INTERRUPT Section End==========================*/
    
    /*==========================TIMER2 INTERRUPT Section Start==========================*/
    if((PIE1bits.TMR2IE == INTERRUPT_ENABLE)&&(PIR1bits.TMR2IF == INTERRUPT_OCCUR))
    {
        TIMER2_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================TIMER2 INTERRUPT Section End==========================*/
    
    /*==========================TIMER2 INTERRUPT Section Start==========================*/
    if((PIE2bits.TMR3IE == INTERRUPT_ENABLE)&&(PIR2bits.TMR3IF == INTERRUPT_OCCUR))
    {
        TIMER3_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================TIMER2 INTERRUPT Section End==========================*/
    /*==========================CCP1 INTERRUPT Section Start==========================*/
    if((PIE1bits.CCP1IE == INTERRUPT_ENABLE)&&(PIR1bits.CCP1IF == INTERRUPT_OCCUR))
    {
        CCP1_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================CCP1 INTERRUPT Section End==========================*/
    
    /*==========================CCP2 INTERRUPT Section Start==========================*/
    if((PIE2bits.CCP2IE == INTERRUPT_ENABLE)&&(PIR2bits.CCP2IF == INTERRUPT_OCCUR))
    {
        CCP2_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================CCP2 INTERRUPT Section End==========================*/
    /*==========================EUSART TX INTERRUPT Section Start==========================*/
    if((PIE1bits.TXIE == INTERRUPT_ENABLE)&&(PIR1bits.TXIF == INTERRUPT_OCCUR))
    {
        EUSART_TX_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================EUSART TX INTERRUPT Section End==========================*/
    /*==========================EUSART RX INTERRUPT Section Start==========================*/
    if((PIE1bits.RCIE == INTERRUPT_ENABLE)&&(PIR1bits.RCIF == INTERRUPT_OCCUR))
    {
        EUSART_RX_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================SPI INTERRUPT Section End==========================*/
    if((PIE1bits.SSPIE == INTERRUPT_ENABLE)&&(PIR1bits.SSPIF == INTERRUPT_OCCUR)&&(SPI_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE))
    {
        SPI_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================SPI INTERRUPT Section End==========================*/
    /*==========================I2C INTERRUPT Section End==========================*/
    if((PIE1bits.SSPIE == INTERRUPT_ENABLE)&&(PIR1bits.SSPIF == INTERRUPT_OCCUR)&&(I2C_INTERRUPT_FEATURE == INTERRUPT_FEATURE_ENABLE))
    {
        I2C_ISR();
    }
    else
    {/*Nothing*/}
    if((PIE2bits.BCLIE == INTERRUPT_ENABLE)&&(PIR2bits.BCLIF == INTERRUPT_OCCUR))
    {
        I2C_Bus_Collision_ISR();
    }
    else
    {/*Nothing*/}
    /*==========================I2C INTERRUPT Section End==========================*/
}


#endif
