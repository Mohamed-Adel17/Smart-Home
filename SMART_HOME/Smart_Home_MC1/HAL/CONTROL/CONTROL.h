/*
 * CONTROL.h
 *
 *  Created on: Sep 6, 2022
 *      Author: aweso
 */

#ifndef HAL_CONTROL_CONTROL_H_
#define HAL_CONTROL_CONTROL_H_


/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define DEFAULT_TEMP_THRESHOLD 30
#define TASK_TEMP 0
#define TASK_LDR 1
#define TASK_DOOR 2
#define TASK_MUSIC 3
#define TASK_SIZE 4

#define DISPLAY_SIZE 5
#define DISPLAY_TEMP 0
#define DISPLAY_LDR 1
#define DISPLAY_DOOR 2
#define DISPLAY_MUSIC 3
#define DISPLAY_SMOKE 4


union{
	struct TASKS{
		u8 LIGHTS :  1;
		u8 DOORS  :  1;
		u8 SOUND  :  1;
	}Tasks_t;
	u8 TASK_REG;
}Control_union;

void Change_TempThreshold();
void CONTROL_Music(u8 On);
void CONTROL_DOOR(u8 Open);
void CONTROL_LDR(u8 On);
void Control_SendUART();
void Control_ReceiveUART();
void CONTROL_Init();

#endif /* HAL_CONTROL_CONTROL_H_ */
