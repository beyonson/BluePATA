#include <stdint.h>
#include "startup.h"

__attribute__((section(".vector_table")))

const vector_table_t vectors[] = {
  {.stack_top = &_stack_ptr},
  Reset_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  SysTick_Handler,
  0,
  0,
  0,
  RTC_Handler,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  RTC_Alarm_Handler
};

void Reset_Handler(void)
{
  uint32_t *src, *dest;

  src = &_etext;
  for (dest = &_data; dest < &_edata;)
  {
    *dest++ = *src++;
  }

  for (dest = &_bss; dest < &_ebss;)
  {
    *dest++ = 0;
  }

  main();
}

void SysTick_Handler(void)
{
	toggleGPIO(C, 13);
}

void RTC_Handler(void)
{
  // add code here
  NVIC->ICPR[(((uint32_t)(int32_t)3) >> 5UL)] = (uint32_t)(1UL << (((uint32_t)(int32_t)3) & 0x1FUL));
	RTC->CRL &= ~(1<<0);
}

void RTC_Alarm_Handler(void)
{
  // add code here
  EXTI->PR |= 0x20000;
  RTC->CRL &= ~(1<<1);
}
