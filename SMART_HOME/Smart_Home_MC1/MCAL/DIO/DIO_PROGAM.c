/**********************************************************************************************************************
 *  HEADER FILES INCLUSION
 *********************************************************************************************************************/

#include "DIO_CONFIG.h"
#include "DIO_PRIVATE.h"
#include "DIO_INTERFACE.h"
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


/**********************************************************************************************************************
 *  Functions Definitions
 *********************************************************************************************************************/

void DIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction){

	switch(Port){

	case PORTA:
		if(Direction == DIO_INPUT){
			CLR_BIT(DDRA_REG,Pin);
		}
		else if(Direction == DIO_OUTPUT){
			SET_BIT(DDRA_REG,Pin);
		}
		break;

	case PORTB:
		if(Direction == DIO_INPUT){
			CLR_BIT(DDRB_REG,Pin);
		}
		else if(Direction == DIO_OUTPUT){
			SET_BIT(DDRB_REG,Pin);
		}
		break;

	case PORTC:
		if(Direction == DIO_INPUT){
			CLR_BIT(DDRC_REG,Pin);
		}
		else if(Direction == DIO_OUTPUT){
			SET_BIT(DDRC_REG,Pin);
		}
		break;

	case PORTD:
		if(Direction == DIO_INPUT){
			CLR_BIT(DDRD_REG,Pin);
		}
		else if(Direction == DIO_OUTPUT){
			SET_BIT(DDRD_REG,Pin);
		}
		break;

	default:
		break;
	}

}

void DIO_SetPinValue(u8 Port, u8 Pin, u8 Value){
	switch(Port){
	case PORTA:
		if(Value == DIO_LOW){
			CLR_BIT(PORTA_REG,Pin);
		}
		else if(Value == DIO_HIGH){
			SET_BIT(PORTA_REG,Pin);
		}
		break;

	case PORTB:
		if(Value == DIO_LOW){
			CLR_BIT(PORTB_REG,Pin);
		}
		else if(Value == DIO_HIGH){
			SET_BIT(PORTB_REG,Pin);
		}
		break;

	case PORTC:
		if(Value == DIO_LOW){
			CLR_BIT(PORTC_REG,Pin);
		}
		else if(Value == DIO_HIGH){
			SET_BIT(PORTC_REG,Pin);
		}
		break;

	case PORTD:
		if(Value == DIO_LOW){
			CLR_BIT(PORTD_REG,Pin);
		}
		else if(Value == DIO_HIGH){
			SET_BIT(PORTD_REG,Pin);
		}
		break;

	default:
		break;
	}
}

u8 DIO_GetPinValue(u8 Port, u8 Pin){
	switch(Port){
	case PORTA:
		return GET_BIT(PINA_REG,Pin);
	case PORTB:
		return GET_BIT(PINB_REG,Pin);
	case PORTC:
		return GET_BIT(PINC_REG,Pin);
	case PORTD:
		return GET_BIT(PIND_REG,Pin);
	default:
		return 2;
	}
}

void DIO_SetPortDirection(u8 Port,u8 Direction){
	switch(Port){
	case PORTA:
		DDRA_REG = Direction;
		break;
	case PORTB:
		DDRB_REG = Direction;
		break;
	case PORTC:
		DDRC_REG = Direction;
		break;
	case PORTD:
		DDRD_REG = Direction;
		break;
	}
}
void DIO_SetPortValue(u8 Port,u8 Value){
	switch(Port){
	case PORTA:
		PORTA_REG = Value;
		break;
	case PORTB:
		PORTB_REG = Value;
		break;
	case PORTC:
		PORTC_REG = Value;
		break;
	case PORTD:
		PORTD_REG = Value;
		break;
	}

}

u8 DIO_GetPortValue(u8 Port){
	switch(Port){
	case PORTA:
		return PORTA_REG;
	case PORTB:
		return PORTB_REG;
	case PORTC:
		return PORTC_REG;
	case PORTD:
		return PORTD_REG;
	default:
		return 0x10;
	}
}
