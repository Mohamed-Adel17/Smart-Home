/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "Program_Flow.h"
#include "DIO_interface.h"
#include "ADC.h"
#include "LM35.h"
#include "GAS.h"
#include "FAN.h"
#include "LDR.h"
#include "Lights.h"
#include "TIMER1_INTERFACE.h"
#include "UART.h"

/*Global Array to control different systems*/
u8 Global_Control[TASK_SIZE]={DEFAULT_TEMP_THRESHOLD,0,0,0};



/*Global Variables*/
u8 Temp_Display = DEFAULT_TEMP_THRESHOLD;

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void HW_Init(void)
{
	DIO_SetPinDirection(FAN_PORT,FAN_PIN,_OUTPUT);
	DIO_SetPinDirection(GAS_PORT,GAS_PIN,_INPUT);
	DIO_SetPinDirection(MUSIC_PORT,MUSIC_PIN,_OUTPUT);
	DIO_SetPinDirection(GAS_PORT,GAS_ALARM_PIN,_OUTPUT);
	DIO_SetPinDirection(LIGHT_PORT,LIGHT_PIN,_OUTPUT);
	DIO_SetPinDirection(DOOR_PORT,DOOR_PIN,_OUTPUT);

	UART_init();
	ADC_INIT();
	TIMER1_FPWMinit();
}


void Control_GAS(void)
{
	Control_union.Stats_t.SMOKE = GAS_GetData();
	GAS_Alarm(Control_union.Stats_t.SMOKE);
}


void Control_Temperature(void)
{
	Temp_Display= LM35_Read_Temp();


	FAN_Control(Temp_Display, Global_Control[TASK_TEMP]);

}


void Control_Lights(void)
{
	if(Global_Control[TASK_LDR])
	{
		Control_union.Stats_t.LIGHTS = 1;
		u16 LDR_DATA = LDR_GetData();
		LIGHT_Control(LDR_DATA);

	}else
	{
		Control_union.Stats_t.LIGHTS = 0;
		LIGHT_Control(LIGHT_OFF);

	}
}


void Control_Door(void){
	if(Global_Control[TASK_DOOR]){
		Control_union.Stats_t.DOORS = 1;
		TIMER1_SetDutyCycle(1249);
	}
	else{
		Control_union.Stats_t.DOORS = 0;
		TIMER1_SetDutyCycle(388);
	}
}


void Control_Music(void){
	if(Global_Control[TASK_MUSIC]){
		Control_union.Stats_t.SOUND = 1;
		DIO_SetPinValue(MUSIC_PORT,MUSIC_PIN,_HIGH);
	}
	else{
		Control_union.Stats_t.SOUND = 0;
		DIO_SetPinValue(MUSIC_PORT,MUSIC_PIN,_LOW);
	}
}


void Control_ReceiveSendUART(){
	static u8 flag=1, flag2=0, flag3=0;
	u8 sent_Data = Control_union.Stats_REG;
	u8 rec_Data;
	if(flag == 0){
		if(flag2 == 1){
			UART_transmit_Char(sent_Data);
			flag2 = 0;
		}
		else{
			UART_transmit_Char(Temp_Display);
			flag2 = 1;
		}
		flag=1;
	}else{

		rec_Data = UART_recieve_Char();
		if(flag3 == 0){
			Global_Control[TASK_TEMP] = rec_Data;
			flag3 = 1;
		}
		else{
			Global_Control[TASK_LDR] = GET_BIT(rec_Data,0);
			Global_Control[TASK_DOOR] = GET_BIT(rec_Data,1);
			Global_Control[TASK_MUSIC] = GET_BIT(rec_Data,2) ;
			flag3 = 0;
		}
		flag=0;
	}
}
