/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
*/

#ifndef _BONEZEGEI_ILI9341_H_
#define _BONEZEGEI_ILI9341_H_
#include <SPI.h>
#include <Arduino.h>


#include "bitmaps/default.h"
#include "Font.h"

#define COLOR_RED 0xFF0000
#define COLOR_BLUE 0x0000ff
#define COLOR_GREEN 0x00ff00
#define COLOR_WHITE 0xFFFFFF
#define COLOR_BLACK 0x000000
#define COLOR_GRAY 0x808080
#define COLOR_TEAL 0x008080
#define COLOR_YELLOW 0xFFFF00

//default SPI Speed
static const int ILI9341_SPISPEED = 80000000;  // 80 MHz

class Bonezegei_ILI9341 {
public:
  Bonezegei_ILI9341();
  Bonezegei_ILI9341(int8_t rst, int8_t cs, int8_t dc);

  void begin();
  void sendCommand(uint8_t cmd);
  void sendData(uint8_t dat);
  void spi24(uint32_t dat);
  void spi16(uint16_t dat);

  void col(uint16_t st, uint16_t en);
  void row(uint16_t st, uint16_t en);
  void setRotation(uint8_t rotation);
  void drawPixel(uint16_t x, uint16_t y, uint32_t color);

  void clear(uint32_t color);

  void drawFilledRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color);
  void drawRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color);
  void drawRectangleStrip(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint32_t color);
  void drawCircle(uint16_t x1, uint16_t y1, uint16_t r, uint32_t color);
  void drawBitmap(uint16_t x1, uint16_t y1, int xbytes, int yheight, const char bitmap[], uint32_t color);

  void drawRoundFilledRectangle(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t r, uint32_t color);

  void setChar8(uint16_t x, uint16_t y, char ch, int bits, uint32_t color);
  void drawChar(int x, int y, char ch, uint32_t color, const char fd[], const int dsc[95][3]);
  void drawText(int x, int y, const char *str, uint32_t color, const char fd[], const int dsc[95][3]);
  void drawText(int x, int y, const char *str, uint32_t color);

  void setFontParam(const char fd[], const int dsc[95][3]);
  void setFont(FONT_TYPE ft);

  uint8_t getFontHeight() {
    return font.descriptor[0][1];
  }

  uint16_t getStringWidth(char *str) {
    uint16_t cn = 0;
    while (*str) {
      cn += font.descriptor[(*str - 32)][0];
      str += 1;
    }
    return cn;
  }

  int8_t _rst;
  int8_t _cs;
  int8_t _dc;
  SPIClass *vspi = NULL;

  int xRun;
  int yRun;
  FONT font;
};

#endif
