/*
 * GPIO_private.h
 *
 *  Created on: Sep 24, 2024
 *      Author: user
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define CTRL_MASK 			0xfffffff0
#define CTRL_8BIT_MASK 			0x00

#define OUT_MASK_LOWER 		0xffff0000
#define OUT_MASK_HIGHER 	0x0000ffff

#define _8BIT_SHIFT			8
#define _4BIT_SHIFT			4

#define LOW_LOWER_NIBBLE_MASK 			0xfffffff0
#define LOW_UP_NIBBLE_MASK 				0xffffff0f
#define HIGH_LOWER_NIBBLE_MASK 			0xfffff0ff
#define HIGH_UP_NIBBLE_MASK 			0xffff0fff



#endif /* GPIO_PRIVATE_H_ */
