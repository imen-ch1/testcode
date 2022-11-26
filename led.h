#ifndef __LED_H
#define __LED_H

#include <stdint.h>
#endif
void GPIO_Config(uint32_t *GPIOx, uint8_t Pin, uint8_t Mode);
uint8_t Button_ToggleLed(uint32_t *GPIOx, uint8_t Pin, uint8_t PinValue);