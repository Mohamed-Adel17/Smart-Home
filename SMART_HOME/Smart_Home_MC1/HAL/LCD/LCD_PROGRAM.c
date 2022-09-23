/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../../MCAL/DIO/DIO_INTERFACE.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TIMER0/TIMER0_INTERFACE.h"
#include "LCD_CONFIG.h"
#include "LCD_PRIVATE.h"
#include "LCD_INTERFACE.h"

#include "SPI_Interface.h"



/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void LCD_WriteCommand(u8 Command,u8 LCD_Number){
	if(LCD_Number == 1){
		DIO_SetPinValue(CONTROL_PORT_1, RS_PIN_1, DIO_LOW); /*For RS*/

		DIO_SetPinValue(CONTROL_PORT_1, RW_PIN_1, DIO_LOW);
		DIO_SetPinValue(CONTROL_PORT_1, ENABLE_PIN_1, DIO_HIGH);
		DIO_SetPortValue(DATA_PORT_1, Command);
		DIO_SetPinValue(CONTROL_PORT_1, ENABLE_PIN_1, DIO_LOW);/*Set Enable*/
		MTIMER0_voidSetBusyWait(5);
	}
	else if(LCD_Number == 2){
		DIO_SetPinValue(CONTROL_PORT_2, RS_PIN_2, DIO_LOW); /*For RS*/

		DIO_SetPinValue(CONTROL_PORT_2, RW_PIN_2, DIO_LOW);
		DIO_SetPinValue(CONTROL_PORT_2, ENABLE_PIN_2, DIO_HIGH);
		DIO_SetPortValue(DATA_PORT_2, Command);
		DIO_SetPinValue(CONTROL_PORT_2, ENABLE_PIN_2, DIO_LOW);/*Set Enable*/
		MTIMER0_voidSetBusyWait(5);
	}
}

void LCD_WriteCharData(u8 Data,u8 LCD_Number){
	if(LCD_Number == 1){
		DIO_SetPinValue(CONTROL_PORT_1, RS_PIN_1, DIO_HIGH); /*For RS*/

		/*RW is grounded*/
		DIO_SetPinValue(CONTROL_PORT_1, RW_PIN_1, DIO_LOW);
		DIO_SetPinValue(CONTROL_PORT_1, ENABLE_PIN_1, DIO_HIGH);
		DIO_SetPortValue(DATA_PORT_1, Data);
		DIO_SetPinValue(CONTROL_PORT_1, ENABLE_PIN_1, DIO_LOW);/*Set Enable*/
		//MTIMER0_voidSetBusyWait(5);
	}

	else if(LCD_Number == 2){
		DIO_SetPinValue(CONTROL_PORT_2, RS_PIN_2, DIO_HIGH); /*For RS*/

		/*RW is grounded*/
		DIO_SetPinValue(CONTROL_PORT_2, RW_PIN_2, DIO_LOW);
		DIO_SetPinValue(CONTROL_PORT_2, ENABLE_PIN_2, DIO_HIGH);
		DIO_SetPortValue(DATA_PORT_2, Data);
		DIO_SetPinValue(CONTROL_PORT_2, ENABLE_PIN_2, DIO_LOW);/*Set Enable*/
		//MTIMER0_voidSetBusyWait(5);
	}

}

void LCD_WriteStringData(u8 *Data, u8 LCD_Number){
	u32 counter=0;
	while(Data[counter] != '\0'){
		LCD_WriteCharData(Data[counter],LCD_Number);
		counter++;
	}
}

void LCD_GoToPosition(u8 X_Position, u8 Y_Position,u8 LCD_Number){
	u8 Local_Address = FIRST_LINE_ADDRESS;

	if(X_Position == 0){
		Local_Address = FIRST_LINE_ADDRESS + Y_Position;
	}
	else if(X_Position == 1){
		Local_Address = SECOND_LINE_ADDRESS + Y_Position;
	}
	else if(X_Position == 2){
		Local_Address = THIRD_LINE_ADDRESS + Y_Position;
	}
	else if(X_Position == 3){
		Local_Address = FOURTH_LINE_ADDRESS + Y_Position;
	}

	SET_BIT(Local_Address,7); /*You can also just OR / add with 0x80 (128) to set the the MSB*/
	LCD_WriteCommand(Local_Address,LCD_Number);
}

void LCD_Init(u8 LCD_Number){
	u8 Cursor_Control = 0;
	if(LCD_Number == 1){
		DIO_SetPinDirection(CONTROL_PORT_1, RS_PIN_1, DIO_OUTPUT); /*RS*/
		DIO_SetPinDirection(CONTROL_PORT_1, ENABLE_PIN_1, DIO_OUTPUT);/*Enable*/
		DIO_SetPinDirection(CONTROL_PORT_1, RW_PIN_1, DIO_OUTPUT);/*RW*/
		DIO_SetPortDirection(DATA_PORT_1, 0xFF);
		Cursor_Control = CURSOR_BLINK;
	}
	else if(LCD_Number == 2){
		DIO_SetPinDirection(CONTROL_PORT_2, RS_PIN_2, DIO_OUTPUT); /*RS*/
		DIO_SetPinDirection(CONTROL_PORT_2, ENABLE_PIN_2, DIO_OUTPUT);/*Enable*/
		DIO_SetPinDirection(CONTROL_PORT_2, RW_PIN_2, DIO_OUTPUT);/*RW*/
		DIO_SetPortDirection(DATA_PORT_2, 0xFF);
		Cursor_Control = CURSOR_OFF;
	}

	MTIMER0_voidSetBusyWait(35);
	LCD_WriteCommand(FUNCTION_SET,LCD_Number);
	MTIMER0_voidSetBusyWait(1);
	LCD_WriteCommand(Cursor_Control,LCD_Number);
	MTIMER0_voidSetBusyWait(1);
	LCD_WriteCommand(DISPLAY_CLEAR,LCD_Number);
	MTIMER0_voidSetBusyWait(2);
	LCD_WriteCommand(0x06,LCD_Number);
}

u8* IntToString(s32 anInteger,u8 *str){
	u32 flag = 0;
	u32 i = INT_TO_STRING_ARR_SIZE - 1;
	str[i--] = '\0';
	if (anInteger < 0) {
		flag = 1;
		anInteger = -anInteger;
	}
	while (anInteger != 0) {
		str[i--] = (anInteger % 10) + '0';
		anInteger /= 10;
	}
	if (flag){
		str[i--] = '-';
	}
	i++;
	return str + i;

}

void LCD_WriteIntData(s32 Data,u8 LCD_Number){
	if(Data){
		u8 arr[INT_TO_STRING_ARR_SIZE];
		//sprintf(str,"%d",Data);
		u8 *str = IntToString(Data,arr);
		LCD_WriteStringData(str,LCD_Number);
	}
	else{
		LCD_WriteCharData('0',LCD_Number);
	}

	//MTIMER0_voidSetBusyWait(5);
}

/*
void LCD_WriteFloatData(f32 Data){
	u8 arr[INT_TO_STRING_ARR_SIZE];
	s32 number = (s32) (Data * 100);
	//sprintf(str,"%d",number);
	u8 *str = IntToString(number,arr);
	u32 counter=0;
	u32 counter2=0;
	while(str[counter] != '\0'){
		counter++;
	}
	counter -= 2;
	if(!counter){
		LCD_WriteCharData('0');
	}
	while(str[counter2] != '\0'){
		if(counter2 == counter){
			LCD_WriteCharData('.');
		}
		LCD_WriteCharData(str[counter2]);
		counter2++;
	}
	MTIMER0_voidSetBusyWait(5);
}


void LCD_DisplaySpecialChar(u8 *char_ptr,u8 CGRam_index,u8 row,u8 column){
	LCD_GoToPosition(row,column);
	LCD_WriteCharData(CGRam_index);
	u8 address = 0;
	u8 index = 0;
	if(CGRam_index < 8){
		address = CGRam_index * 8;
		SET_BIT(address,6);
		CLR_BIT(address,7);
		LCD_WriteCommand(address);
		for(index = 0; index < 8; index++){
			LCD_WriteCharData(char_ptr[index]);
		}
	}
	LCD_WriteCommand(RETURN_HOME);
}
 */

s32 LCD_ReadInput(u8 LCD_Number){
	u8 Local_u8PressedKey = 0xFF;
	s32 Local_input;
	u8 counter = 0;
	while(1){
		Local_u8PressedKey = SPI_Recieve();/*receive KP input*/
			if(Local_u8PressedKey == 'k' && counter != 0){
				break;

			}
			else if(Local_u8PressedKey != 'k' && Local_u8PressedKey != 'd'){
				if(counter != 0){
					Local_input *= 10;
					Local_input += Local_u8PressedKey;
				}
				else{
					Local_input = Local_u8PressedKey;
				}
				counter++;
				LCD_WriteIntData(Local_u8PressedKey,LCD_Number);


			}
			else if(counter != 0 && Local_u8PressedKey == 'd'){
				LCD_WriteCommand(0x10,LCD_Number);
				LCD_WriteCharData(' ',LCD_Number);
				LCD_WriteCommand(0x10,LCD_Number);
				Local_input /= 10;
				counter--;

			}

		}
	return Local_input;
}


