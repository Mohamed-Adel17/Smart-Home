#ifndef HAL_LOGIN_LOGIN_H_
#define HAL_LOGIN_LOGIN_H_
/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "../../LIB/STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

#define CORRECT_ID  1
#define CORRECT_PASS 123

void Program_Init();
u8 Login_CheckInputs();
void Login_ChangePass();


#endif /* HAL_LOGIN_LOGIN_H_ */
