/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "TIMER1_INTERFACE.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER1_PRIVATE.h"
#include "../DIO/DIO_INTERFACE.h"

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void TIMER1_FPWMinit(){
	//Configure TIMER1
	TCCR1A = 0;
	TCCR1B = 0;

	//NON Inverted PWM
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	SET_BIT(TCCR1A,TCCR1A_COM1B1);

	//MODE 14(FAST PWM)
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	SET_BIT(TCCR1B,TCCR1B_CS10); //PRESCALER=1

	ICR1=19999;  //fPWM=50Hz (Period = 20ms Standard).
	OCR1A = 388; //Door is closed
	//PWM Pins as Out
	DIO_SetPinDirection(PORTD,DIO_PIN5,DIO_OUTPUT);
}

void TIMER1_SetDutyCycle(u16 duty){
	OCR1A = duty;
}

