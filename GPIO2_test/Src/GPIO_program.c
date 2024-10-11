/*
 * GPIO_program.c
 *
 *  Created on: Sep 24, 2024
 *      Author: user
 */

#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../Inc/GPIO_config.h"
#include "../Inc/GPIO_interface.h"
#include "../Inc/GPIO_private.h"
#include "../Inc/GPIO_register.h"

u8 MGPIO_u8SetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinMode)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		if(Copy_u8Pin<=GPIO_PIN7)
		{
			GPIOA_CRL &= (CTRL_MASK << (Copy_u8Pin *_4BIT_SHIFT));
			GPIOA_CRL |= ((Copy_u8PinMode)<< (Copy_u8Pin *_4BIT_SHIFT));
		}
		else if(Copy_u8Pin<=GPIO_PIN15)
		{
			GPIOA_CRH &= (CTRL_MASK << (Copy_u8Pin *_4BIT_SHIFT));
			GPIOA_CRH |= ((Copy_u8PinMode)<< (Copy_u8Pin *_4BIT_SHIFT));

		}
		else
			Local_u8ErrorState = NOTOK;
		break;
	case GPIO_PORTB:
		if(Copy_u8Pin<=GPIO_PIN7)
		{
			GPIOB_CRL &= (CTRL_MASK << (Copy_u8Pin *_4BIT_SHIFT));
			GPIOB_CRL |= ((Copy_u8PinMode)<< (Copy_u8Pin *_4BIT_SHIFT));
		}
		else if(Copy_u8Pin<=GPIO_PIN15)
		{
			GPIOB_CRH &= (CTRL_MASK << (Copy_u8Pin *_4BIT_SHIFT));
			GPIOB_CRH |= ((Copy_u8PinMode)<< (Copy_u8Pin *_4BIT_SHIFT));
		}
		else
			Local_u8ErrorState = NOTOK;
		break;
	case GPIO_PORTC :
		if(Copy_u8Pin<=GPIO_PIN7)
		{
			GPIOC_CRL &= (CTRL_MASK << (Copy_u8Pin *_4BIT_SHIFT));
			GPIOC_CRL |= ((Copy_u8PinMode)<< (Copy_u8Pin *_4BIT_SHIFT));
		}
		else if(Copy_u8Pin<=GPIO_PIN15)
		{
			GPIOC_CRH &= (CTRL_MASK << (Copy_u8Pin *_4BIT_SHIFT));
			GPIOC_CRH |= ((Copy_u8PinMode)<< (Copy_u8Pin *_4BIT_SHIFT));

		}
		else
			Local_u8ErrorState = NOTOK;
		break;
	default:
		Local_u8ErrorState = NOTOK;


	}

	return Local_u8ErrorState;
}

u8 MGPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinValue)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		switch(Copy_u8PinValue)
		{
		case GPIO_PIN_HIGH:
			SET_BIT(GPIOA_ODR,Copy_u8Pin);
			break;
		case GPIO_PIN_LOW:
			CLR_BIT(GPIOA_ODR,Copy_u8Pin);
			break;
		default:
			Local_u8ErrorState = NOTOK;
		}
		break;
		case GPIO_PORTB:
			switch(Copy_u8PinValue)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOB_ODR,Copy_u8Pin);
				break;
			case GPIO_PIN_LOW:
				CLR_BIT(GPIOB_ODR,Copy_u8Pin);
				break;
			default:
				Local_u8ErrorState = NOTOK;
			}
			break;

			case GPIO_PORTC:
				switch(Copy_u8PinValue)
				{
				case GPIO_PIN_HIGH:
					SET_BIT(GPIOC_ODR,Copy_u8Pin);
					break;
				case GPIO_PIN_LOW:
					CLR_BIT(GPIOC_ODR,Copy_u8Pin);
					break;
				default:
					Local_u8ErrorState = NOTOK;
				}
				break;
				default:Local_u8ErrorState = NOTOK;
	}
	return Local_u8ErrorState;
}
u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_pu8PinValue)
{
	u8 Local_u8ErrorState = OK;
	if(Copy_pu8PinValue != NULL )
	{
		switch(Copy_u8Port)
		{
		case GPIO_PORTA: *Copy_pu8PinValue = GET_BIT(GPIOA_IDR,Copy_u8Pin);break;
		case GPIO_PORTB: *Copy_pu8PinValue = GET_BIT(GPIOB_IDR,Copy_u8Pin);break;
		case GPIO_PORTC:*Copy_pu8PinValue = GET_BIT(GPIOC_IDR,Copy_u8Pin);break;
		default: Local_u8ErrorState = NOTOK;
		}
	}
	else
		Local_u8ErrorState = NULL_POINTER;

	return Local_u8ErrorState;
}

u8 MGPIO_u8WritePinAccess(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8State)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		switch(Copy_u8State)
		{
		case GPIO_PIN_HIGH:
			SET_BIT(GPIOA_BSRR,Copy_u8Pin);
			break;
		case GPIO_PIN_LOW:
			SET_BIT(GPIOA_BRR,(Copy_u8Pin));
			break;
		default:
			Local_u8ErrorState = NOTOK;
		}
		break;
		case GPIO_PORTB:
			switch(Copy_u8State)
			{
			case GPIO_PIN_HIGH:
				SET_BIT(GPIOA_BSRR,Copy_u8Pin);
				break;
			case GPIO_PIN_LOW:
				SET_BIT(GPIOA_BRR,(Copy_u8Pin));
				break;
			default:
				Local_u8ErrorState = NOTOK;
			}
			break;

			case GPIO_PORTC:
				switch(Copy_u8State)
				{
				case GPIO_PIN_HIGH:
					SET_BIT(GPIOA_BSRR,Copy_u8Pin);
					break;
				case GPIO_PIN_LOW:
					SET_BIT(GPIOA_BRR,(Copy_u8Pin));
					break;
				default:
					Local_u8ErrorState = NOTOK;
				}
				break;
				default:Local_u8ErrorState = NOTOK;
	}
	return Local_u8ErrorState;
}

u8 MGPIO_u8SetPortMode8_Pin(u8 Copy_u8Port,u8 Copy_u8BytePos,u8 Copy_u8PortMode)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8PinCounter = 0;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		switch(Copy_u8BytePos)
		{
		case GPIO_PORT_LOW_BYTE:
			GPIOA_CRL &= CTRL_8BIT_MASK;
			for(Local_u8PinCounter=0;Local_u8PinCounter<8;Local_u8PinCounter++)
			{
				GPIOA_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
			}
			break;
		case GPIO_PORT_HIGH_BYTE:
			GPIOA_CRH &= CTRL_8BIT_MASK;
			for(Local_u8PinCounter=0;Local_u8PinCounter<8;Local_u8PinCounter++)
			{
				GPIOA_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
			}

			break;
		default:Local_u8ErrorState = NOTOK;
		}

		break;
		case GPIO_PORTB:
			switch(Copy_u8BytePos)
			{
			case GPIO_PORT_LOW_BYTE:

				GPIOB_CRL &= CTRL_8BIT_MASK;
				for(Local_u8PinCounter=0;Local_u8PinCounter<8;Local_u8PinCounter++)
				{
					GPIOB_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
				}

				break;
			case GPIO_PORT_HIGH_BYTE:

				GPIOB_CRH &= CTRL_8BIT_MASK;
				for(Local_u8PinCounter=0;Local_u8PinCounter<8;Local_u8PinCounter++)
				{
					GPIOB_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
				}

				break;
			default:Local_u8ErrorState = NOTOK;
			}

			break;
			case GPIO_PORTC:
				switch(Copy_u8BytePos)
				{
				case GPIO_PORT_LOW_BYTE:
					GPIOC_CRL &= CTRL_8BIT_MASK;
					for(Local_u8PinCounter=0;Local_u8PinCounter<8;Local_u8PinCounter++)
					{
						GPIOC_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
					}

					break;
				case GPIO_PORT_HIGH_BYTE:
					GPIOC_CRH &= CTRL_8BIT_MASK;
					for(Local_u8PinCounter=0;Local_u8PinCounter<8;Local_u8PinCounter++)
					{
						GPIOC_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
					}
					break;
				default:Local_u8ErrorState = NOTOK;
				}

				break;
				default:
					Local_u8ErrorState = NOTOK;
	}

	return Local_u8ErrorState;
}

u8 MGPIO_u8SetPortValue8_Pin(u8 Copy_u8Port,u8 Copy_u8BytePos,u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		switch(Copy_u8BytePos)
		{
		case GPIO_PORT_LOW_BYTE:
			GPIOA_ODR &= OUT_MASK_LOWER;
			GPIOA_ODR |= Copy_u8PortValue;
			break;
		case GPIO_PORT_HIGH_BYTE:
			GPIOA_ODR &= OUT_MASK_HIGHER;
			GPIOA_ODR |= Copy_u8PortValue<<_8BIT_SHIFT;
			break;
		}
		break;
		case GPIO_PORTB:
			switch(Copy_u8BytePos)
			{
			case GPIO_PORT_LOW_BYTE:
				GPIOB_ODR &= OUT_MASK_LOWER;
				GPIOB_ODR |= Copy_u8PortValue;
				break;
			case GPIO_PORT_HIGH_BYTE:
				GPIOB_ODR &= OUT_MASK_HIGHER;
				GPIOB_ODR |= Copy_u8PortValue<<_8BIT_SHIFT;
				break;
			}
			break;
			case GPIO_PORTC:
				switch(Copy_u8BytePos)
				{
				case GPIO_PORT_LOW_BYTE:
					GPIOC_ODR &= OUT_MASK_LOWER;
					GPIOC_ODR |= Copy_u8PortValue;
					break;
				case GPIO_PORT_HIGH_BYTE:
					GPIOC_ODR &= OUT_MASK_HIGHER;
					GPIOC_ODR |= Copy_u8PortValue<<_8BIT_SHIFT;
					break;
				}
				break;
	}

	return Local_u8ErrorState;

}
//**
u8 MGPIO_u8SetPortMode4_Pin(u8 Copy_u8Port,u8 Copy_u8NibblePos,u8 Copy_u8PortMode)
{
	u8 Local_u8ErrorState = OK;
	u8 Local_u8PinCounter = 0;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		switch(Copy_u8NibblePos)
		{
		case GPIO_LOW_BYTE_LOWER_Nibble:
			GPIOA_CRL &=  OUT_MASK_LOWER;
			for(Local_u8PinCounter=0;Local_u8PinCounter<4;Local_u8PinCounter++)
			{
				GPIOA_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
			}
			break;
		case GPIO_LOW_BYTE_UP_Nibble:
			GPIOA_CRL &= OUT_MASK_HIGHER;
			for(Local_u8PinCounter=4;Local_u8PinCounter<8;Local_u8PinCounter++)
			{
				GPIOA_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
			}
			break;
		case GPIO_HIGH_BYTE_LOWER_Nibble:
			GPIOA_CRH &= OUT_MASK_LOWER;
			for(Local_u8PinCounter=0;Local_u8PinCounter<4;Local_u8PinCounter++)
			{
				GPIOA_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
			}
			break;
		case GPIO_HIGH_BYTE_UP_Nibble:
			GPIOA_CRH &= OUT_MASK_HIGHER;
			for(Local_u8PinCounter=4;Local_u8PinCounter<8;Local_u8PinCounter++)
			{
				GPIOA_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
			}
			break;
		default: Local_u8ErrorState = NOTOK;
		}

		break;
		case GPIO_PORTB:
			switch(Copy_u8NibblePos)
			{
			case GPIO_LOW_BYTE_LOWER_Nibble:
				GPIOB_CRL &= OUT_MASK_LOWER;
				for(Local_u8PinCounter=0;Local_u8PinCounter<4;Local_u8PinCounter++)
				{
					GPIOB_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
				}
				break;
			case GPIO_LOW_BYTE_UP_Nibble:
				GPIOB_CRL &= OUT_MASK_HIGHER;
				for(Local_u8PinCounter=4;Local_u8PinCounter<8;Local_u8PinCounter++)
				{
					GPIOB_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
				}
				break;
			case GPIO_HIGH_BYTE_LOWER_Nibble:
				GPIOB_CRH &= OUT_MASK_LOWER;
				for(Local_u8PinCounter=0;Local_u8PinCounter<4;Local_u8PinCounter++)
				{

					GPIOB_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
				}
				break;
			case GPIO_HIGH_BYTE_UP_Nibble:
				GPIOB_CRH &= OUT_MASK_HIGHER;
				for(Local_u8PinCounter=4;Local_u8PinCounter<8;Local_u8PinCounter++)
				{
					GPIOB_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
				}
				break;
			default: Local_u8ErrorState = NOTOK;
			}

			break;
			case GPIO_PORTC:
				switch(Copy_u8NibblePos)
				{
				case GPIO_LOW_BYTE_LOWER_Nibble:
					GPIOC_CRL &= OUT_MASK_LOWER;
					for(Local_u8PinCounter=0;Local_u8PinCounter<4;Local_u8PinCounter++)
					{

						GPIOC_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
					}
					break;
				case GPIO_LOW_BYTE_UP_Nibble:
					GPIOC_CRL &= OUT_MASK_HIGHER;
					for(Local_u8PinCounter=4;Local_u8PinCounter<8;Local_u8PinCounter++)
					{

						GPIOC_CRL |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
					}
					break;
				case GPIO_HIGH_BYTE_LOWER_Nibble:
					GPIOC_CRH &= OUT_MASK_LOWER;
					for(Local_u8PinCounter=0;Local_u8PinCounter<4;Local_u8PinCounter++)
					{

						GPIOC_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
					}
					break;
				case GPIO_HIGH_BYTE_UP_Nibble:
					GPIOC_CRH &= OUT_MASK_HIGHER;
					for(Local_u8PinCounter=4;Local_u8PinCounter<8;Local_u8PinCounter++)
					{

						GPIOC_CRH |= ((Copy_u8PortMode)<< (Local_u8PinCounter *_4BIT_SHIFT));
					}
					break;
				default: Local_u8ErrorState = NOTOK;
				}
				break;
				default: Local_u8ErrorState = NOTOK;
	}

	return Local_u8ErrorState;
}
u8 MGPIO_u8SetPortValue4_Pin(u8 Copy_u8Port,u8 Copy_u8NibblePos,u8 Copy_u8PortValue)
{
	u8 Local_u8ErrorState = OK;
	switch(Copy_u8Port)
	{
	case GPIO_PORTA:
		switch(Copy_u8NibblePos)
		{
		case GPIO_LOW_BYTE_LOWER_Nibble:
			GPIOA_ODR &= LOW_LOWER_NIBBLE_MASK;
			GPIOA_ODR |= Copy_u8PortValue;
			break;
		case GPIO_LOW_BYTE_UP_Nibble:
			GPIOA_ODR &= LOW_UP_NIBBLE_MASK;
			GPIOA_ODR |= Copy_u8PortValue<<_4BIT_SHIFT;
			break;
		case GPIO_HIGH_BYTE_LOWER_Nibble:
			GPIOA_ODR &= HIGH_LOWER_NIBBLE_MASK;
			GPIOA_ODR |= Copy_u8PortValue<<_8BIT_SHIFT;
			break;
		case GPIO_HIGH_BYTE_UP_Nibble:
			GPIOA_ODR &= HIGH_UP_NIBBLE_MASK;
			GPIOA_ODR |= Copy_u8PortValue<<12;
			break;
		default: Local_u8ErrorState = NOTOK;
		}
		break;
		case GPIO_PORTB:
			switch(Copy_u8NibblePos)
			{
			case GPIO_LOW_BYTE_LOWER_Nibble:
				GPIOB_ODR &= LOW_LOWER_NIBBLE_MASK;
				GPIOB_ODR |= Copy_u8PortValue;
				break;
			case GPIO_LOW_BYTE_UP_Nibble:
				GPIOB_ODR &= LOW_UP_NIBBLE_MASK;
				GPIOB_ODR |= Copy_u8PortValue<<_4BIT_SHIFT;
				break;
			case GPIO_HIGH_BYTE_LOWER_Nibble:
				GPIOB_ODR &= HIGH_LOWER_NIBBLE_MASK;
				GPIOB_ODR |= Copy_u8PortValue<<_8BIT_SHIFT;
				break;
			case GPIO_HIGH_BYTE_UP_Nibble:
				GPIOB_ODR &= HIGH_UP_NIBBLE_MASK;
				GPIOB_ODR |= Copy_u8PortValue<<(12);
				break;
			default: Local_u8ErrorState = NOTOK;
			}
			break;
			case GPIO_PORTC:
				switch(Copy_u8NibblePos)
				{
				case GPIO_LOW_BYTE_LOWER_Nibble:
					GPIOC_ODR &= LOW_LOWER_NIBBLE_MASK;
					GPIOC_ODR |= Copy_u8PortValue;
					break;
				case GPIO_LOW_BYTE_UP_Nibble:
					GPIOC_ODR &= LOW_UP_NIBBLE_MASK;
					GPIOC_ODR |= Copy_u8PortValue<<_4BIT_SHIFT;
					break;
				case GPIO_HIGH_BYTE_LOWER_Nibble:
					GPIOC_ODR &= HIGH_LOWER_NIBBLE_MASK;
					GPIOC_ODR |= Copy_u8PortValue<<_8BIT_SHIFT;
					break;
				case GPIO_HIGH_BYTE_UP_Nibble:
					GPIOC_ODR &= HIGH_UP_NIBBLE_MASK;
					GPIOC_ODR |= Copy_u8PortValue<<(12);
					break;
				default:Local_u8ErrorState = NOTOK;
				}
				break;
				default:Local_u8ErrorState = NOTOK;
	}
	return Local_u8ErrorState;
}
