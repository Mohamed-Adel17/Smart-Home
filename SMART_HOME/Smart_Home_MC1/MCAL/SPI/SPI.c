/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "SPI_Interface.h"
#include "STD_TYPES.h"
#include "BIT_math.h"
#include "../../MCAL/DIO/DIO_INTERFACE.h"

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void SPI_InitMaster(void)
{
	SET_BIT(SPCR,MSTR);//MASTER
	SET_BIT(SPCR,SPE);//ENABLE
}
void SPI_InitSlave(void)
{
	DIO_SetPinDirection(PORTB, DIO_PIN4, DIO_INPUT);
	DIO_SetPinDirection(PORTB, DIO_PIN5, DIO_INPUT);
	DIO_SetPinValue(PORTB, DIO_PIN5, DIO_HIGH);
	DIO_SetPinDirection(PORTB, DIO_PIN6, DIO_OUTPUT);
	DIO_SetPinDirection(PORTB, DIO_PIN7, DIO_INPUT);
	DIO_SetPinValue(PORTB, DIO_PIN7, DIO_HIGH);

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
