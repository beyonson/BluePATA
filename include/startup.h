#ifndef __STARTUP_H
#define __STARTUP_H

#include "gpio_drive.h"
#include "global.h"

#define DEFAULT __attribute__((weak, alias("Default_Handler")))
typedef void (*element_t)(void);

void Reset_Handler(void);
void SysTick_Handler(void);
void RTC_Handler(void);
void RTC_Alarm_Handler(void);

typedef union {
    element_t isr;
    void *stack_top;
} vector_table_t;

extern int main(void);

extern uint32_t _stack_ptr;
extern uint32_t _etext;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _bss;
extern uint32_t _ebss;

#endif // __STARTUP_H
