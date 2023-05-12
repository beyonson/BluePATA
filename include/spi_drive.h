#include "stm32f103.h"
#include "gpio_drive.h"

void initSPI(uint8_t spi);
void writeSPI(uint8_t spi, uint16_t data);
int readSPI(uint8_t spi);
