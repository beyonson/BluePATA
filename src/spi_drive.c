#include "spi_drive.h"

void initSPI(uint8_t spi)
{
    if (spi == 1) {
        SPI1->CR1 |= 0x0044;
        SPI1->CR2 &= 0x00;
    } else if (spi == 2) {
        SPI2->CR1 |= 0x0044;
        SPI2->CR2 &= 0x00;
    } else {
        SPI3->CR1 |= 0x0044;
        SPI3->CR2 &= 0x00;
    }
}

void writeSPI(uint8_t spi, uint16_t data)
{
    if (spi == 1) {
        while((SPI1->SR & 0x80) | (SPI1->SR & 0x2)){} // wait while SPI is busy or TX buffer not empty
        SPI1->DR |= data;
    } else if (spi == 2) {
        while((SPI2->SR & 0x80) | (SPI2->SR & 0x2)){} // wait while SPI is busy or TX buffer not empty
        SPI2->DR |= data;
    } else {
        while((SPI3->SR & 0x80) | (SPI3->SR & 0x2)){} // wait while SPI is busy or TX buffer not empty
        SPI3->DR |= data;
    }
}

int readSPI(uint8_t spi) 
{
    if (spi == 1) {
        return SPI1->DR;
    } else if (spi == 2) {
        return SPI2->DR;
    } else {
        return SPI3->DR;
    } 
}
