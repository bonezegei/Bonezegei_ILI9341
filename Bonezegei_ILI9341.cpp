/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
*/
#include "Bonezegei_ILI9341.h"

Bonezegei_ILI9341::Bonezegei_ILI9341() {

}

Bonezegei_ILI9341::Bonezegei_ILI9341( int8_t rst, int8_t cs, int8_t dc ) {
  _rst = rst;
  _cs = cs;
  _dc = dc;

}

void Bonezegei_ILI9341::begin() {
  vspi = new SPIClass(VSPI);
  vspi->begin();
  pinMode(_dc, OUTPUT);
  pinMode(_cs, OUTPUT);
  pinMode(_rst, OUTPUT);
  digitalWrite(_cs, HIGH);
  digitalWrite(_dc, HIGH);
  digitalWrite(_rst, HIGH);

  sendCommand(0x01);
  sendCommand(0x13); //NOrmal DIsplay ON
   sendCommand(0x29); //NOrmal DIsplay ON
}

void Bonezegei_ILI9341::setRotation(uint8_t rotation) {
}

void Bonezegei_ILI9341::drawPixel(uint16_t x, uint16_t y, uint32_t color) {

}

void Bonezegei_ILI9341::sendCommand(uint8_t cmd) {
  vspi->beginTransaction(SPISettings(ILI9341_SPISPEED, SPI_MSBFIRST, SPI_MODE0));
  digitalWrite(_cs, LOW);
  digitalWrite(_dc, LOW); //cmd mode
  vspi->transfer(cmd);
  digitalWrite(_dc, HIGH);
  digitalWrite(_cs, HIGH);
}

void Bonezegei_ILI9341::sendCommands(uint8_t cmd, uint8_t param[], uint8_t siz) {
  vspi->beginTransaction(SPISettings(ILI9341_SPISPEED, SPI_MSBFIRST, SPI_MODE0));
  digitalWrite(_cs, LOW);

  digitalWrite(_dc, LOW); //cmd mode
  vspi->transfer(cmd);
  digitalWrite(_dc, HIGH);

  for (int a = 0; a < siz; a++) {
    vspi->transfer(param[a]);
  }

  digitalWrite(_cs, HIGH);
}



void Bonezegei_ILI9341::sendSPI(uint8_t dat) {
  vspi->beginTransaction(SPISettings(ILI9341_SPISPEED, SPI_MSBFIRST, SPI_MODE0));
  vspi->transfer(dat);
  vspi->endTransaction();
}
