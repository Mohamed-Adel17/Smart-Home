/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "STD_TYPES.h"
#include "Program_Flow.h"
#include "Scheduler.h"
/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/
 
 /*Main function of Application layer*/
int main(void)
{
	SCH_init();
	HW_Init();

	SCH_Add_Task(Control_ReceiveSendUART,0,150);
	SCH_Add_Task(Control_GAS,1,5);
	SCH_Add_Task(Control_Temperature,2,7);
	SCH_Add_Task(Control_Lights,3,20);
	SCH_Add_Task(Control_Door,4,20);
	SCH_Add_Task(Control_Music,5,20);

	SCH_Start();
	
/*Main super loop*/
	while(1)
	{
		SCH_Dispatcher();
	}
}


