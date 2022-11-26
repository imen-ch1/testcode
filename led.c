#include "gpio.h"
#include "led.h"
#define OFFSET_ODR           (0x14/4)
#define OFFSET_IDR           (0X10/4)
#define OFFSET_MODDR           (0x00/4)
void AssertValid(void)
{
  __asm("NOP");
}

void AssertFailed(void)
{
  while(1){}
}

#define EMB_ASSERT(Exp) ((Exp) ? AssertValid() : AssertFailed())

void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode)
{
   EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
   EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
   EMB_ASSERT(Mode >= INPUT && Mode <= OUTPUT);
   uint16_t *RCCAHB1 = (uint16_t *)(0x40023830);
   *GPIOx &= ~(0x3 << Pin*2);
   *GPIOx |= (Mode << Pin*2);
   
   if ( Mode == INPUT)
   {
     if(GPIOx == GPIOA)
    {
      *RCCAHB1 |= (1<<0);
    }
    else if(GPIOx == GPIOB)
    {
      *RCCAHB1 |= (1<<1);
    }
    else if(GPIOx == GPIOC)
    {
      *RCCAHB1 |= (1<<2);
    }
    else if(GPIOx == GPIOD)
    {
      *RCCAHB1 |= (1<<3);
    }
   }
   else
   {}
}

 uint8_t Button_ToggleLed(uint32_t *GPIOx, uint8_t Pin, uint8_t PinValue)
{
  EMB_ASSERT(GPIOx == GPIOA || GPIOx == GPIOB || GPIOx == GPIOC  || GPIOx == GPIOD );
  EMB_ASSERT(Pin >= PIN0 && Pin <= PIN15);
  EMB_ASSERT(PinValue == 0 || PinValue == 1);
  
  if(GPIOx == GPIOD)
  {
    *(GPIOx + OFFSET_ODR) &= ~(1<<Pin);
    *(GPIOx + OFFSET_ODR) |=  (PinValue<<Pin);
     return ((*(GPIOx + OFFSET_IDR) >> Pin) & 1);
  }
}