#include "stm32f30x.h"

/* Private functions ---------------------------------------------------------*/

void init(void)
{
	GPIO_InitTypeDef	GPIO_InitStructure;

	//Provide clock to GPIO
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOA, ENABLE);
	//Initialize GPIOA P0
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;  // Output
	GPIO_InitStructure.GPIO_OType = GPIO_PuPd_NOPULL; // Push Pull
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);

	//Provide clock to GPIOE
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOE, ENABLE);
	//Initialize GPIOE
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_All;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;  // Output
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; // Push Pull
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOE, &GPIO_InitStructure);
}

/**
  * @brief  Main program.
  * @param  None 
  * @retval None
  */
int main(void)
{  
  /* Initialize LEDs and User Button available on STM32F3-Discovery board */
  
  init();


  /* Infinite loop */
  while (1)
  { 
		GPIO_Write(GPIOE, (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0)) * 0xFFFF);
  }
}



#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
