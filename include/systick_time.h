#ifndef __SYSTICK_TIME_H
#define __SYSTICK_TIME_H

void systickInit(void);
void delayMs(unsigned long t);
void systickInt(unsigned short uart_1_mgr[],unsigned short uart_2_mgr[],unsigned short uart_3_mgr[]);
void systickIntStart(void);
void delayMicro(void);
void delayUs(unsigned long t);

#endif // __SYSTICK_TIME_H
