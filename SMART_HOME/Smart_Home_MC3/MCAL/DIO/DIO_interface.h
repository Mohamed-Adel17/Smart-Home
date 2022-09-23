#ifndef DIO_interface_H
#define DIO_interface_H

/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "DIO_private.h"
#include "BIT_math.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	_PORTA=1,
	_PORTB,
	_PORTC,
	_PORTD,
}Eports_DIO;

typedef enum
{
	_PIN0=0,
	_PIN1,
	_PIN2,
	_PIN3,
	_PIN4,
	_PIN5,
	_PIN6,
	_PIN7
}Epins_DIO;

typedef enum
{
	_LOW       = 0,
	_HIGH      = 1,
}Estate_DIO;

typedef enum
{
	_INPUT       = 0,
	_OUTPUT      = 1,
	_PORT_INPUT  = 0,
	_PORT_OUTPUT = 0xFF
}Edirection_DIO;

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define _PORT_HIGH 0xFF



void DIO_SetPinDirection(Eports_DIO port, Epins_DIO pin, Edirection_DIO direction);
void DIO_SetPortDirection(Eports_DIO port, Edirection_DIO direction);

void DIO_SetPinValue(Eports_DIO port, Epins_DIO pin, Estate_DIO value);
void DIO_SetPortValue(Eports_DIO port, u8 value);

Estate_DIO DIO_GetPinValue(Eports_DIO port, Epins_DIO bit);
u8 DIO_GetPortValue(Eports_DIO port);


#endif
