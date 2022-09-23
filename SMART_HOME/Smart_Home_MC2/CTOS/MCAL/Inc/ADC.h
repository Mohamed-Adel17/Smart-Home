/*
 * ADC.h
 *
 * Created: 07/02/2021 03:29:18 م
 *  Author: Mu
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "STD_TYPES.h"

#define	ACSR_R			*(volatile u8 *)  (0x28)
#define	ADMUX_R			*(volatile u8 *)  (0x27)
#define	ADCSRA_R		*(volatile u8 *)  (0x26)
#define	ADCH_R			*(volatile u8 *)  (0x25)
#define	ADCL_R			*(volatile u8 *)  (0x24)

#define	ADC_R			*(volatile u16 *)  (0x24)

#define SFIOR_R			*(volatile u8 *)  (0x50)


#define REFS0_R 6
#define REFS1_R 7
#define ADLAR_R 5
#define MUX4_R 4
#define MUX3_R 3
#define MUX2_R 2
#define MUX1_R 1
#define MUX0_R 0


#define ADEN_R   7
#define ADSC_R	 6
#define ADATE_R	 5
#define ADIF_R	 4
#define ADIE_R 	 3
#define	ADPS2_R  2
#define	ADPS1_R	 1
#define	ADPS0_R	 0


#define	ADTS2_R 7
#define	ADTS1_R 6
#define	ADTS0_R 5



void ADC_INIT(void);

u16 ADC_u16ReadData(u8 channel);

f32 ADC_f32ReadVoltage(u8 channel);


#endif /* ADC_H_ */
