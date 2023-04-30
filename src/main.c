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
    initGPIO(A, 11, INPUT, FLI);
    int state;
    for(;;)
    {
        state = readGPIO(A,11);
        writeGPIO(C, 13, state);
    }
}

void delay(void)
{
    for(int i=0; i<300000; i++){}
}