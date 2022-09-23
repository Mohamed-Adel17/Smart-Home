/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "GAS.h"
/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/
 
u8 GAS_GetData(void)
{
	return DIO_GetPinValue(GAS_PORT,GAS_PIN);
}

void GAS_Alarm(u8 GAS_State)
{
	switch(GAS_State)
	{
		case 0: DIO_SetPinValue(GAS_PORT,GAS_ALARM_PIN,_LOW); break;
		case 1: DIO_SetPinValue(GAS_PORT,GAS_ALARM_PIN,_HIGH); break;

	}
}
