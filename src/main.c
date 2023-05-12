#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "stm32f103.h"
#include "gpio_drive.h"
#include "systick_time.h"
#include "spi_drive.h"
#include "oled_drive.h"

int main(void);
void delay(void);

void reset_handler(void)
{
    main();

    while(1){}
}

int main(void)
{
    systickInit();
    initSPI(2);
    oledInit(2);
    oledBlank(2);
    initGPIO(C, 13, OUTPUT10, GP_PP);

    uint16_t wData, rData;
    char rDataStr[2];

    wData = 0x28;
    writeSPI(2, wData);
    rData = readSPI(2);
    rDataStr[0] = rData;
    rDataStr[1] = rData;
    oledPrint(2, rDataStr);
    for(;;){}
}
