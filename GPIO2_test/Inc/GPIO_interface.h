/*
 * GPIO_interface.h
 *
 *  Created on: Sep 24, 2024
 *      Author: user
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_


#define GPIO_PORTA     0
#define GPIO_PORTB     1
#define GPIO_PORTC     2

#define GPIO_PIN0     0
#define GPIO_PIN1     1
#define GPIO_PIN2     2
#define GPIO_PIN3     3
#define GPIO_PIN4     4
#define GPIO_PIN5     5
#define GPIO_PIN6     6
#define GPIO_PIN7     7


#define GPIO_PIN8      0
#define GPIO_PIN9      1
#define GPIO_PIN10     2
#define GPIO_PIN11     3
#define GPIO_PIN12     4
#define GPIO_PIN13     5
#define GPIO_PIN14     6
#define GPIO_PIN15     7


// CNF
#define GPIO_PIN_OUT_10MHz              1
#define GPIO_PIN_OUT_2MHz               2
#define GPIO_PIN_OUT_50MHz              3

#define GPIO_OUT_PUSH_PULL_10MHz	    ((0<<2)|GPIO_PIN_OUT_10MHz)
#define GPIO_OUT_OPEN_DRAIN_10MHz	    ((1<<2)|GPIO_PIN_OUT_10MHz)
#define GPIO_OUT_AF_PUSH_PULL_10MHz	    ((2<<2)|GPIO_PIN_OUT_10MHz)
#define GPIO_OUT_AF_OPEN_DRAIN_10MHz	((3<<2)|GPIO_PIN_OUT_10MHz)

#define GPIO_OUT_PUSH_PULL_2MHz	    	((0<<2)|GPIO_PIN_OUT_2MHz)
#define GPIO_OUT_OPEN_DRAIN_2MHz	    ((1<<2)|GPIO_PIN_OUT_2MHz)
#define GPIO_OUT_AF_PUSH_PULL_2MHz	    ((2<<2)|GPIO_PIN_OUT_2MHz)
#define GPIO_OUT_AF_OPEN_DRAIN_2MHz		((3<<2)|GPIO_PIN_OUT_2MHz)

#define GPIO_OUT_PUSH_PULL_50MHz	    ((0<<2)|GPIO_PIN_OUT_50MHz)
#define GPIO_OUT_OPEN_DRAIN_50MHz	    ((1<<2)|GPIO_PIN_OUT_50MHz)
#define GPIO_OUT_AF_PUSH_PULL_50MHz	((2<<2)|GPIO_PIN_OUT_50MHz)
#define GPIO_OUT_AF_OPEN_DRAIN_50MHz	((3<<2)|GPIO_PIN_OUT_50MHz)

#define GPIO_IN_ANALOG				(0<<2)
#define GPIO_IN_FLOATING			(1<<2)
#define GPIO_IN_PULL_UP				(2<<2)
#define GPIO_IN_PULL_DOWN			(2<<2)

#define GPIO_PIN_HIGH					1
#define GPIO_PIN_LOW					0

#define GPIO_PORT_LOW_BYTE				1
#define GPIO_PORT_HIGH_BYTE				0

#define GPIO_LOW_BYTE_UP_Nibble			1
#define GPIO_LOW_BYTE_LOWER_Nibble		0

#define GPIO_HIGH_BYTE_LOWER_Nibble		2
#define GPIO_HIGH_BYTE_UP_Nibble		3



u8 MGPIO_u8SetPinMode(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinMode);

u8 MGPIO_u8SetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8PinValue);

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_pu8PinValue);

u8 MGPIO_u8WritePinAccess(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8State);

u8 MGPIO_u8SetPortMode8_Pin(u8 Copy_u8Port,u8 Copy_u8BytePos,u8 Copy_u8PortMode);

u8 MGPIO_u8SetPortValue8_Pin(u8 Copy_u8Port,u8 Copy_u8BytePos,u8 Copy_u8PortValue);

u8 MGPIO_u8SetPortMode4_Pin(u8 Copy_u8Port,u8 Copy_u8NibblePos,u8 Copy_u8PortMode);

u8 MGPIO_u8SetPortValue4_Pin(u8 Copy_u8Port,u8 Copy_u8NibblePos,u8 Copy_u8PortValue);

#endif /* GPIO_INTERFACE_H_ */
