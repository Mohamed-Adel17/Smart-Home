/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "ADC_INTERFACE.h"
#include "ADC_PRIVATE.h"
#include "ADC_CONFIG.h"


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void ADC_voidInit(void)
{
	/* Select AVCC reference voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);

	/*Activate Left adjust result(8 bit resolution)*/
	//SET_BIT(ADMUX,ADMUX_ADLAR);

	ADCSRA &= 0b11111000;			/*Clear first 3 bits in adcsra register*/
	ADCSRA |= ADC_u8PRESCALER;		/*set the required configuration*/

	/*Enable ADC peripheral*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);
}

u16 ADC_u8StartConversion(u8 Copy_u8Channel)
{
	/*Clear first 5 bits in ADMUX register*/
	ADMUX &= 0b11100000;

	/*set required channel*/
	ADMUX |= Copy_u8Channel;

	/*Start conversion*/
	SET_BIT(ADCSRA,ADCSRA_ADSC);

	/*Busy waiting (polling) until the conversion is complete*/
	while((GET_BIT(ADCSRA,ADCSRA_ADIF))==0);

	/*clear the interrupt flag*/
	SET_BIT(ADCSRA,ADCSRA_ADIF);

	return ADC;
}
