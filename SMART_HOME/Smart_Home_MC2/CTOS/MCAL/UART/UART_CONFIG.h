/*
 * UART_CONFIG.h
 *
 *  Created on: Sep 7, 2022
 *      Author: aweso
 */

#ifndef MCAL_UART_UART_CONFIG_H_
#define MCAL_UART_UART_CONFIG_H_

#include "../../LIB/STD_TYPES.h"

#define NONE 0
#define Asynchronous_Mode 0
#define F_1MHz 1000000
#define BaudRate_9600 9600
#define Data_8Bits 8
#define Stop_Bits_one 1



typedef struct {

	u8 Mode;
	u8 Parity;
	u8 Stop_Bits;
	u8 Data_Bits;
	u16 baud_rate;
	u64 Foc;

}uart_t;


#endif /* MCAL_UART_UART_CONFIG_H_ */
