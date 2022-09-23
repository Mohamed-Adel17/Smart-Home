#ifndef TIMER0_CONFIG_H_
#define TIMER0_CONFIG_H_

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

/********************************************************
*Choose Timer Mode
*Options :
*            1- TIMER0_Normal for normal mode
*			  2- TIMER0_CTC    for compare on match mode
*			  3- TIMER0_PWM    for pwm mode
*  		  4- TIMER0_DELAY  for delay mode
********************************************************/
#define TIMER0_Mode TIMER0_DELAY

#endif 
