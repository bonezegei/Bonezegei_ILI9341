/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
*/

#ifndef _BONEZEGEI_ILI9341_H_
#define _BONEZEGEI_ILI9341_H_
#include <SPI.h>
#include <Arduino.h>

//default SPI Speed
//#define ILI9341_SPISPEED 1000000U
static const int ILI9341_SPISPEED = 240000000; // 1 MHz

class Bonezegei_ILI9341 {
  public:
    Bonezegei_ILI9341();
    Bonezegei_ILI9341( int8_t rst, int8_t cs, int8_t dc );

    void begin();
    void setRotation(uint8_t rotation);
    void drawPixel(uint16_t x, uint16_t y, uint32_t color);

    void sendCommand(uint8_t cmd);
    void sendData(uint8_t dat);

    void sendCommands(uint8_t cmd, uint8_t param[], uint8_t siz);
    void sendSPI(uint8_t dat);

    void col(uint16_t st, uint16_t en) {
      sendCommand(0x2a);
      sendData(st >> 8);
      sendData(st);
      sendData(en >> 8);
      sendData(en);
    }

    void row(uint16_t st, uint16_t en) {
      sendCommand(0x2b);
      sendData(st >> 8);
      sendData(st);
      sendData(en >> 8);
      sendData(en);
    }

    inline void pix(uint32_t color) {
      sendData(color);
      sendData(color >> 8);
      sendData(color >> 16);
      //vspi->write(color);
      //vspi->write16(color >> 8);
    }

    void clr(uint32_t color) {
      col(0, 240);
      row(0, 320);
      sendCommand(0x2c);
      //digitalWrite(_cs, LOW);

      for (int a = 0; a < 76800; a++) {
        pix(color);
        //vspi-> write32(color);
      }
      //vspi->transfer(dat);
      
      //digitalWrite(_cs, HIGH);
    }

    int8_t _rst;
    int8_t _cs;
    int8_t _dc;
    SPIClass * vspi = NULL;
};

#endif
