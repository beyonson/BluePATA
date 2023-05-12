#ifndef __OLED_DRIVE_H
#define __OLED_DRIVE_H

#include "i2c_drive.h"
#include "global.h"

void oledCmd1Byte(uint8_t i2c, uint8_t data);
void oledCmd2Byte(uint8_t i2c, uint8_t data[]);
void oledInit(uint8_t i2c);
void oledData(uint8_t i2c, uint8_t data);
void oledPos(uint8_t i2c, uint8_t yPos, uint8_t xPos);
void oledBlank(uint8_t i2c);
void oledPrint(uint8_t i2c, char str[]);
void oledMsg(uint8_t i2c, uint8_t yPos, uint8_t xPos, char str[]);
void oledAprint(uint8_t i2c, int asc);
void oledClearBuffer(uint8_t buffer[][128]);
void oledUpdateBuffer(uint8_t xPos, uint8_t cols, const uint8_t *image, uint8_t buffer[][128]);
void updateStrBuffer(short yPos, short xPos,char str[], uint8_t buffer[][128]);
void updateTimeBuffer(uint8_t str[], uint8_t buffer[][128]);
void printBuffer(uint8_t i2c, uint8_t buffer[][128]);

struct oledImage {
    uint8_t cols;
    uint8_t *image[10];
};

#endif // __OLED_DRIVE_H
