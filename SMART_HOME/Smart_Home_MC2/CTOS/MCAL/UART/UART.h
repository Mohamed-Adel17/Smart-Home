

#ifndef UART_H_
#define UART_H_
#include "../../LIB/STD_TYPES.h"
#define NONE 0
#define EVEN 1
#define ODD 2

void UART_init(void);

void UART_transmit_Char(u16 data);
u8 UART_recieve_Char(void);

void UART_transmit_String(u8 data[]);

#endif /* UART_H_ */
