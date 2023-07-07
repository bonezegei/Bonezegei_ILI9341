/*
  This Library is written for ILI9341 LCD
  Author: Bonezegei (Jofel Batutay)
*/
#ifndef _FONT_H_
#define _FONT_H_
#include "fonts/arial8.h"
#include "fonts/arial10.h"
#include "fonts/arial11.h"
#include "fonts/ubuntu12.h"
#include "fonts/ubuntu12B.h"

#include "fonts/FontVerdana12.h"
#include "fonts/FontVerdana12B.h"

typedef enum {
  ARIAL_8 = 0,
  ARIAL_10,
  ARIAL_11,
  UBUNTU_12,
  UBUNTU_BOLD_12,
  VERDANA_12,
  VERDANA_BOLD_12
} FONT_TYPE;


class FONT {
public:
  FONT() {}
  char *fnt;
  int descriptor[95][3];
};




#endif