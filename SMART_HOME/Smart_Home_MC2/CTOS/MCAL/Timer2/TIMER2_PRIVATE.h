#ifndef TIMER2_PRIVATE_H_
#define TIMER2_PRIVATE_H_


/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define SREG           *((volatile u8*)0x5F)   /*AVR STATUS REGISTER*/
#define SREG_GIE       7                       /*GLOBAL INTERRUPT ENABLE*/

#define TCCR2         *((volatile u8*)0x45)          /*Timer2 control register*/
#define TCCR2_WGM00   6                              /*Waveform generation Mode bit0*/
#define TCCR2_WGM01   3                              /*Waveform generation Mode bit1*/
#define TCCR2_CS22    2                              /*Prescalar bit2*/
#define TCCR2_CS21    1                              /*Prescalar bit1*/
#define TCCR2_CS20    0                              /*Prescalar bit0*/
#define TCCR2_COM00   4                              /*COMPARE OUTPUT MODE BIT0*/
#define TCCR2_COM01   5                              /*COMPARE OUTPUT MODE BIT1*/

#define OCR2          *((volatile u8*)0x43)          /*Output Compare register 2*/

#define TIMSK         *((volatile u8*)0X59)          /*Timer mask*/
#define TIMSK_OCIE         1                         /*Output Compare 2 interrupt enable*/
#define TIMSK_TOIE2         6                         /*OVERFLOW 2 interrupt enable*/
#define TIFR		  *((volatile u8*)0x58)
#define TIFR_OCF2	  1



#define TCNT2         *((volatile u8*)0x44)
/*Define TIMER0 Mode options*/
#define TIMER2_Normal     1
#define TIMER2_CTC        2
#define TIMER2_PWM        3
#define TIMER2_DELAY      4

#endif
