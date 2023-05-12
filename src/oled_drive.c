#include "oled_drive.h"
#include <string.h>

void oledCmd1Byte(uint8_t i2c, uint8_t data)
{
	i2cStart(i2c);
	i2cAdd(i2c, 0x78, 0); // choosing oled address
	
	i2cData(i2c, 0x00); // send command
	
	i2cData(i2c, data);
	
	i2cStop(i2c);
}

void oledCmd2Byte(uint8_t i2c, uint8_t data[])
{
	int i=0;
	i2cStart(i2c);
	i2cAdd(i2c, 0x78, 0); // choosing oled address
	
	i2cData(i2c, 0x00); // send command
	for(i=0; i<2; i++)
		{i2cData(i2c, data[i]);}
	
	i2cStop(i2c);
}

// oled initialization
void oledInit(uint8_t i2c)
{
	i2cInit(i2c, i2c_FM);
	
	uint8_t cmd[] = {0xA8, 0x3F};
	oledCmd2Byte(i2c, cmd);
	uint8_t cmd1[] = {0xD3, 0x00};
	oledCmd2Byte(i2c, cmd1);
	
	oledCmd1Byte(i2c, 0x40);
	oledCmd1Byte(i2c, 0xA1);
	oledCmd1Byte(i2c, 0xC8);
	
	uint8_t cmd2[] = {0xDA, 0x12};
	oledCmd2Byte(i2c, cmd2);
	uint8_t cmd3[] = {0x81, 0x7F};
	oledCmd2Byte(i2c, cmd3);
	
	oledCmd1Byte(i2c, 0xA4);
	oledCmd1Byte(i2c, 0xA6);

	uint8_t cmd4[] = {0xD5, 0x80};
	oledCmd2Byte(i2c, cmd4);
	uint8_t cmd5[] = {0x8D, 0x14};
	oledCmd2Byte(i2c, cmd5);
	
	oledCmd1Byte(i2c, 0xAF);
	
	uint8_t cmd6[] = {0x20, 0x10};
	oledCmd2Byte(i2c, cmd6);
}


// oled data
void oledData(uint8_t i2c, uint8_t data)
{
	i2cStart(i2c);
	i2cAdd(i2c, 0x78, 0); // choosing oled address
	
	i2cData(i2c, 0x40); // send data
	
	i2cData(i2c, data);
	
	i2cStop(i2c);
}

// oled position
void oledPos(uint8_t i2c, uint8_t yPos, uint8_t xPos)
{
	oledCmd1Byte(i2c, 0x00 + (0x0F & xPos)); // x position
	oledCmd1Byte(i2c, 0x10 + (0x0F & (xPos>>4)));
	oledCmd1Byte(i2c, 0xB0 + yPos); // y position
}

// blank screen
void oledBlank(uint8_t i2c)
{
	int i, j;
	oledPos(i2c, 0, 0);
	for (i=0; i<8; i++)
	{
		for (j=0; j<128; j++)
		{
			oledData(i2c, 0x00);
		}
	}
	oledPos(i2c, 0, 0);
}

// print
void oledPrint(uint8_t i2c, char str[])
{
	int i, j;
	i = 0;
	while(str[i])
	{
		for(j=0; j<5; j++)
		{
			oledData(i2c, ASCII[(str[i]-32)][j]);
		}
		i++;
	}
}

// message
void oledMsg(uint8_t i2c, uint8_t yPos, uint8_t xPos, char str[])
{
	oledPos(i2c, yPos, xPos);
	oledPrint(i2c, str);
}

// ascii intput
void oledAprint(uint8_t i2c, int asc)
{
	int j;
	for(j=0; j<5; j++)
	{
		oledData(i2c, ASCII[asc][j]);
	}
}

void oledClearBuffer(uint8_t buffer[][128])
{
	int i, j;
	for (i=0; i<8; i++)
	{
		for (j=0; j<128; j++)
		{
			buffer[i][j] = 0;
		}
	}
}

void oledUpdateBuffer(uint8_t xPos, uint8_t cols, const uint8_t *img, uint8_t buffer[][128])
{
	int i, j, cnt;
	cnt = 0;
	for (i = 1; i<8; i++) 
	{
		for (j = xPos; j<xPos+cols; j++)
		{
			cnt += 1;
			buffer[i][j] = img[cnt];	
		}
	}
}

void updateTimeBuffer(uint8_t str[], uint8_t buffer[][128])
{
	int i, j, row, col;
	col = 0;
	row = 0;
	i = 1;
	while(i<6)
	{
		for (j = 0; j<45; j++)
		{
			buffer[row][col] = BIGASCII[str[i-1]][j];
			if (col >= (i*15))
			{
				col -= 15;
				row += 1;
			}
			col += 1;
		}
		i++;
		row=0;
	}
}

void updateStrBuffer(short yPos, short xPos,char str[], uint8_t buffer[][128])
{
	int i,j, cnt_col,cnt_row;
	
	cnt_col= xPos;
	cnt_row = yPos;
	i=0;
	while(str[i])
	{
		if(cnt_row>8)
		{break;}
		for(j=0;j<5;j++)
		{
			buffer[cnt_row][cnt_col] = BIGASCII[str[i]-32][j];
			if((cnt_col+1)>127)
			{
				if((cnt_row+1)>8)
				{
					break;
				}
				else{
					cnt_row ++;
					cnt_col = xPos;
				}
			}
			else
				{
				 cnt_col ++;
				}
		}
		i++;
	}
}

//print buffer
void printBuffer(uint8_t i2c, uint8_t buffer[][128])
{
	oledPos(i2c,0,0);
	int i,j;
	for (i=0;i<8;i++)
	{
		for(j=0;j<128;j++)
		{
			oledData(i2c,buffer[i][j]);
		}
	}
}

