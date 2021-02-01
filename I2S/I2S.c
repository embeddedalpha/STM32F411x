#include "I2S.h"


void I2S1_Master__Init(void)
{
		//CLOCK CONFIGURATION
		RCC -> CR |= RCC_CR_PLLI2SON;
		RCC -> PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
		RCC -> PLLI2SCFGR |= (192 << 6) | (5 << 28) ;
		RCC -> APB2ENR |= RCC_APB2ENR_SPI1EN ;
		RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
		
		//PIN CONFIGURATION
		GPIOA -> MODER &= ~((GPIO_MODER_MODE4_0 | GPIO_MODER_MODE4_1) |
												(GPIO_MODER_MODE5_0 | GPIO_MODER_MODE5_1) |
												(GPIO_MODER_MODE7_0 | GPIO_MODER_MODE7_1));
		GPIOA -> OSPEEDR |= ((GPIO_OSPEEDR_OSPEED4_0 | GPIO_OSPEEDR_OSPEED4_1) |
												(GPIO_OSPEEDR_OSPEED5_0 | GPIO_OSPEEDR_OSPEED5_1) |
												(GPIO_OSPEEDR_OSPEED7_0 | GPIO_OSPEEDR_OSPEED7_1));	
		GPIOA -> PUPDR &= ~((GPIO_PUPDR_PUPDR4_0 | GPIO_PUPDR_PUPDR4_1) |
												(GPIO_PUPDR_PUPDR5_0 | GPIO_PUPDR_PUPDR5_1) |
												(GPIO_PUPDR_PUPDR7_0 | GPIO_PUPDR_PUPDR7_1));	
		GPIOA -> OTYPER |= GPIO_OTYPER_OT4 | GPIO_OTYPER_OT5 | GPIO_OTYPER_OT7;
		GPIOA->AFR[0] |= (5 << 16) | (5 << 20) | (5 << 28);
		
		//PERIPHERAL CONFIGURATION
		SPI1 ->I2SCFGR |= SPI_I2SCFGR_I2SMOD;  //I2S MODE 
		SPI1 ->I2SCFGR |= SPI_I2SCFGR_I2SCFG_1; //MASTER TRANSMIT
		SPI1 ->I2SCFGR |= SPI_I2SCFGR_I2SCFG_0 | SPI_I2SCFGR_I2SCFG_1 ; //MASTER RECEIVE
		SPI1 ->I2SCFGR &= ~SPI_I2SCFGR_I2SSTD;  //I2S PHILLIPS STANDARD
		SPI1 ->I2SCFGR |= SPI_I2SCFGR_DATLEN_0; //24BIT DATA LENGTH
		SPI1 -> I2SPR |= (1<< 1 | 12);
		SPI1 ->I2SCFGR |= SPI_I2SCFGR_I2SE;  //I2S ENABLED

}
//


void I2S2_Master_Init(void)
{
 //CLOCK CONFIGURATION
  RCC -> CR |= RCC_CR_PLLI2SON;
	RCC -> PLLCFGR |= RCC_PLLCFGR_PLLSRC_HSE;
	RCC -> PLLI2SCFGR |= (192 << 6) | (5 << 28) ;
	
	RCC -> APB2ENR |= RCC_APB1ENR_SPI2EN ;
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	//PIN CONFIGURATION
	GPIOB -> MODER &= ~((GPIO_MODER_MODE10_0 | GPIO_MODER_MODE10_1) |
	                    (GPIO_MODER_MODE12_0 | GPIO_MODER_MODE12_1) |
	                    (GPIO_MODER_MODE15_0 | GPIO_MODER_MODE15_1));
	GPIOB -> OSPEEDR |= ((GPIO_OSPEEDR_OSPEED10_0 | GPIO_OSPEEDR_OSPEED10_1) |
	                    (GPIO_OSPEEDR_OSPEED12_0 | GPIO_OSPEEDR_OSPEED12_1) |
	                    (GPIO_OSPEEDR_OSPEED15_0 | GPIO_OSPEEDR_OSPEED15_1));	
	GPIOB -> PUPDR &= ~((GPIO_PUPDR_PUPDR10_0 | GPIO_PUPDR_PUPDR10_1) |
	                    (GPIO_PUPDR_PUPDR12_0 | GPIO_PUPDR_PUPDR12_1) |
	                    (GPIO_PUPDR_PUPDR15_0 | GPIO_PUPDR_PUPDR15_1));	
  GPIOB -> OTYPER |= GPIO_OTYPER_OT10 | GPIO_OTYPER_OT12 | GPIO_OTYPER_OT15;
	GPIOB->AFR[1] |= (5 << 8) | (5 << 16) | (5 << 28);
	
	//PERIPHERAL CONFIGURATION
	SPI2 ->I2SCFGR |= SPI_I2SCFGR_I2SMOD;  //I2S MODE 
	SPI2 ->I2SCFGR |= SPI_I2SCFGR_I2SCFG_1; //MASTER TRANSMIT
	SPI2 ->I2SCFGR |= SPI_I2SCFGR_I2SCFG_0 | SPI_I2SCFGR_I2SCFG_1 ; //MASTER RECEIVE
	SPI2 ->I2SCFGR &= ~SPI_I2SCFGR_I2SSTD;  //I2S PHILLIPS STANDARD
	SPI2 ->I2SCFGR |= SPI_I2SCFGR_DATLEN_0; //24BIT DATA LENGTH
	SPI2 -> I2SPR |= (1<< 1 | 12);
	SPI2 ->I2SCFGR |= SPI_I2SCFGR_I2SE;  //I2S ENABLED	
}
//

