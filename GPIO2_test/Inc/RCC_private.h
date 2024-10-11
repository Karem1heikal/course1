

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

 #define HSI_MODE	1
 #define HSE_MODE	2
 #define PLL_MODE	3
 #define ADC_MODE	4

#define RCC_CRYSTAL_CLK		1
#define RCC_RC_CLK			2


#define START_PLLMUL 		18		
#define START_ADCPRE		14
#define START_PPRE2			11
#define START_PPRE1			8
#define START_HPRE			4
#define START_SWS				2

#define AHB_MASK				0xffffff0f
#define APB1_MASK				0xfffff8ff
#define APB2_MASK				0xffffc7ff
#define ADC_MASK				0xffff3fff
#define PLL_MASK				0xffc3ffff




#endif