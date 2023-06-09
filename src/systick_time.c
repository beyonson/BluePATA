#include "stm32f103.h" 
#include "systick_time.h"

void systickInit(void)
{
	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL = 5;
}
void delayMicro(void)
{
	SysTick->LOAD = 72;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
}

void delayUs(unsigned long t)
{
	for(;t>0;t--)
		{
			delayMicro();
		}
}

void delayMillis(void)
{
	SysTick->LOAD = 0x11940;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
}

void delayMs(unsigned long t)
{
	for(;t>0;t--)
		{
			delayMillis();
		}
}

void systickIntStart(void)
{
	__disable_irq();
	SysTick->CTRL = 0;
	SysTick->LOAD = 7200000 - 1;
	SysTick->VAL = 0;
	SysTick->CTRL |= 7;
	__enable_irq();
}

void systickInt(unsigned short uart_1_mgr[],unsigned short uart_2_mgr[],unsigned short uart_3_mgr[])
{
	if(uart_1_mgr[0]!=0)
	{
	 if(uart_1_mgr[6] == 0)
	 {
		uart_1_mgr[0] = 0;
		uart_1_mgr[1] = 1;
		uart_1_mgr[5] = 0;
		systickInit();
	 }
	 else
		{
		uart_1_mgr[6]--;
	 }
	}
	else if(uart_2_mgr[0]!=0)
	{
	 if(uart_2_mgr[6] == 0)
	 {
		uart_2_mgr[0] = 0;
		uart_2_mgr[1] = 1;
		uart_2_mgr[5] = 0;
		systickInit();
	 }
	 else
		{
		uart_2_mgr[6]--;
	 }
	}
	else if(uart_3_mgr[0]!=0)
	{
	 if(uart_3_mgr[6] == 0)
	 {
		uart_3_mgr[0] = 0;
		uart_3_mgr[1] = 1;
		uart_3_mgr[5] = 0;
		systickInit();
	 }
	 else
		{
		uart_3_mgr[6]--;
	 }
	}
}
