#ifndef __STM32F102_H
#define __STM32F102_H

#include <stdio.h>
#include <stdint.h>

#define vol volatile
typedef struct
{
    vol uint32_t CRL;
    vol uint32_t CRH;
    vol uint32_t IDR;
    vol uint32_t ODR;
    vol uint32_t BSRR;
    vol uint32_t BRR;
    vol uint32_t LCKR;
} GPIO_TypeDef;

typedef struct
{
    vol uint32_t CR;
    vol uint32_t CFGR;
    vol uint32_t CIR;
    vol uint32_t APB2RSTR;
    vol uint32_t APB1RSTR;
    vol uint32_t APB2ENR;
    vol uint32_t APB1ENR;
    vol uint32_t BDCR;
    vol uint32_t CSR;
    vol uint32_t AHBRSTR;
    vol uint32_t CFGR2;

} RCC_TypeDef;

// RCC offsets
#define RCC_BASE    (vol uint32_t)0x40021000 // reset and clock control

// GPIO offsets
#define GPIOA_BASE  (vol uint32_t)0x40010800
#define GPIOB_BASE  (vol uint32_t)0x40010C00
#define GPIOC_BASE  (vol uint32_t)0x40011000
// #define CRL    (vol uint32_t)0x00 // port configuration register low
// #define CRH    (vol uint32_t)0x04 // port configuration register high
// #define IDR    (vol uint32_t)0x08 // input data register
// #define ODR    (vol uint32_t)0x0C // output data register
// #define BSRR   (vol uint32_t)0x10 // port bit set/reset register
// #define BRR    (vol uint32_t)0x14 // port bit reset register
// #define LCKR   (vol uint32_t)0x18 // port configuration lock register

// declare typedefs
#define GPIOC       ((GPIO_TypeDef *) GPIOC_BASE)
#define RCC         ((RCC_TypeDef *) RCC_BASE)

#endif // __STM32F103_H

