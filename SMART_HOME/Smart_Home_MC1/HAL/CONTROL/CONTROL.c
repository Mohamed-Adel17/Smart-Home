/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../MCAL/TIMER1/TIMER1_INTERFACE.h"
#include "../../MCAL/TIMER0/TIMER0_INTERFACE.h"
#include "../../MCAL/Timer2/Timer2.h"
#include "../../MCAL/UART/UART.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../LCD/LCD_INTERFACE.h"
#include "../LCD/LCD_PRIVATE.h"
#include "CONTROL.h"


/*Global Array for data to be displayed*/
u8 GLOBAL_Display[DISPLAY_SIZE] ={DEFAULT_TEMP_THRESHOLD,0,0,0,0};

/*Global variables*/
u8 Temp_Threshold = DEFAULT_TEMP_THRESHOLD;


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void CONTROL_Init(){
	Control_union.Tasks_t.LIGHTS = 0;
	Control_union.Tasks_t.DOORS  = 0;
	Control_union.Tasks_t.SOUND  = 0;
}


void CONTROL_DOOR(u8 Open){
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	if(Open){
		TIMER1_SetDutyCycle(1249);

		LCD_WriteStringData((u8*) "DOOR OPENED!",LCD_1);
	}
	else{
		TIMER1_SetDutyCycle(388);
		LCD_WriteStringData((u8*) "DOOR CLOSED!",LCD_1);
	}
	Control_union.Tasks_t.DOORS = Open;
	MTIMER0_voidSetBusyWait(DELAY_LCD);//delay 350ms
}


void CONTROL_LDR(u8 On){
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	if(On){
		LCD_WriteStringData((u8*) "LDR TURNED ON!",LCD_1);
	}
	else{
		LCD_WriteStringData((u8*) "LDR TURNED OFF!",LCD_1);
	}
	Control_union.Tasks_t.LIGHTS = On;
	MTIMER0_voidSetBusyWait(DELAY_LCD);//delay 350ms
}


void CONTROL_Music(u8 On){
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	if(On){
		LCD_WriteStringData((u8*) "MUSIC TURNED ON!",LCD_1);
	}
	else{
		LCD_WriteStringData((u8*) "MUSIC TURNED OFF!",LCD_1);
	}
	Control_union.Tasks_t.SOUND = On;
	MTIMER0_voidSetBusyWait(DELAY_LCD);//delay 350ms
}


void Change_TempThreshold(){
	u8 input = 0;
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
	LCD_WriteStringData((u8*) "NEW THRESHOLD: ",LCD_1);
	input = LCD_ReadInput(LCD_1);
	if(input <= 30){
		Temp_Threshold= input;
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "THRESHOLD UPDATED!",LCD_1);
	}
	else{
		LCD_WriteCommand(DISPLAY_CLEAR,LCD_1);
		LCD_WriteStringData((u8*) "INCORRECT THRESHOLD!",LCD_1);
	}

	MTIMER0_voidSetBusyWait(DELAY_LCD);//delay 350ms
}


void Control_SendUART(){
	static u8 flag=0, flag2=0, flag3=0;
	u8 sent_Data = Control_union.TASK_REG;
	u8 rec_Data;
	if(flag == 0){
		if(flag2 == 1){
			UART_transmit_Char(sent_Data);
			flag2 = 0;
		}
		else{
			UART_transmit_Char(Temp_Threshold);
			flag2 = 1;
		}
		flag=1;
	}else{

		rec_Data = UART_recieve_Char();
		if(flag3 == 0){
			LCD_GoToPosition(0,6,LCD_2);
			LCD_WriteIntData(rec_Data,LCD_2);//display temperature degree
			flag3 = 1;
		}
		else{
			LCD_GoToPosition(0,16,LCD_2);
			LCD_WriteStringData(DATA_CHECK(GET_BIT(rec_Data,0)),LCD_2);//display LDR status

			LCD_GoToPosition(1,6,LCD_2);
			LCD_WriteStringData(DATA_CHECK(GET_BIT(rec_Data,1)),LCD_2);//display Door status

			LCD_GoToPosition(1,16,LCD_2);
			LCD_WriteStringData(DATA_CHECK(GET_BIT(rec_Data,2)),LCD_2);//display Music status

			LCD_GoToPosition(2,6,LCD_2);
			LCD_WriteStringData(DATA_CHECK(GET_BIT(rec_Data,3)),LCD_2);//display Smoke status
			flag3 = 0;
		}
		flag=0;
	}
}


