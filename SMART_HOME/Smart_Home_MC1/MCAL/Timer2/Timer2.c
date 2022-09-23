/*
 * Timer2.c
 *
 *  Created on: Sep 7, 2022
 *      Author: Mohamed Adel
 */


#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "Timer2.h"
#include "TIMER2_PRIVATE.h"
#include "TIMER2_CONFIG.h"

     /*Define Pointer to TIMER0 ISR functions*/
 void (*Global_pvTimer2OverFlowCallBack)(void)= NULL;
 void (*Global_pvTimer2CTCCallBack)(void)= NULL;

 /**********************************************************************************************************************
  *  Functions Definitions
  *********************************************************************************************************************/

void MTIMER2_voidInit()
{
	#if  TIMER2_Mode == TIMER2_Normal

	/*Normal Mode*/

	/*Timer Over flow flag Enable*/
	SET_BIT(TIMSK, TIMSK_TOIE2);
	SET_BIT(SREG,SREG_GIE);                /*ENABLE GLOBAL INTERRUPT*/

	TCNT2 = 108; //ISR every 150ms

	/*Set PRESCALAR 1024*/
	SET_BIT(TCCR2, TCCR2_CS20);
	SET_BIT(TCCR2, TCCR2_CS21);
	SET_BIT(TCCR2, TCCR2_CS22);


	#elif     TIMER2_Mode == TIMER2_CTC
	/*Choose CTC Mode*/
	CLR_BIT(TCCR2, TCCR2_WGM00);
	SET_BIT(TCCR2, TCCR2_WGM01);

	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIMSK, TIMSK_OCIE);
	SET_BIT(SREG,SREG_GIE);
	/*Set compare match value to 250*/
	OCR2=250;

	/*Set PRESCALAR 1*/
	SET_BIT(TCCR2, TCCR2_CS00);
	CLR_BIT(TCCR2, TCCR2_CS01);
	CLR_BIT(TCCR2, TCCR2_CS02);
	#elif     TIMER0_Mode == TIMER0_PWM

	/*Choose Fast PWM Mode*/
	SET_BIT(TCCR2, TCCR2_WGM00);
	SET_BIT(TCCR2, TCCR2_WGM01);

	/*SET OC0 ON TOP CLEAR OC0 ON COMPARE*/
	CLR_BIT(TCCR2, TCCR2_COM00);
	SET_BIT(TCCR2, TCCR2_COM01);

	OCR0=0;
	/*Set PRESCALAR 64*/
	SET_BIT(TCCR2, TCCR2_CS00);
	CLR_BIT(TCCR2, TCCR2_CS01);
	CLR_BIT(TCCR2, TCCR2_CS02);

#elif TIMER0_Mode == TIMER0_DELAY
	CLR_BIT(TCCR2, TCCR2_WGM00);
	SET_BIT(TCCR2, TCCR2_WGM01);

	/*OUTPUT COMPARE MATCH INTERRUPT ENABLE*/
	SET_BIT(TIFR,TIFR_OCF2);
	/*Set compare match value to 250*/
	OCR0=250;

	/*Set PRESCALAR 8*/
	CLR_BIT(TCCR2, TCCR0_CS00);
	SET_BIT(TCCR2, TCCR0_CS01);
	CLR_BIT(TCCR2, TCCR0_CS02);
	#endif
}

void MTIMER2_voidSetDuty(u8 Copy_u8DutyCycle)
{
	/*Check for mode is PWM*/

	OCR2 = Copy_u8DutyCycle;               /*Sets OCR0 value*/

}

void MTIMER2_voidTimer2OVSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvTimer2OverFlowCallBack= Copy_pvCallBackFunc; /*ADDS ISR Function*/
	}
	else
	{
		/*do nothing*/
	}

}

void MTIMER2_voidTimer2CTCSetCallBack(void (*Copy_pvCallBackFunc)(void))
{
	if(Copy_pvCallBackFunc != NULL) /*checking if function exists*/
	{
		Global_pvTimer2CTCCallBack= Copy_pvCallBackFunc; /*ADDS ISR Function*/
	}
	else
	{
		/*do nothing*/
	}

}

void MTIMER2_voidSetBusyWait(u16 Copy_u8WaitTime){
	u16 Local_u8Counter = 0;
	u8 counter = 0;
	while(Local_u8Counter != Copy_u8WaitTime){
		if(GET_BIT(TIFR,TIFR_OCF2)){
			counter++;
			SET_BIT(TIFR,TIFR_OCF2);
		}
		if(counter == 4){
			Local_u8Counter++;
			counter = 0;
		}
	}
}

//TIMER OVERFLOW ISR
void  __vector_5 (void)	__attribute__((signal));
void  __vector_5 (void)
{
	TCNT2 = 108; //ISR every 150ms

	if(Global_pvTimer2OverFlowCallBack != NULL)
	{
		Global_pvTimer2OverFlowCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}

//ON COMPARE ISR
void  __vector_4 (void)	__attribute__((signal));
void  __vector_4 (void)
{
	if(Global_pvTimer2CTCCallBack != NULL)
	{
		Global_pvTimer2CTCCallBack();
	}
	else
	{
		/*Do nothing*/
	}

}
