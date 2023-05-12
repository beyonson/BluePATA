#ifndef __I2C_DRIVE_H
#define __I2C_DRIVE_H

#include "stm32f103.h"
#include "gpio_drive.h"
#include "systick_time.h"

#define i2c_FM 0x2D
#define i2c_SM 0xB4

void i2cInit(char i2c, unsigned short speed_mode);
void i2cStart(char i2c);
void i2cWrite(char i2c, char address, char data[]);
void i2cAdd(char i2c, char address, char RW);
void i2cData(char i2c, char data);
void i2cStop(char i2c);

#endif // __I2C_DRIVE_H
