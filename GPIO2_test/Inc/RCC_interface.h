

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
/**
 * @prief
 * 
 * @param(in)
 * 
 * @param()
 * 
 */
void MRCC_voidInit();
/** 
Copy_u8Bus_ID :
		1- RCC_AHB		
		2- RCC_APB1	
		3- RCC_APB2	
		4- RCC_ADC
		5- RCC_PLL
*/
#define RCC_AHB		1
#define RCC_APB1	2
#define RCC_APB2	3
#define RCC_ADC		4
#define RCC_PLL   	5
/**
Copy_u8PreValue :
*/
/***************************
Set and cleared by software to control AHB clock division factor.
*/
#define RCC_SYSCLK_DIV2 			0b1000		
#define RCC_SYSCLK_DIV4				0b1001
#define RCC_SYSCLK_DIV8 			0b1010
#define RCC_SYSCLK_DIV16 			0b1011
#define RCC_SYSCLK_DIV64 			0b1100
#define RCC_SYSCLK_DIV128 			0b1101
#define RCC_SYSCLK_DIV256 			0b1110
#define RCC_SYSCLK_DIV512 			0b1111
#define RCC_SYSCLK_DIV1 			0b0000
/***************************
Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1). (Max f = 32;)
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
*/

#define RCC_APB1_HCLK_DIV1				0
#define RCC_APB1_HCLK_DIV2				4
#define RCC_APB1_HCLK_DIV4				5
#define RCC_APB1_HCLK_DIV8				6
#define RCC_APB1_HCLK_DIV16				7

/***************************
Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
0xx: HCLK not divided
100: HCLK divided by 2
101: HCLK divided by 4
110: HCLK divided by 8
111: HCLK divided by 16
*/
#define RCC_APB2_HCLK_DIV1				0
#define RCC_APB2_HCLK_DIV2				4
#define RCC_APB2_HCLK_DIV4				5
#define RCC_APB2_HCLK_DIV8				6
#define RCC_APB2_HCLK_DIV16				7

/**************************
Set and cleared by software to select the frequency of the clock to the ADCs.
00: PLCK2 divided by 2
01: PLCK2 divided by 4
10: PLCK2 divided by 6
11: PLCK2 divided by 8
*/
#define RCC_PLCK2_DIV2					0
#define RCC_PLCK2_DIV4					1
#define RCC_PLCK2_DIV6					2	
#define RCC_PLCK2_DIV8					3

/**************************
These bits are written by software to define the PLL multiplication factor.
*/
/*
000x: Reserved
0010: PLL input clock x 4
0011: PLL input clock x 5
0100: PLL input clock x 6
0101: PLL input clock x 7
0110: PLL input clock x 8
0111: PLL input clock x 9
10xx: Reserved
1100: Reserved
1101: PLL input clock x 6.5
111x: Reserved
*/
#define RCC_PLL_MUL4					2
#define RCC_PLL_MUL5					3
#define RCC_PLL_MUL6					4	
#define RCC_PLL_MUL7					5
#define RCC_PLL_MUL8					6
#define RCC_PLL_MUL9					7
#define RCC_PLL_MUL6D5					13

u8 MRCC_u8Prescaler(u8 Copy_u8Bus_ID,u8 Copy_u8PreValue);
/***************************
	APB1 peripheral clock enable register
*/
#define RCC_APB1ENR_DACEN				29 
#define RCC_APB1ENR_PWREN         		28 
#define RCC_APB1ENR_BKPEN               27 
#define RCC_APB1ENR_CAN2EN              26 
#define RCC_APB1ENR_CAN1EN              25
#define RCC_APB1ENR_I2C2EN              22 
#define RCC_APB1ENR_T2C1EN              21 
#define RCC_APB1ENR_UART5EN        	    20 
#define RCC_APB1ENR_UART4EN             19 
#define RCC_APB1ENR_USART3EN			18
#define RCC_APB1ENR_USART2EN			17
#define RCC_APB1ENR_SPI3EN				15
#define RCC_APB1ENR_SPI2EN				14
#define RCC_APB1ENR_WWDGEN				11
#define RCC_APB1ENR_TIM7EN				5
#define RCC_APB1ENR_TIM6EN        		4 
#define RCC_APB1ENR_TIM5EN        		3
#define RCC_APB1ENR_TIM4EN       		2
#define RCC_APB1ENR_TIM3EN       		1
#define RCC_APB1ENR_TIM2EN			 	0
/***************************
	APB2 peripheral clock enable register
*/
#define RCC_APB2ENR_AFIOEN				0
#define RCC_APB2ENR_IOPA				2
#define RCC_APB2ENR_IOPB				3
#define RCC_APB2ENR_IOPC				4
#define RCC_APB2ENR_IOPD				5
#define RCC_APB2ENR_IOPE				6
#define RCC_APB2ENR_ADC1				9
#define RCC_APB2ENR_ADC2				10
#define RCC_APB2ENR_TIM1				11
#define RCC_APB2ENR_SPI1				12
#define RCC_APB2ENR_USART1EN			14
/****************************
	AHB Peripheral Clock enable register
*/
#define RCC_AHBENR_ETHMACRXEN			16
#define RCC_AHBENR_ETHMACTXEN			15
#define RCC_AHBENR_ETHMACEN				14
#define RCC_AHBENR_OTGFSEN				12
#define RCC_AHBENR_CRCEN				6
#define RCC_AHBENR_FLITFEN				4
#define RCC_AHBENR_SRAMEN				2
#define RCC_AHBENR_DMA2EN				1
#define RCC_AHBENR_DMA1EN				0
/*
Copy_u8PrepheralClkState:
	 1- ENABLE 
	 2- DISABLE
*/
#define ENABLE		1
#define DISABLE		0
u8 MRCC_u8EnableClk(u8 Copy_u8Bus_ID,u8 Copy_u8Prepheral_ID,u8 Copy_u8PrepheralClkState);

#endif
