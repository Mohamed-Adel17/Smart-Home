/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "DIO_interface.h"


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void DIO_SetPinDirection(Eports_DIO port, Epins_DIO pin, Edirection_DIO direction)
{
	switch(direction)
	{
		case _OUTPUT:
			switch(port)
			{
				case _PORTA:
					SET_BIT(DDRA_R,pin); break;
				case _PORTB:
					SET_BIT(DDRB_R,pin); break;
				case _PORTC:
					SET_BIT(DDRC_R,pin); break;
				case _PORTD:
					SET_BIT(DDRD_R,pin); break;
			}
			break;
		case _INPUT:
			switch(port)
			{
				case _PORTA:
					CLEAR_BIT(DDRA_R,pin); SET_BIT(PINA_R,pin);break;
				case _PORTB:
					CLEAR_BIT(DDRB_R,pin); SET_BIT(PINB_R,pin);break;
				case _PORTC:
					CLEAR_BIT(DDRC_R,pin); SET_BIT(PINC_R,pin);break;
				case _PORTD:
					CLEAR_BIT(DDRD_R,pin); SET_BIT(PIND_R,pin);break;
			}
			break;
			default: break;
	}
}
void DIO_SetPortDirection(Eports_DIO port, Edirection_DIO direction)
{
	switch(direction)
	{
		case _OUTPUT:
			switch(port)
			{
				case _PORTA:
					DDRA_R = _PORT_HIGH; break;
				case _PORTB:
					DDRB_R = _PORT_HIGH; break;
				case _PORTC:
					DDRC_R = _PORT_HIGH; break;
				case _PORTD:
					DDRD_R = _PORT_HIGH; break;					
			}
			break;
		case _INPUT:
			switch(port)
			{
				case _PORTA:
					DDRA_R = _LOW; break;
				case _PORTB:
					DDRB_R = _LOW; break;
				case _PORTC:
					DDRC_R = _LOW; break;
				case _PORTD:
					DDRD_R = _LOW; break;				
			}
			break;
			default: break;
	}
}

void DIO_SetPinValue(Eports_DIO port, Epins_DIO pin, Estate_DIO value)
{
	switch(value)
	{
		case _HIGH:
			switch(port)
			{
				case _PORTA:
					SET_BIT(PORTA_R,pin); break;
				case _PORTB:
					SET_BIT(PORTB_R,pin); break;
				case _PORTC:
					SET_BIT(PORTC_R,pin); break;
				case _PORTD:
					SET_BIT(PORTD_R,pin); break;					
			}
			break;
		case _LOW:
			switch(port)
			{
				case _PORTA:
					CLEAR_BIT(PORTA_R,pin); break;
				case _PORTB:  
					CLEAR_BIT(PORTB_R,pin); break;
				case _PORTC:  
					CLEAR_BIT(PORTC_R,pin); break;
				case _PORTD:  
					CLEAR_BIT(PORTD_R,pin); break;					
			}
			break;
			default: break;
	}
}

void DIO_SetPortValue(Eports_DIO port, u8 value)
{
	switch(port)
	{
		case _PORTA:
			PORTA_R = value; break;
		case _PORTB:
			PORTB_R = value; break;
		case _PORTC:
			PORTC_R = value; break;
		case _PORTD:
			PORTD_R = value; break;					
	}	
}

Estate_DIO DIO_GetPinValue(Eports_DIO port, Epins_DIO pin)
{
	Estate_DIO value=_LOW;
	switch(port)
	{
		case _PORTA:
			value = GET_BIT(PINA_R,pin); break;
		case _PORTB:  
			value = GET_BIT(PINB_R,pin); break;
		case _PORTC:  
			value = GET_BIT(PINC_R,pin); break;
		case _PORTD:  
			value = GET_BIT(PIND_R,pin); break;						
	}	
	return value;
}
u8 DIO_GetPortValue(Eports_DIO port)
{
	u8 value=0;
	switch(port)
	{
		case _PORTA:
			value = PINA_R; break;
		case _PORTB:  
			value = PINB_R; break;
		case _PORTC:  
			value = PINC_R; break;
		case _PORTD:  
			value = PIND_R; break;						
	}	
	return value;
}
