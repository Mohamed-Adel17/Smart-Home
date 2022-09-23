/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "SPI_Interface.h"
#include "STD_TYPES.h"
#include "BIT_math.h"
#include "DIO_interface.h"


void SPI_InitMaster(void)
{
	DIO_SetPinDirection(_PORTB, _PIN4, _INPUT);
	DIO_SetPinValue(_PORTB, _PIN4, _HIGH);
	DIO_SetPinDirection(_PORTB, _PIN5, _OUTPUT);
	DIO_SetPinDirection(_PORTB, _PIN6, _INPUT);
	DIO_SetPinValue(_PORTB, _PIN6, _HIGH);
	DIO_SetPinDirection(_PORTB, _PIN7, _OUTPUT);


	SET_BIT(SPCR,MSTR);//MASTER
	SET_BIT(SPCR,SPE);//ENABLE
}
void SPI_InitSlave(void)
{
	CLEAR_BIT(SPCR,MSTR);//Slave
	
	SET_BIT(SPCR,SPE);//ENABLE
}
u8 SPI_SendRecieve(u8 data)
{
	SPDR=data;
	while (!GET_BIT(SPSR,SPIF));
	return SPDR;
}
void SPI_Send(u8 data)
{
	SPDR=data;
	while (!GET_BIT(SPSR,SPIF));
}
u8 SPI_Recieve(void)
{
	while (!GET_BIT(SPSR,SPIF));
	return SPDR;
}
