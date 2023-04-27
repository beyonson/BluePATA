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
    vol uint32_t AHBENR;
    vol uint32_t APB2ENR;
    vol uint32_t APB1ENR;
    vol uint32_t BDCR;
    vol uint32_t CSR;
    vol uint32_t AHBRSTR;
    vol uint32_t CFGR2;
} RCC_TypeDef;

// RCC base
#define RCC_BASE    (uint32_t)0x40021000 // reset and clock control

// GPIO bases
#define GPIOA_BASE  (uint32_t)0x40010800
#define GPIOB_BASE  (uint32_t)0x40010C00
#define GPIOC_BASE  (uint32_t)0x40011000

// declare typedefs
#define GPIOC       ((GPIO_TypeDef *) GPIOC_BASE)
#define RCC         ((RCC_TypeDef *) RCC_BASE)

#endif // __STM32F103_H

