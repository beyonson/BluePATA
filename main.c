#include <stdio.h>
#include <stdint.h>

#include "stm32f10x.h"

int main(void)
{
    // enable APB2
    RCC->APB2ENR |= 0x10;

    // configure gpio PC13
    GPIOC->CRH &= 0xFF0FFFFF;
    GPIOC->CRH |= 0x00300000;
    //GPIOC->ODR |= 0x2000;
}