/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "KEYPAD_INTERFACE.h"
#include "KEYPAD_PRIVATE.h"
#include "KEYPAD_CONFIG.h"
#include "DIO_interface.h"


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

u8 KPD_GetPressedKey(){
	u8 Local_u8PressedKey = NO_PRESSED_KEY;
	u8 Local_u8ColIndex;
	u8 Local_u8RowIndex;
	u8 Local_u8KPDArr[ROW_NUMBER][COL_NUMBER] = {KPD_ARR_VAL};
	u8 Local_u8ColArr[COL_NUMBER] = {KPD_COL0_PIN, KPD_COL1_PIN, KPD_COL2_PIN};
	u8 Local_u8RowArr[ROW_NUMBER] = {KPD_ROW0_PIN, KPD_ROW1_PIN, KPD_ROW2_PIN, KPD_ROW3_PIN};
	for(Local_u8ColIndex = 0; Local_u8ColIndex < COL_NUMBER; Local_u8ColIndex++){
		/*Activate current column by clearing it*/
		DIO_SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIndex],_LOW);

		for(Local_u8RowIndex = 0; Local_u8RowIndex < ROW_NUMBER; Local_u8RowIndex++){
			if(DIO_GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex]) == _LOW){
				Local_u8PressedKey = Local_u8KPDArr[Local_u8RowIndex][Local_u8ColIndex];
				while(DIO_GetPinValue(KPD_PORT,Local_u8RowArr[Local_u8RowIndex]) == _LOW){

				}
				DIO_SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIndex],_HIGH);
				return Local_u8PressedKey;
			}
		}

		/*Deactivate current column by setting it*/
		DIO_SetPinValue(KPD_PORT,Local_u8ColArr[Local_u8ColIndex],_HIGH);

	}
	return Local_u8PressedKey;
}

void KPD_Init(){
	DIO_SetPinDirection(KPD_PORT,KPD_COL0_PIN,_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_COL1_PIN,_OUTPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_COL2_PIN,_OUTPUT);

	DIO_SetPinDirection(KPD_PORT,KPD_ROW0_PIN,_INPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_ROW1_PIN,_INPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_ROW2_PIN,_INPUT);
	DIO_SetPinDirection(KPD_PORT,KPD_ROW3_PIN,_INPUT);

	DIO_SetPortValue(KPD_PORT,_PORT_OUTPUT);
}
