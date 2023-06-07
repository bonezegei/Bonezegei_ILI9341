/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
*/

#ifndef _BONEZEGEI_ILI9341_H_
#define _BONEZEGEI_ILI9341_H_
#include <SPI.h>
#include <Arduino.h>

//default SPI Speed
#define ILI9341_SPISPEED 1000000U

//#define 



class Bonezegei_ILI9341 {
  public:
    Bonezegei_ILI9341();
    Bonezegei_ILI9341( int8_t rst, int8_t cs, int8_t dc );
    
    void begin();
    void setRotation(uint8_t rotation);
    void drawPixel(uint16_t x, uint16_t y, uint32_t color);

    void sendCommand(uint8_t cmd);
    void sendCommands(uint8_t cmd, uint8_t param[], uint8_t siz);
    void sendSPI(uint8_t dat);
    
    int8_t _rst;            
    int8_t _cs;              
    int8_t _dc;  
    SPIClass * vspi = NULL;           
};

#endif
