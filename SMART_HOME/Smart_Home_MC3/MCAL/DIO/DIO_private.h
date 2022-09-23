#ifndef DIO_private_H
#define DIO_private_H
#include "STD_TYPES.h"

#define PORTA_R  *((volatile u8*)0x3B)
#define DDRA_R   *((volatile u8*)0x3A)
#define PINA_R   *((volatile u8*)0x39)
#define PORTB_R  *((volatile u8*)0x38)
#define DDRB_R   *((volatile u8*)0x37)
#define PINB_R   *((volatile u8*)0x36)
#define PORTC_R  *((volatile u8*)0x35)
#define DDRC_R   *((volatile u8*)0x34)
#define PINC_R   *((volatile u8*)0x33)
#define PORTD_R  *((volatile u8*)0x32)
#define DDRD_R   *((volatile u8*)0x31)
#define PIND_R   *((volatile u8*)0x30)

#endif