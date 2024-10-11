
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../Inc/RCC_register.h"
#include "../Inc/RCC_private.h"
#include "../Inc/RCC_config.h"
#include "../Inc/RCC_interface.h"


void MRCC_voidInit()
{
	#if RCC_CLOCK_MODE == HSI_MODE
		// select HSI
		CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
		CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
		// Enable Internal High Speed
		SET_BIT(RCC_CR,RCC_CR_HSION);
		while(GET_BIT(RCC_CR,RCC_CR_HSIRDY)==0);
	#elif RCC_CLOCK_MODE == HSE_MODE
		// select HSE
		CLR_BIT(RCC_CFGR,RCC_CFGR_SW1);
		SET_BIT(RCC_CFGR,RCC_CFGR_SW0);
		// connection circuit
	#if RCC_CONN_TYPE == RCC_CRYSTAL_CLK
		CLR_BIT(RCC_CR,RCC_CR_HSERDP);
	#elif RCC_CONN_TYPE == RCC_RC_CLK
		SET_BIT(RCC_CR,RCC_CR_HSERDP);
	#else
	#error "wrong in select HSE connected Clk"
	#endif //-- connection circuit
		// Enable External High Speed
		SET_BIT(RCC_CR,RCC_CR_HSEON);
		// Check if HSE Clk is Ready
		//while(GET_BIT(RCC_CR,RCC_CR_HSERDY)==0);
	#elif RCC_CLOCK_MODE == PLL_MODE
		// select PLL
		SET_BIT(RCC_CFGR,RCC_CFGR_SW1);
		CLR_BIT(RCC_CFGR,RCC_CFGR_SW0);
	#if	RCC_PLL_clkSRC == HSI_MODE
		CLR_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
	#elif RCC_PLL_clkSRC == HSE_MODE
		SET_BIT(RCC_CFGR,RCC_CFGR_PLLSRC);
	#else
	#error "wrong in select PLL source Clk"
	#endif //-- RCC_PLL_clkSRC
		// Enable PLL
		SET_BIT(RCC_CR,RCC_CR_PLLON);
		while(GET_BIT(RCC_CR,RCC_CR_PLLRDY)==0);

	#else
	#error "configration error in clk mode"
	#endif  //-- RCC_CLOCK_MODE
}

u8 MRCC_u8Prescaler(u8 Copy_u8Bus_ID,u8 Copy_u8PreValue)
{
	u8 Local_u8ErrorState = OK;
	if(RCC_AHB==Copy_u8Bus_ID)
	{
		if(Copy_u8PreValue<=RCC_SYSCLK_DIV512){
		RCC_CFGR &= AHB_MASK;
		RCC_CFGR |= ((u32)Copy_u8PreValue)<<START_HPRE;
		}
		else
			Local_u8ErrorState = NOTOK;
	}
	else if(RCC_APB1==Copy_u8Bus_ID)
	{
		if(Copy_u8PreValue<=RCC_APB1_HCLK_DIV16){
		RCC_CFGR &= APB1_MASK;
		RCC_CFGR |= ((u32)Copy_u8PreValue)<<START_PPRE1;
		}
		else
			Local_u8ErrorState = NOTOK;
	}
	else if(RCC_APB2==Copy_u8Bus_ID)
	{
		if(Copy_u8PreValue<=RCC_APB2_HCLK_DIV16){
		RCC_CFGR &= APB2_MASK;
		RCC_CFGR |= ((u32)Copy_u8PreValue)<<START_PPRE2;
		}
		else
			Local_u8ErrorState = NOTOK;
	}
	else if(RCC_ADC==Copy_u8Bus_ID)
	{
		if(Copy_u8PreValue<=RCC_PLCK2_DIV8){
		RCC_CFGR &= ADC_MASK;
		RCC_CFGR |= ((u32)Copy_u8PreValue)<<START_ADCPRE;
		}
		else
			Local_u8ErrorState = NOTOK;
	}
	else if(RCC_PLL==Copy_u8Bus_ID)
	{
		if(Copy_u8PreValue<=RCC_PLL_MUL6D5){
		RCC_CFGR &= PLL_MASK;
		RCC_CFGR |= ((u32)Copy_u8PreValue)<<START_PLLMUL;
		}
		else
			Local_u8ErrorState = NOTOK;
	}
	else
		Local_u8ErrorState = NOTOK;
	return Local_u8ErrorState;
}

u8 MRCC_u8EnableClk(u8 Copy_u8Bus_ID,u8 Copy_u8Prepheral_ID,u8 Copy_u8PrepheralClkState)
{
	u8 Local_u8ErrorState = OK;
	if(RCC_AHB==Copy_u8Bus_ID)
	{
		if(Copy_u8PrepheralClkState==ENABLE)
			SET_BIT(RCC_AHBENR,Copy_u8Prepheral_ID);
		else if(Copy_u8PrepheralClkState==DISABLE)
			CLR_BIT(RCC_AHBENR,Copy_u8Prepheral_ID);
		else
			Local_u8ErrorState = NOTOK;
	}
	else if(RCC_APB1==Copy_u8Bus_ID)
	{
		if(Copy_u8PrepheralClkState==ENABLE)
			SET_BIT(RCC_APB1ENR,Copy_u8Prepheral_ID);
		else if(Copy_u8PrepheralClkState==DISABLE)
			CLR_BIT(RCC_APB1ENR,Copy_u8Prepheral_ID);
		else
			Local_u8ErrorState = NOTOK;
	}
	else if(RCC_APB2==Copy_u8Bus_ID)
	{
		if(Copy_u8PrepheralClkState==ENABLE)
			SET_BIT(RCC_APB2ENR,Copy_u8Prepheral_ID);
		else if(Copy_u8PrepheralClkState==DISABLE)
			CLR_BIT(RCC_APB2ENR,Copy_u8Prepheral_ID);
		else
			Local_u8ErrorState = NOTOK;
	}
	else
		Local_u8ErrorState = NOTOK;
	return Local_u8ErrorState;

}
