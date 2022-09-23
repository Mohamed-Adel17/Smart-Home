/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "Control_Input.h"
#include "KEYPAD_INTERFACE.h"
#include "SPI_Interface.h"
#include "KEYPAD_CONFIG.h"


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void Control_Init(void){
	KPD_Init();
	SPI_InitMaster();
}

void Control_Input(void)
{
	u8 Key=KPD_GetPressedKey();
	if (Key != NO_PRESSED_KEY)
	{
		SPI_Send(Key);
	}
}
