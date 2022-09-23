#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H


#include "../../LIB/STD_TYPES.h"
/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define DIO_PORTHIGH 0xFF

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

enum PORT{
	PORTA = 0,
	PORTB = 1,
	PORTC = 2,
	PORTD = 3
};

enum DIRECTION{
	DIO_INPUT  = 0,
	DIO_OUTPUT = 1
};

enum PIN{
	DIO_PIN0 = 0,
	DIO_PIN1 = 1,
	DIO_PIN2 = 2,
	DIO_PIN3 = 3,
	DIO_PIN4 = 4,
	DIO_PIN5 = 5,
	DIO_PIN6 = 6,
	DIO_PIN7 = 7,
};

enum VALUE{
	DIO_LOW = 0,
	DIO_HIGH = 1
};


void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 DIO_GetPinValue(u8 Port, u8 Pin);
u8 DIO_GetPortValue(u8 Port);
void DIO_SetPortValue(u8 Port,u8 Value);
void DIO_SetPortDirection(u8 Port,u8 Direction);

#endif
