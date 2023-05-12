#include "stm32f103.h"

void __disable_irq(void)
{
	for (int i=0; i<67; i++)
	{
	NVIC->ICER[(((uint32_t)(int32_t)i) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)i) & 0x1FUL));
  	NVIC->ICPR[(((uint32_t)(int32_t)i) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)i) & 0x1FUL));
	}
}

void __enable_irq(void)
{
    NVIC->ISER[(((uint32_t)(int32_t)3) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)3) & 0x1FUL));
}