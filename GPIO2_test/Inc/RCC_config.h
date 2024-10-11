

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/*
	0: HSI_MODE
	1: HSE_MODE
	2: PLL_MODE
	3: ADC_MODE

*/  

#define RCC_CLOCK_MODE  	HSE_MODE

#if RCC_CLOCK_MODE == HSE_MODE
 /*
  * Select External Connection Circuit
  * options:
  * 	1- RCC_CRYSTAL_CLK
  * 	2- RCC_RC_CLK
  * 	
  * */
#define RCC_CONN_TYPE 	RCC_CRYSTAL_CLK

#endif

#if RCC_CLOCK_MODE == PLL_MODE
 /*
  * Select PLL Clock Source
  * options:
  * 	1- HSI_MODE  // Note: if you select HSI, CLK divides by 2.
  * 	2- HSE_MODE	 // Nothing
  * 	
  * */
#define RCC_PLL_clkSRC 	HSI_MODE

#endif

#endif
