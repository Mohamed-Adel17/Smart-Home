/*
 * ADC.c
 *
 * Created: 07/02/2021 03:29:01 م
 *  Author: Mu
 */ 

#include "STD_TYPES.h"
#include "BIT_math.h"
#include "ADC.h"
#include "avr/interrupt.h"
#include "DIO_interface.h"
#define Vref 5
//volatile u16 Volt=0;
/*ISR(ADC_vect)
{

	Volt = ADC_R;
	//CLEAR_BIT(ADCSRA_R,ADIE_R);  //enable ADC interrupt
}*/

void ADC_INIT(void)
{
	DIO_SetPortDirection(_PORTA,_PORT_INPUT);
	SET_BIT(ADCSRA_R,ADEN_R);  //enable ADC
	
	/*set the prescaler of ADC to 64*/
	SET_BIT(ADCSRA_R,ADPS2_R);
	SET_BIT(ADCSRA_R,ADPS1_R);
		
	SET_BIT(ADMUX_R,REFS0_R);  //set ADC voltage from AVCC
	//SET_BIT(ADCSRA_R,ADIE_R);  //enable ADC interrupt
	
	//sei(); //enable global interrupts
}

u16 ADC_u16ReadData(u8 channel)
{
	ADMUX_R &= 0b11100000;

	ADMUX_R |= channel;

	/*if(ADMUX_R == channel)
	{
		if(channel == 0xC2)
		{
			SET_BIT(ADCSRA_R,ADSC_R);
			while(GET_BIT(ADCSRA_R,ADIF_R)==0);
			ADMUX_R= 0xC0;
		}else
		{
			SET_BIT(ADCSRA_R,ADSC_R);
			while(GET_BIT(ADCSRA_R,ADIF_R)==0);
			ADMUX_R= 0xC2;
		}
	}
	else if(channel == 0xC0)
	{
		ADMUX_R = 0xC2;
		SET_BIT(ADCSRA_R,ADSC_R);
		while(GET_BIT(ADCSRA_R,ADIF_R)==0);
		ADMUX_R = 0xC0;
	}else
	{
		ADMUX_R = 0xC0;
		SET_BIT(ADCSRA_R,ADSC_R);
		while(GET_BIT(ADCSRA_R,ADIF_R)==0);
		ADMUX_R = 0xC2;
	}*/

	SET_BIT(ADCSRA_R,ADSC_R); //start the conversion process
	while(GET_BIT(ADCSRA_R,ADIF_R)==0);

	CLEAR_BIT(ADCSRA_R,ADIF_R);
	return ADC_R;

}

f32 ADC_f32ReadVoltage(u8 channel)
{
	
	u16 voltage = ADC_u16ReadData(channel);
	f32 Vin  = (Vref*voltage)/1024.0;
	return Vin ;
}


 
