#include <stdio>
#include <stdint.h>

#include "stm32f103.h"

int main(void)
{
    // enable APB2
    RCC_BASE->APB2_ENR |= 0x10;

    // configure gpio PC13
    GPIOC_BASE->GPIO_CRH &= 0xFF0FFFFF;
    GPIOC_BASE->GPIO_CRH |= 0x00300000;
    GPIOC_BASE->GPIO_ODR |= 0x2000;
}