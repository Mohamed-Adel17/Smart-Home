#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/TIMER0/TIMER0_INTERFACE.h"
#include "../../MCAL/TIMER1/TIMER1_INTERFACE.h"
#include "../../MCAL/UART/UART.h"
#include "../../MCAL/Timer2/Timer2.h"

/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../LCD/LCD_INTERFACE.h"
#include "../LCD/LCD_PRIVATE.h"
#include "LOGIN.h"
#include "../CONTROL/CONTROL.h"
#include "../DISP_OPT/DISP_OPT.h"
#include "SPI_Interface.h"

/*Global Variables*/
s32 CorrectPass = CORRECT_PASS;


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void Program_Init(){
	SPI_InitSlave();
	MTIMER0_voidInit();
	LCD_Init(LCD_1);
	LCD_Init(LCD_2);
	UART_init();
	CONTROL_Init();
	Display_Data_LDC2();
	MTIMER2_voidInit();
	MTIMER2_voidTimer2OVSetCallBack(Control_SendUART);

}

u8 Login_CheckInputs(){
	s32 Local_ID;
	s32 Local_Pass;
	static u8 Local_Counter = 0;

	/*Display ID & Pass screen*/
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	LCD_WriteStringData((u8*) "PLEASE LOGIN!",LCD_1);
	LCD_GoToPosition(1,0,LCD_1);
	LCD_WriteStringData((u8*) "ID: ",LCD_1);
	LCD_GoToPosition(2,0,LCD_1);
	LCD_WriteStringData((u8*) "Pass: ",LCD_1);

	/*Read the ID*/
	LCD_GoToPosition(1, 4,LCD_1);
	Local_ID = LCD_ReadInput(LCD_1);

	/*Read the Password*/
	LCD_GoToPosition(2,6,LCD_1);
	Local_Pass = LCD_ReadInput(LCD_1);

	if(Local_ID == CORRECT_ID && Local_Pass == CorrectPass){
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "LOGIN SUCCESSFUL!",LCD_1);
		MTIMER0_voidSetBusyWait(DELAY_LCD);
		Local_Counter = 0;
		return 1;
	}
	else if(Local_Counter < 2){
		Local_Counter++;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*)"TRY AGAIN!",LCD_1);
		MTIMER0_voidSetBusyWait(DELAY_LCD+150);
		return Login_CheckInputs();
	}
	else{
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "LOGIN FAILED",LCD_1);
		LCD_GoToPosition(1,0,LCD_1);
		LCD_WriteStringData((u8*) "TRY AGAIN LATER!",LCD_1);
		MTIMER0_voidSetBusyWait(5000);
		Local_Counter = 0;
		return 0;
	}
}

void Login_ChangePass(){
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	LCD_WriteStringData((u8*) "NEW PASS: ",LCD_1);

	CorrectPass = LCD_ReadInput(LCD_1);
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	LCD_WriteStringData((u8*) "PASSWORD UPDATED!",LCD_1);
	MTIMER0_voidSetBusyWait(DELAY_LCD);
}

