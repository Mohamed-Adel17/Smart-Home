/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/TIMER0/TIMER0_INTERFACE.h"
#include "../../MCAL/TIMER1/TIMER1_INTERFACE.h"
#include "../../MCAL/Timer2/Timer2.h"

#include "../LCD/LCD_INTERFACE.h"
#include "../LCD/LCD_PRIVATE.h"
#include "../LOGIN/LOGIN.h"
#include "../CONTROL/CONTROL.h"
#include "DISP_OPT.h"


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void Display_Data_LDC2(void)
{

	LCD_WriteCommand(DISPLAY_CLEAR,LCD_2);
	LCD_WriteStringData((u8*)"TEMP",LCD_2);

	LCD_GoToPosition(0,10,LCD_2);
	LCD_WriteStringData((u8*)"LDR   OFF",LCD_2);

	LCD_GoToPosition(1,0,LCD_2);
	LCD_WriteStringData((u8*)"DOOR  OFF",LCD_2);

	LCD_GoToPosition(1,10,LCD_2);
	LCD_WriteStringData((u8*)"MUSIC OFF",LCD_2);

	LCD_GoToPosition(2,0,LCD_2);
	LCD_WriteStringData((u8*)"SMOKE OFF",LCD_2);

}




void DISP_OPT_Init(){
	u8 exit = 0;
	while(!exit){
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteIntData(AC,LCD_1);
		LCD_WriteStringData((u8*)"-AC",LCD_1);

		LCD_GoToPosition(0,9,LCD_1);
		LCD_WriteIntData(LDR,LCD_1);
		LCD_WriteStringData((u8*)"-LDR",LCD_1);

		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteIntData(DOOR,LCD_1);
		LCD_WriteStringData((u8*)"-DOOR",LCD_1);

		LCD_GoToPosition(1,9,LCD_1);
		LCD_WriteIntData(MUSIC,LCD_1);
		LCD_WriteStringData((u8*)"-MUSIC",LCD_1);

		LCD_GoToPosition(2,0,LCD_1);
		LCD_WriteIntData(RETURN,LCD_1);
		LCD_WriteStringData((u8*)"-RETURN",LCD_1);

		LCD_GoToPosition(3,0,LCD_1);
		LCD_WriteStringData((u8*)"YOUR CHOICE: ",LCD_1);

		switch(LCD_ReadInput(LCD_1)){
		case AC:
			DISP_OPT_AC();
			break;
		case LDR:
			DISP_OPT_LDR();
			break;
		case DOOR:
			DISP_OPT_DOOR();
			break;
		case MUSIC:
			DISP_OPT_MUSIC();
			break;
		case RETURN:
			exit = 1;
			break;
		default:
			LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
			LCD_WriteStringData((u8*) "INVALID CHOICE!",LCD_1);
			MTIMER0_voidSetBusyWait(DELAY_LCD);
			break;
		}
	}
}

void DISP_OPT_AC(){
	u8 flag = 0;
	do{
		flag= 0;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "CHANGE AC THRESHOLD?",LCD_1);

		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteStringData((u8*) "1-YES",LCD_1);

		LCD_GoToPosition(1,9,LCD_1);
		LCD_WriteStringData((u8*) "2-NO",LCD_1);

		LCD_GoToPosition(2,0,LCD_1);
		LCD_WriteStringData((u8*) "YOUR CHOICE: ",LCD_1);
		switch(LCD_ReadInput(LCD_1)){
		case YES:
			Change_TempThreshold();
			break;
		case NO:
			break;
		default:
			flag = 1;
			LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
			LCD_WriteStringData((u8*) "INVALID CHOICE!",LCD_1);
			MTIMER0_voidSetBusyWait(DELAY_LCD);
			break;
		}
	}while(flag);
}

void DISP_OPT_LDR(){
	u8 flag = 0;
	do{
		flag= 0;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "ENABLE LDR SYSTEM?",LCD_1);

		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteStringData((u8*) "1-YES",LCD_1);

		LCD_GoToPosition(1,9,LCD_1);
		LCD_WriteStringData((u8*) "2-NO",LCD_1);

		LCD_GoToPosition(2,0,LCD_1);
		LCD_WriteStringData((u8*) "YOUR CHOICE: ",LCD_1);
		switch(LCD_ReadInput(LCD_1)){
		case YES:
			CONTROL_LDR(1);
			break;
		case NO:
			CONTROL_LDR(0);
			break;
		default:
			flag = 1;
			LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
			LCD_WriteStringData((u8*) "INVALID CHOICE!",LCD_1);
			MTIMER0_voidSetBusyWait(DELAY_LCD);
			break;
		}
	}while(flag);
}

void DISP_OPT_DOOR(){
	u8 flag = 0;
	do{
		flag= 0;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "DOOR CONTROL",LCD_1);

		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteStringData((u8*) "1-OPEN DOOR",LCD_1);

		LCD_GoToPosition(2,0,LCD_1);
		LCD_WriteStringData((u8*) "2-CLOSE DOOR",LCD_1);

		LCD_GoToPosition(3,0,LCD_1);
		LCD_WriteStringData((u8*) "YOUR CHOICE: ",LCD_1);
		switch(LCD_ReadInput(LCD_1)){
		case 1:
			CONTROL_DOOR(1);
			break;
		case 2:
			CONTROL_DOOR(0);
			break;
		default:
			flag = 1;
			LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
			LCD_WriteStringData((u8*) "INVALID CHOICE!",LCD_1);
			MTIMER0_voidSetBusyWait(DELAY_LCD);
			break;
		}
	}while(flag);
}

void DISP_OPT_MUSIC(){
	u8 flag = 0;
	do{
		flag= 0;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "ENABLE MUSIC SYSTEM?",LCD_1);

		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteStringData((u8*) "1-YES",LCD_1);

		LCD_GoToPosition(1,9,LCD_1);
		LCD_WriteStringData((u8*) "2-NO",LCD_1);

		LCD_GoToPosition(2,0,LCD_1);
		LCD_WriteStringData((u8*) "YOUR CHOICE: ",LCD_1);
		switch(LCD_ReadInput(LCD_1)){
		case YES:
			CONTROL_Music(1);
			break;
		case NO:
			CONTROL_Music(0);
			break;
		default:
			flag = 1;
			LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
			LCD_WriteStringData((u8*) "INVALID CHOICE!",LCD_1);
			MTIMER0_voidSetBusyWait(DELAY_LCD);
			break;
		}
	}while(flag);
}

void USER_MODE_Init(){
	u8 flag = 0;
	do{
		flag = 0;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "1-DISPLAY OPTIONS",LCD_1);

		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteStringData((u8*) "2-CHANGE PASSWORD",LCD_1);

		LCD_GoToPosition(2,0,LCD_1);
		LCD_WriteStringData((u8*) "3-LOGOUT",LCD_1);

		LCD_GoToPosition(3,0,LCD_1);
		LCD_WriteStringData((u8*) "YOUR CHOICE: ",LCD_1);
		switch(LCD_ReadInput(LCD_1)){
		case 1:
			DISP_OPT_Init();
			flag = 1;
			break;
		case 2:
			Login_ChangePass();
			break;
		case 3:
			CONTROL_Init();
			break;
		default:
			flag = 1;
			LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
			LCD_WriteStringData((u8*) "INVALID CHOICE!",LCD_1);
			MTIMER0_voidSetBusyWait(DELAY_LCD);
			break;
		}
	}while(flag);
}
