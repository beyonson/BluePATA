#include <stdio.h>
#include <stdint.h>

#include "stm32f103.h"

int main(void);
void delay(void);

void reset_handler(void)
{
    main();

    while(1){}
}

int main(void)
{
    // enable APB2
    RCC->APB2ENR |= 0x10;

    // configure gpio PC13
    GPIOC->CRH &= 0xFF0FFFFF;
    GPIOC->CRH |= 0x00300000;

    for(;;)
    {
        GPIOC->ODR &= 0x0000;
        delay();
        GPIOC->ODR |= 0x2000;
        delay();
    }
}

void delay(void)
{
    for(int i=0; i<300000; i++){}
}