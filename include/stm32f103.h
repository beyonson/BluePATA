#include <stdio.h>

// RCC offsets
#define RCC_BASE    0x40021000 // reset and clock control
#define APB2_ENR    0x0C // APB2 RCC register

// GPIO offsets
#define GPIOA_BASE  0x40010800
#define GPIOB_BASE  0x40010C00
#define GPIOC_BASE  0x40011000
#define GPIO_CRL    0x00 // port configuration register low
#define GPIO_CRH    0x04 // port configuration register high
#define GPIO_IDR    0x08 // input data register
#define GPIO_ODR    0x0C // output data register
#define GPIO_BSRR   0x10 // port bit set/reset register
#define GPIO_BRR    0x14 // port bit reset register
#define GPIO_LCKR   0x18 // port configuration lock register

