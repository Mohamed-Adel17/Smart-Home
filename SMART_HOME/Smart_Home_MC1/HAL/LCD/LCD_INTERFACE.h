#ifndef LCD_INTEFACE_H
#define LCD_INTEFACE_H

/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../../LIB/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define LCD_1 1
#define LCD_2 2

#define DELAY_LCD 350


#define DATA_CHECK(x)   x ? (u8*)"ON " : (u8*)"OFF"



void LCD_WriteCommand(u8 Command,u8 LCD_Number);
void LCD_WriteCharData(u8 Data,u8 LCD_Number);
void LCD_WriteIntData(s32 Data,u8 LCD_Number);
void LCD_WriteStringData(u8 *Data,u8 LCD_Number);
void LCD_GoToPosition(u8 X_Position, u8 Y_Position,u8 LCD_Number);
void LCD_Init(u8 LCD_Number);
u8* IntToString(s32 anInteger,u8 *str);
s32 LCD_ReadInput(u8 LCD_Number);

#endif
