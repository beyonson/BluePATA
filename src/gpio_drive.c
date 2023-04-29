#include "gpio_drive.h"

void initGPIO(uint8_t gpio, uint8_t pin, uint8_t mode, uint8_t cnf)
{
    RCC->APB2ENR |= (1 << gpio); // enable gpio section chosen
    
    if (pin <= 7)
    {
        if (gpio == 1) {
            GPIOA->CRL &= ~(0xf << pin*4);
            GPIOA->CRL |= ((mode <<(pin*4)) | (cnf<<(pin*4+2)));
        } else if (gpio == 2) {
            GPIOB->CRL &= ~(0xf << pin*4);
            GPIOB->CRL |= ((mode <<(pin*4)) | (cnf<<(pin*4+2)));
        } else if (gpio == 3) {
            GPIOC->CRL &= ~(0xf << pin*4);
            GPIOC->CRL |= ((mode <<(pin*4)) | (cnf<<(pin*4+2)));
        }
    } else {
        pin -= 8;
        if (gpio == 1) {
            GPIOA->CRH &= ~(0xf << pin*4);
            GPIOA->CRH |= ((mode <<(pin*4)) | (cnf<<(pin*4+2)));
        } else if (gpio == 2) {
            GPIOB->CRH &= ~(0xf << pin*4);
            GPIOB->CRH |= ((mode <<(pin*4)) | (cnf<<(pin*4+2)));
        } else if (gpio == 3) {
            GPIOC->CRH &= ~(0xf << pin*4);
            GPIOC->CRH |= ((mode <<(pin*4)) | (cnf<<(pin*4+2)));
        }
    }
}