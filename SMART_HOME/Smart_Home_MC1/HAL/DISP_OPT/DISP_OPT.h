/*
 * DISP_OPT.h
 *
 *  Created on: Sep 6, 2022
 *      Author: aweso
 */

#ifndef HAL_DISP_OPT_DISP_OPT_H_
#define HAL_DISP_OPT_DISP_OPT_H_

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define AC 		1
#define LDR 	2
#define DOOR 	3
#define MUSIC 	4
#define RETURN 	5
#define YES 1
#define NO  2


void USER_MODE_Init();
void DISP_OPT_Init();
void DISP_OPT_AC();
void DISP_OPT_LDR();
void DISP_OPT_DOOR();
void DISP_OPT_MUSIC();
void Change_TempThreshold();
void Control_LDR(u8 On);
void Control_Music(u8 On);
void Control_Door(u8 Open);


void Display_Data_LDC2(void);
#endif /* HAL_DISP_OPT_DISP_OPT_H_ */
