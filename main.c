/**
  ******************************************************************************
  * @file    main.c
  * @author  Mouadh Dahech
  * @brief   GPIO Driver 
  * @version V1.0.0
  * @date    16-10-2022
  *****************************************************************************/
/* Includes ------------------------------------------------------------------*/
#include "gpio.h"
#include "led.h"
/* Private function prototypes -----------------------------------------------*/

/* Macros --------------------------------------------------------------------*/

/* Private functions ---------------------------------------------------------*/


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main()
{

  GPIO_Config(GPIOA, PIN4, OUTPUT);
 
  while(1)
  {
     uint8_t PinState = GPIO__Read_Pin(GPIOD, PIN12);
     if ( PinState == 0)
     {
       GPIO_Write_Pin(GPIOD, PIN12, 1);
     }
     else
     {
       GPIO_Write_Pin(GPIOD, PIN12, 0);
     }
  }
}

/**************************************END OF FILE**************************************/
