
#include "STD_TYPES.h"
#include "Scheduler.h"
#include "BIT_math.h"
#include "Timer2.h"

sTask SCH_TaskArr[SCH_MAX_TASKS];

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void SCH_init(void)
{
	u8 i=0;
	for (i = 0; i < SCH_MAX_TASKS; i++)
	  {
		SCH_Delete_Task(i);
	  }
	
	MTIMER2_voidInit();
	MTIMER2_voidTimer2OVSetCallBack(SCH_ISR);
}

void SCH_Start(void)
{
	SET_BIT(SREG,SREG_GIE);                /*ENABLE GLOBAL INTERRUPT*/
}



void SCH_ISR(void) /*the update function*/
{
	u8 Index;
	
	for(Index=0; Index < SCH_MAX_TASKS; Index++)
	{
		if (SCH_TaskArr[Index].ptrTask)
		{
		if(SCH_TaskArr[Index].Delay == 0)
		{
			SCH_TaskArr[Index].RunMe ++;
			if (SCH_TaskArr[Index].Period !=0)
			{
				SCH_TaskArr[Index].Delay = SCH_TaskArr[Index].Period;
			}
		}else 
		{
			SCH_TaskArr[Index].Delay -=1;
		}
		}
	}
}


u8 SCH_Add_Task(void (* pFunction)(),
				const u8 DELAY,
				const u16 PERIOD)
{
	u8 Index=0;

    while ((SCH_TaskArr[Index].ptrTask != 0) && (Index < SCH_MAX_TASKS))
		{
			Index++;
		}
	
	SCH_TaskArr[Index].ptrTask = pFunction;
	SCH_TaskArr[Index].Delay = DELAY;
	SCH_TaskArr[Index].Period = PERIOD;
	SCH_TaskArr[Index].RunMe = 0;
		
	return Index;	
}


void SCH_Delete_Task(u8 Index)
{
	SCH_TaskArr[Index].ptrTask =  0x0000;
	SCH_TaskArr[Index].Delay =  0;
	SCH_TaskArr[Index].Period = 0;
	SCH_TaskArr[Index].RunMe =  0;
}


void SCH_Delete_All_Tasks(void)
{
	for (u8 Index=0;Index<SCH_MAX_TASKS;Index++)
	{
		SCH_TaskArr[Index].ptrTask =  0x0000;
		SCH_TaskArr[Index].Delay =  0;
		SCH_TaskArr[Index].Period = 0;
		SCH_TaskArr[Index].RunMe =  0;
	}
}


void SCH_Dispatcher(void)
{
	u8 Index;
	for(Index=0; Index < SCH_MAX_TASKS; Index++)
	{
		if(SCH_TaskArr[Index].RunMe > 0)
		{
			(*SCH_TaskArr[Index].ptrTask)();
			SCH_TaskArr[Index].RunMe-=1;
			
			if(SCH_TaskArr[Index].Period ==0)
			{
				SCH_Delete_Task(Index);
			}
		}	
	}
}

void SCH_Stop(void)
{
	CLR_BIT(SREG,SREG_GIE);
}									 






