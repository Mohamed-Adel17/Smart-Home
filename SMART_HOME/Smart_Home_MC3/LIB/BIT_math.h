/*
 * BIT_math.h
 *
 * Created: 1/18/2021 5:50:54 AM
 *  Author: Mohamed Adel
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/

#define  SET_BIT(reg,bit)	 (reg |=  (1<<bit))
#define  CLEAR_BIT(reg,bit)	 (reg &= ~(1<<bit))
#define  TOGGLE_BIT(reg,bit) (reg ^=  (1<<bit))
#define  GET_BIT(reg,bit)    ((reg>>bit) & 1)

/*#define SET_BITS_VALUE(reg,start,len,value)	{\
												int i_counter=0,temp_start=start; \
												for(i_counter=0;i_counter<len;i_counter++)\
												{ \
													reg &= ~(1<<temp_start); \
													temp_start++; \
												} \
												reg |= (value<<start); \
											}
*/
#define SET_BITS_VALUE(reg,start,len,value) {\
												reg &= ~((u32)((1<<len)-1)<<start); \
												reg |= (value<<start); \
										    }
#endif /* BIT_MATH_H_ */										
