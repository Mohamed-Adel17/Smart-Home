#ifndef LCD_PRIVATE_H
#define LCD_PRIVATE_H

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define FUNCTION_SET 		0X38
#define DISPLAY_CONTROL 	0x0C
#define DISPLAY_CLEAR 		0x01
#define CURSOR_BLINK		0X0F
#define CURSOR_OFF		    0b00001100
#define RETURN_HOME			0x02
#define SHIFT_DISPLAY_RIGHT 0x1C
#define SHIFT_DISPLAY_LEFT  0x18
#define FIRST_LINE_ADDRESS  0x80
#define SECOND_LINE_ADDRESS 0xC0
#define THIRD_LINE_ADDRESS  0x94
#define FOURTH_LINE_ADDRESS 0xD4

#endif
