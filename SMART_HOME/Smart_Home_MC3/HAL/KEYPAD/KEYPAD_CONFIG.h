#ifndef KEYPAD_CONFIG_H
#define KEYPAD_CONFIG_H

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define KPD_PORT		_PORTC
#define KPD_ARR_VAL     { 1 , 2 , 3 },{ 4 , 5 , 6 },{ 7 , 8 , 9 },{ 'd' , 0 , 'k' }
#define NO_PRESSED_KEY  0xFF

#define KPD_COL0_PIN	_PIN0
#define KPD_COL1_PIN	_PIN1
#define KPD_COL2_PIN	_PIN2

#define KPD_ROW0_PIN	_PIN3
#define KPD_ROW1_PIN	_PIN4
#define KPD_ROW2_PIN	_PIN5
#define KPD_ROW3_PIN	_PIN6


#endif
