/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../HAL/LOGIN/LOGIN.h"
#include "../HAL/DISP_OPT/DISP_OPT.h"
#include "../MCAL/TIMER0/TIMER0_INTERFACE.h"
#include "../HAL/CONTROL/CONTROL.h"
#include "../HAL/LCD/LCD_INTERFACE.h"
#include "SPI_Interface.h"

/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

/*Main function of Application layer*/
int main(){

	Program_Init(); /*All required initializations*/
	while(1){
		/*Check if user entered ID and Password correctly*/
		if(Login_CheckInputs()){
			USER_MODE_Init(); /*To enter the main screen to choose: Display options - Change password - Logout*/
		}
	}
	return 0;
}

