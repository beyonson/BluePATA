#include <stdio.h>
#include <stdint.h>

#include "stm32f103.h"
#include "gpio_drive.h"

int main(void);
void delay(void);

void reset_handler(void)
{
    main();

    while(1){}
}

int main(void)
{
    initGPIO(C, 13, OUTPUT10, GP_PP);
    for(;;)
    {
        writeGPIO(C, 13, LOW);
        delay();
        writeGPIO(C, 13, HIGH);
        delay();
    }
}

void delay(void)
{
    for(int i=0; i<300000; i++){}
}