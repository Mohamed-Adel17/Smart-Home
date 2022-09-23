#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/


#include "BIT_MATH.h"
#include "STD_TYPES.h"

/**********************************************************************************************************************
 *  GLOBAL MACROS
 *********************************************************************************************************************/

/* SPI Control Register */
#define SPCR       (*(volatile unsigned char*)0x2D)
/* SPI Status Register */
#define SPSR       (*(volatile unsigned char*)0x2E)
/* SPI I/O Data Register */
#define SPDR       (*(volatile unsigned char*)0x2F)

/* SPI Status Register - SPSR */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0

/* SPI Control Register - SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0


void SPI_InitMaster(void);
void SPI_InitSlave(void);
u8 SPI_SendRecieve(u8 data);
void SPI_Send(u8 data);
u8 SPI_Recieve(void);
#endif /* SPI_INTERFACE_H_ */
