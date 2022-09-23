#ifndef TIMER2_H_
#define TIMER2_H_
#include "../../LIB/STD_TYPES.h"
#include "TIMER2_PRIVATE.h"
/****************************************************************
 name           : 	MTIMER2_voidInit
 description    : 	Sets Timer 2 mode
 parameter      :   None
 options        :   Set from config file
 return         : 	none
****************************************************************/
void MTIMER2_voidInit(void);

/****************************************************************
 name           : 	MTIMER2_voidSetDuty
 description    : 	Sets Duty Cycle
 parameter      :   Copy_u8DutyCycle
 return         : 	none
****************************************************************/
void MTIMER2_voidSetDuty(u8 Copy_u8DutyCycle);

/****************************************************************
 name           : 	MTIMER2_voidTimer0CTCSetCallBack
 description    : 	Sets ISR function for on compare match mode
 parameter      :   Copy_pvCallBackFunc
 return         : 	none
****************************************************************/
void MTIMER2_voidTimer2CTCSetCallBack(void (*Copy_pvCallBackFunc)(void));

/****************************************************************
 name           : 	MTIMER2_voidTimer0OVSetCallBack
 description    : 	Sets ISR function for timer overflow
 parameter      :   Copy_pvCallBackFunc
 return         : 	none
****************************************************************/
void MTIMER2_voidTimer2OVSetCallBack(void (*Copy_pvCallBackFunc)(void));
void MTIMER2_voidSetBusyWait(u16 Copy_u8WaitTime);
#endif
