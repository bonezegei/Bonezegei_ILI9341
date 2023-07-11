/*
  Author: Jofel Batutay
  Date: July 2023

  Basic Example for ILI9341
  This library only support 18bit color format (0xRRGGBB) example RED = 0xFF0000, BLUE = 0x0000FF
  The LCD is Connected to the VSPI of ESP32
  ------------------------
  |  LCD PIN   |  ESP32  |
  | MOSI       |   23    |
  | SCK        |   18    |
  | MISO       |   19    | Optional ( not Necessarily Connected to the LCD when mode is diplay Only)
  | CS         |   4     | Can be Assign to other pin
  | RST        |   16    | Can be Assign to other pin
  | DC         |   17    | Can be Assign to other pin
  ------------------------
    LED of the LCD can be connected to the 3.3V with 100 Ohm resitor
*/


#include <Bonezegei_ILI9341.h>

#define LCD_DC 17
#define LCD_CS 4
#define LCD_RST 16
Bonezegei_ILI9341 lcd(LCD_RST, LCD_CS, LCD_DC);  //Initialize the LCD

void setup() {
  lcd.begin();
  delay(10);

  lcd.drawRectangle(10, 10, 110, 60, 0xFF0000);  //Draw Red Rectangle
  delay(2000);
  lcd.drawFilledRectangle(10, 10, 110, 60, 0xFF0000);  //Draw Red Fill Rectangle
  lcd.drawText(20, 20, "Bonzegei", COLOR_WHITE);       //Draw Text (Dafault Font is VERDANA 12)
  delay(2000);
  lcd.clear(0xFFFFFF);  //Fill The Screen With Color White

  lcd.setFont(ARIAL_8);                   //Set Font to Arial 8px
  lcd.drawText(10, 20, "Arial 8 ", 0x0);  //Draw text

  lcd.setFont(ARIAL_10);  //Set Font to Arial 10px
  lcd.drawText(10, 40, "Arial 10  ", 0x0);

  lcd.setFont(ARIAL_11);  //Set Font to Arial 11px
  lcd.drawText(10, 60, "Arial 11 ; ", 0x0);

  lcd.setFont(VERDANA_12);  //Set Font to Verdana 12
  lcd.drawText(10, 80, "VERDANA 12 ", 0x0);

  lcd.setFont(VERDANA_BOLD_12);  //Set Font to Verdana 12 Bold
  lcd.drawText(10, 100, "VERDANA 12 BOLD ", 0x0);

  lcd.setFont(UBUNTU_12);  //Set Font to Ubuntu 12
  lcd.drawText(10, 120, "UBUNTU 12 ", 0x0);

  lcd.setFont(UBUNTU_BOLD_12);  //Set Font to Ubuntu 12 Bold
  lcd.drawText(10, 140, "UBUNTU BOLD 12 ", 0x0);
  delay(5000);
}

void loop() {
  lcd.clear(COLOR_RED);
  delay(1000);
  lcd.clear(COLOR_GREEN);
  delay(1000);
  lcd.clear(COLOR_BLUE);
  delay(1000);
}
