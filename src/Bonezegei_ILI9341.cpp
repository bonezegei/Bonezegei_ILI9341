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

  //  sendCommand(0x01);
  //  sendCommand(0x13); //NOrmal DIsplay ON
  //  sendCommand(0x29); //NOrmal DIsplay ON
  digitalWrite(_rst, LOW);
  delay(200);
  digitalWrite(_rst, HIGH);
  delay(2);
  sendCommand(0x11); delay(2);
  sendCommand(0x3a); delay(2);
  sendCommand(0x06); delay(2);
  sendCommand(0x29); delay(2);
  sendCommand(0x2c); delay(2);
  vspi->setFrequency(ILI9341_SPISPEED);
  vspi->setDataMode(SPI_MODE0);
  vspi->setBitOrder(MSBFIRST);
  //vspi->setClockDivider(1000000);
  //vspi->setClockDivider(0x00061001);
  Serial.begin(115200);
  Serial.println("Bonezegei ILI9341");
  Serial.print("divider=");
  Serial.println(vspi->getClockDivider(), HEX);
}

void Bonezegei_ILI9341::setRotation(uint8_t rotation) {
}

void Bonezegei_ILI9341::drawPixel(uint16_t x, uint16_t y, uint32_t color) {

}

void Bonezegei_ILI9341::sendCommand(uint8_t cmd) {
  //vspi->beginTransaction(SPISettings(ILI9341_SPISPEED, MSBFIRST, SPI_MODE0));
  digitalWrite(_cs, LOW);
  digitalWrite(_dc, LOW); //cmd mode
  vspi->transfer(cmd);
  digitalWrite(_dc, HIGH);
  digitalWrite(_cs, HIGH);
  //vspi->endTransaction();
}

void Bonezegei_ILI9341::sendData(uint8_t dat) {
  //vspi->beginTransaction(SPISettings(ILI9341_SPISPEED, MSBFIRST, SPI_MODE0));
  digitalWrite(_cs, LOW);
  //vspi->transfer(dat);
  //vspi->write(dat);


  spiWriteByteNL( vspi->bus(), dat);
  //spiWriteShortNL( vspi->bus(),dat);
  digitalWrite(_cs, HIGH);
  //vspi->endTransaction();
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
  // vspi->transfer(dat);
  vspi->write(dat);
  vspi->endTransaction();
}
