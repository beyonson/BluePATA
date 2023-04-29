#ifndef __GPIO_DRIVE_H
#define __GPIO_DRIVE_H

#include "stm32f103.h"
#include <stdint.h>
#include <stdio.h>

typedef enum { NONE, A, B, C } GPIO_PINS;
typedef enum { INPUT, OUTPUT10, OUTPUT2, OUTPUT50 } MODE;
typedef enum { ANALOG, FLOATING_INPUT, PULL} INPUT_CNF;
typedef enum { GP_PP, GP_OD, AF_PP, AF_OD } OUTPUT_CNF;

/*
* Function for configuring GPIO pins
* gpio: gpio section A-C
* pin: gpio pin to enable
* cnf: port configuration bits
* mode: gpio mode, input or output
*/
void initGPIO(uint8_t gpio, uint8_t pin, uint8_t mode, uint8_t cnf);

#endif // __GPIO_DRIVE_H
