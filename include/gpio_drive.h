#ifndef __GPIO_DRIVE_H
#define __GPIO_DRIVE_H

#include "stm32f103.h"
#include <stdint.h>
#include <stdio.h>

#define HIGH 1
#define LOW 0

typedef enum { NONE, A, B, C } GPIO_PINS;
typedef enum { INPUT, OUTPUT10, OUTPUT2, OUTPUT50 } MODE;
typedef enum { ANAL, FLI, PP} INPUT_CNF;
typedef enum { GP_PP, GP_OD, AF_PP, AF_OD } OUTPUT_CNF;

void initGPIO(uint8_t gpio, uint8_t pin, uint8_t mode, uint8_t cnf);
void writeGPIO(uint8_t gpio, uint8_t pin, uint8_t value);
int readGPIO(uint8_t gpio, uint8_t pin);
void toggleGPIO(uint8_t gpio, uint8_t pin);

#endif // __GPIO_DRIVE_H

