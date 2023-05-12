#include "gpio_drive.h"

/*
* Function for configuring GPIO pins
* gpio: gpio section A-C
* pin: gpio pin to enable
* cnf: port configuration bits
* mode: gpio mode, input or output
*/
void initGPIO(uint8_t gpio, uint8_t pin, uint8_t mode, uint8_t cnf)
{
    // enable APB2
    RCC->APB2ENR |= (1 << (gpio + 1));

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

/*
* Function for writing to GPIO pins
* gpio: gpio section A-C
* pin: gpio pin to write
* value: high or low
*/
void writeGPIO(uint8_t gpio, uint8_t pin, uint8_t value)
{
    if (gpio == 1) {
        value ? (GPIOA->ODR |= (value<<pin)) : (GPIOA->ODR &= ~(1<<pin));;
    } else if (gpio == 2) {
        value ? (GPIOB->ODR |= (value<<pin)) : (GPIOB->ODR &= ~(1<<pin));;
    } else if (gpio == 3) {
        value ? (GPIOC->ODR |= (value<<pin)) : (GPIOC->ODR &= ~(1<<pin));;
    }
}

/*
* Function for reading from GPIO pins
* gpio: gpio section A-C
* pin: gpio pin to read
* returns: gpio value
*/
int readGPIO(uint8_t gpio, uint8_t pin)
{
    if (gpio == 1) {
        return ((GPIOA->IDR & (1<<pin))>>pin);
    } else if (gpio == 2) {
        return ((GPIOB->IDR & (1<<pin))>>pin);
    } else if (gpio == 3) {
        return ((GPIOC->IDR & (1<<pin))>>pin);
    }
}

/*
* Function for toggling GPIO pin values
* gpio: gpio section A-C
* pin: gpio pin to read
* returns: gpio value
*/
void toggleGPIO(uint8_t gpio, uint8_t pin)
{
    if (readGPIO(gpio, pin)) {
        writeGPIO(gpio, pin, 0);
    } else {
        writeGPIO(gpio, pin, 1);
    }
}