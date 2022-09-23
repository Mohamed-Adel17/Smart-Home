/*
 * UART1.C
 *
 *  Created on: Sep 7, 2022
 *      Author: aweso
 */

#include "avr/io.h"
#include "../../LIB/BIT_MATH.h"
#include "UART_CONFIG.h"
#include "UART.h"
#include "DIO_interface.h"

extern uart_t ptr;
void UART_init(void)
{
	DIO_SetPinDirection(_PORTD, _PIN0, _INPUT);
	DIO_SetPinDirection(_PORTD, _PIN1,_OUTPUT);
	UCSRB = 0x18 ; //running UART as receiver&transmitter
	//SET_BIT(UCSRB,TXCIE); //enable transmit interrupt

	switch(ptr.Mode)
	{
		case 0 : CLR_BIT(UCSRC,UMSEL); break;//setting UASRT to Asynchronous mode
		case 1 : SET_BIT(UCSRC,UMSEL); break;//setting UASRT to synchronous mode
	}

	switch(ptr.Parity)
	{
		case NONE :
					CLR_BIT(UCSRC,UPM1);
					CLR_BIT(UCSRC,UPM0);
					break;
		case EVEN :
					SET_BIT(UCSRC,UPM1);
					CLR_BIT(UCSRC,UPM0);
					break;
		case ODD :
					SET_BIT(UCSRC,UPM1);
					SET_BIT(UCSRC,UPM0);
					break;
	}

	switch (ptr.Stop_Bits)
	{
		case 1 : CLR_BIT(UCSRC,USBS); break;
		case 2 : SET_BIT(UCSRC,USBS);	break;
	}

	switch(ptr.Data_Bits)
	{
		case 5 :
				CLR_BIT(UCSRC,UCSZ2);
				CLR_BIT(UCSRC,UCSZ1);
				CLR_BIT(UCSRC,UCSZ0);
				break;
		case 6 :
				CLR_BIT(UCSRC,UCSZ2);
				CLR_BIT(UCSRC,UCSZ1);
				SET_BIT(UCSRC,UCSZ0);
				break;
		case 7 :
				CLR_BIT(UCSRC,UCSZ2);
				SET_BIT(UCSRC,UCSZ1);
				CLR_BIT(UCSRC,UCSZ0);
				break;
		case 8 :
				CLR_BIT(UCSRC,UCSZ2);
				SET_BIT(UCSRC,UCSZ1);
				SET_BIT(UCSRC,UCSZ0);
				break;
	}

	UBRRL = (ptr.Foc/(ptr.baud_rate * 16))-1;

}


void UART_transmit_Char(u16 data)
{

	while(GET_BIT(UCSRA,UDRE)== 0);

	UDR = data;

}


u8 UART_recieve_Char(void)
{
	while(GET_BIT(UCSRA,RXC)== 0);

	return UDR;
}


void UART_transmit_String(u8 data[])
{
	u8 i =0;
	while(data[i]!='\0')
	{
		UART_transmit_Char(data[i]);
		i++;
	}
}





