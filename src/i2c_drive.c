#include "i2c_drive.h"

void i2cInit(char i2c, unsigned short speed_mode)
{
	// enable io clock
	RCC->APB2ENR |= 1; 
	
	if(i2c==1)
	{
		// enable i2c1 clock
		RCC->APB1ENR |= 0x200000; 
		
		// pin enable
		initGPIO(B, 6, OUTPUT50, AF_OD);
		initGPIO(B, 7, OUTPUT50, AF_OD);
		I2C1->CR1 |= 0x8000;
		I2C1->CR1 &= ~0x8000;
		I2C1->CR2 = 0x8;
		
		// set i2c speed
		I2C1->CCR = speed_mode;
		I2C1->TRISE = 0x9;
		
		// enable register
		I2C1->CR1 |= 0x1;
	} else {
		// enable i2c1 clock
		RCC->APB1ENR |= 0x400000; 
		
		// pin enable
		initGPIO(B, 10, OUTPUT50, AF_OD);
		initGPIO(B, 11, OUTPUT50, AF_OD);
		I2C2->CR1 |= 0x8000;
		I2C2->CR1 &= ~0x8000;
		I2C2->CR2 = 0x8;
		
		// set i2c speed
		I2C2->CCR = speed_mode;
		I2C2->TRISE = 0x9;
		
		// enable register
		I2C2->CR1 |= 0x1;
	}
}

// sending the address and r/w
void i2cAdd(char i2c, char address, char RW)
{
	volatile int tmp;
	if (i2c==1) 
	{
		I2C1->DR = (address|RW);
		while((I2C1->SR1 & 2)==0){}
		while(I2C1->SR1 & 2) 
		{
			tmp = I2C1->SR1;
			tmp = I2C1->SR2;
			if((I2C1->SR1)==0)
			{break;}
		} 
	} else if (i2c==2) 
	{
		I2C2->DR = (address|RW);
		while((I2C2->SR1 & 2)==0){}
		while(I2C2->SR1 & 2) 
		{
			tmp = I2C2->SR1;
			tmp = I2C2->SR2;
			if((I2C2->SR1)==0)
			{break;}
		} 
	}
}

// start 
void i2cStart(char i2c)
{
	if (i2c==1) 
	{
		I2C1->CR1 |= 0x100;  // setting up start bit
		while (!(I2C1->SR1 & 1)){}
	} 
	else if (i2c==2)
	{
		I2C2->CR1 |= 0x100;  // setting up start bit
		while (!(I2C2->SR1 & 1)){}
	}
}

// sending data
void i2cData(char i2c, char data)
{
	if (i2c==1)
	{
		while((I2C1->SR1 & 0x80)==0);
		I2C1->DR = data;
		while((I2C1->SR1 & 0x80)==0);
	}
	else if (i2c==2)
	{
		while((I2C2->SR1 & 0x80)==0);
		I2C2->DR = data;
		while((I2C2->SR1 & 0x80)==0);
	}
}

// stop
void i2cStop(char i2c)
{
	volatile int tmp;
	if (i2c==1) 
	{
		tmp = I2C1->SR1;
		tmp = I2C1->SR2;
		I2C1->CR1 |= 0x200;
	} 
	else if (i2c==2)
	{
		tmp = I2C2->SR1;
		tmp = I2C2->SR2;
		I2C2->CR1 |= 0x200;
	}
}


// write function
void i2c_write(char i2c, char address, char data[])
{
	int i=0;
	i2cStart(i2c);
	i2cAdd(i2c, address, 0);
	while(data[i])
	{	
		i2cData(i2c, data[i]);
		i++;
	}
	i2cStop(i2c);
}
