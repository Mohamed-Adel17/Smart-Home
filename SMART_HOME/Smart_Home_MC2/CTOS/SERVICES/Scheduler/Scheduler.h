/*
 * Scheduler.h
 *
 * Created: 8/26/2021 12:22:25 AM
 *  Author: Mohamed Adel
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_

/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "STD_TYPES.h"


/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define SCH_MAX_TASKS 10



void SCH_init(void);
void SCH_Start(void);
void SCH_Stop(void);
u8 SCH_Add_Task(void (* pFunction)(),
const u8 DELAY,
const u16 PERIOD);

void SCH_Delete_Task(u8 Index);
void SCH_Dispatcher(void);
void SCH_Delete_All_Tasks(void);
void SCH_ISR(void);

typedef struct {
	
	void (*ptrTask)(void);
	u8 Delay;
	u8 RunMe;
	u16 Period;
	
}sTask;

#endif /* SCHEDULER_H_ */
