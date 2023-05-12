#ifndef __STM32F103_H
#define __STM32F103_H

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
} RCC_TypeDef;

typedef struct
{
    vol uint32_t CR1;
    vol uint32_t CR2;
    vol uint32_t OAR1;
    vol uint32_t OAR2;
    vol uint32_t DR;
    vol uint32_t SR1;
    vol uint32_t SR2;
    vol uint32_t CCR;
    vol uint32_t TRISE;
} I2C_TypeDef;

typedef struct
{
    vol uint32_t CTRL;
    vol uint32_t LOAD;
    vol uint32_t VAL;
    vol uint32_t CALIB;
} SysTick_TypeDef;

typedef struct
{
      vol uint32_t CR;
      vol uint32_t CSR;
} PWR_TypeDef;

typedef struct
{
      vol uint32_t IMR;
      vol uint32_t EMR;
      vol uint32_t RTSR;
      vol uint32_t FTSR;
      vol uint32_t SWIER;
      vol uint32_t PR;
} EXTI_TypeDef;

typedef struct
{
      vol uint16_t CRH;
      uint16_t  RESERVED0;
      vol uint16_t CRL;
      uint16_t  RESERVED1;
      vol uint16_t PRLH;
      uint16_t  RESERVED2;
      vol uint16_t PRLL;
      uint16_t  RESERVED3;
      vol uint16_t DIVH;
      uint16_t  RESERVED4;
      vol uint16_t DIVL;
      uint16_t  RESERVED5;
      vol uint16_t CNTH;
      uint16_t  RESERVED6;
      vol uint16_t CNTL;
      uint16_t  RESERVED7;
      vol uint16_t ALRH;
      uint16_t  RESERVED8;
      vol uint16_t ALRL;
      uint16_t  RESERVED9;
} RTC_TypeDef;

typedef struct
{
  vol uint32_t ISER[8U];               /*!< Offset: 0x000 (R/W)  Interrupt Set Enable Register */
        uint32_t RESERVED0[24U];
  vol uint32_t ICER[8U];               /*!< Offset: 0x080 (R/W)  Interrupt Clear Enable Register */
        uint32_t RSERVED1[24U];
  vol uint32_t ISPR[8U];               /*!< Offset: 0x100 (R/W)  Interrupt Set Pending Register */
        uint32_t RESERVED2[24U];
  vol uint32_t ICPR[8U];               /*!< Offset: 0x180 (R/W)  Interrupt Clear Pending Register */
        uint32_t RESERVED3[24U];
  vol uint32_t IABR[8U];               /*!< Offset: 0x200 (R/W)  Interrupt Active bit Register */
        uint32_t RESERVED4[56U];
  vol uint8_t  IP[240U];               /*!< Offset: 0x300 (R/W)  Interrupt Priority Register (8Bit wide) */
        uint32_t RESERVED5[644U];
  vol uint32_t STIR;                   /*!< Offset: 0xE00 ( /W)  Software Trigger Interrupt Register */
} NVIC_TypeDef;

typedef struct
{
      vol uint32_t CR1;
      vol uint32_t CR2;
      vol uint32_t SR;
      vol uint32_t DR;
      vol uint32_t CRCPR;
      vol uint32_t RXCRCR;
      vol uint32_t TXCRCR;
      vol uint32_t I2S;
      vol uint32_t I2SCFGR;
      vol uint32_t I2SPR;
} SPI_TypeDef;

// Base addresses
#define RCC_BASE    (vol uint32_t)0x40021000 // reset and clock control

#define GPIOA_BASE  (vol uint32_t)0x40010800
#define GPIOB_BASE  (vol uint32_t)0x40010C00
#define GPIOC_BASE  (vol uint32_t)0x40011000

#define I2C1_BASE   (vol uint32_t)0x40005400
#define I2C2_BASE   (vol uint32_t)0x40005800

#define SCS_BASE    (vol uint32_t)0xE000E000
#define STK_BASE    (SCS_BASE + 0x0010UL)
#define NVIC_BASE   (SCS_BASE +  0x0100UL)

#define RTC_BASE    (vol uint32_t)0x40002800

#define PWR_BASE    (vol uint32_t)0x40007000

#define EXTI_BASE   (vol uint32_t)0x40010400

#define SPI1_BASE   (vol uint32_t)0x40013000
#define SPI2_BASE   (vol uint32_t)0x40003800
#define SPI3_BASE   (vol uint32_t)0x40003C00

// declare typedefs
#define RCC         ((RCC_TypeDef *) RCC_BASE)
#define GPIOA       ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB       ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC       ((GPIO_TypeDef *) GPIOC_BASE)
#define I2C1        ((I2C_TypeDef *) I2C1_BASE)
#define I2C2        ((I2C_TypeDef *) I2C2_BASE)
#define SysTick     ((SysTick_TypeDef *) STK_BASE)
#define NVIC        ((NVIC_TypeDef *) NVIC_BASE)
#define RTC         ((RTC_TypeDef *) RTC_BASE)
#define PWR         ((PWR_TypeDef *) PWR_BASE)
#define EXTI        ((EXTI_TypeDef *) EXTI_BASE)
#define SPI1        ((SPI_TypeDef *) SPI1_BASE)
#define SPI2        ((SPI_TypeDef *) SPI2_BASE)
#define SPI3        ((SPI_TypeDef *) SPI3_BASE)


void __disable_irq(void);
void __enable_irq(void);

#endif // __STM32F103_H

