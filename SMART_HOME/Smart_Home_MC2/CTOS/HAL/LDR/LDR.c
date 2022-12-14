/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/
#include "STD_TYPES.h"
#include "DIO_interface.h"
#include "ADC.h"
#include "LDR.h"

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

u16 LDR_GetData(void)
{
	u16 LDR_VOLT = ADC_u16ReadData(LDR_PIN);
	return LDR_VOLT;
}
