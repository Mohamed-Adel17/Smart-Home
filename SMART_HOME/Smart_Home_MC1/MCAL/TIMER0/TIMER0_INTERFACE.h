#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_

/****************************************************************
 name           : 	MTIMER0_voidInit                        
 description    : 	Sets Timer 0 mode  		                                         
 parameter      :   None		     
 options        :   Set from config file  
 return         : 	none                             
****************************************************************/
void MTIMER0_voidInit();

/****************************************************************
 name           : 	MTIMER0_voidSetDuty                        
 description    : 	Sets Duty Cycle 		                                         
 parameter      :   Copy_u8DutyCycle		       
 return         : 	none                             
****************************************************************/
void MTIMER0_voidSetDuty(u8 Copy_u8DutyCycle);

/****************************************************************
 name           : 	MTIMER0_voidTimer0CTCSetCallBack                        
 description    : 	Sets ISR function for on compare match mode		                                         
 parameter      :   Copy_pvCallBackFunc		       
 return         : 	none                             
****************************************************************/
void MTIMER0_voidTimer0CTCSetCallBack(void (*Copy_pvCallBackFunc)(void));

/****************************************************************
 name           : 	MTIMER0_voidTimer0OVSetCallBack                       
 description    : 	Sets ISR function for timer overflow  		                                         
 parameter      :   Copy_pvCallBackFunc		       
 return         : 	none                             
****************************************************************/
void MTIMER0_voidTimer0OVSetCallBack(void (*Copy_pvCallBackFunc)(void));
void MTIMER0_voidSetBusyWait(u16 Copy_u8WaitTime);
#endif 
