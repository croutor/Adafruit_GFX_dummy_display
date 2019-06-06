/*
 * Copyright (c) 2019, Vincent Hervieux vincent.hervieux@gmail.com
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * * Neither the name of the author Vincent Hervieux, nor the
 *   names of its contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS AND CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#include "Adafruit_GFX_dummy_display.h"
#include <unistd.h>
#include <cstdio>

#include <Fonts/FreeSansBold12pt7b.h>

#define WIDTH 128
#define HEIGHT 64


Adafruit_GFX_dummy_display display(WIDTH,HEIGHT);

void setFreq(uint32_t _freq, uint16_t _color) 
{
   const static int16_t FREQ_BIG_TEXT_POS_X PROGMEM = 1;
   const static int16_t FREQ_SMALL_TEXT_POS_X PROGMEM = 34;
   const static int16_t FREQ_TEXT_POS_Y PROGMEM = 20;
        
   const static uint16_t MAX_FREQ_STR_LENGTH PROGMEM = 8; /* 30000000*/
   char str[MAX_FREQ_STR_LENGTH + 1] = {0};
   char big_str[4] = {0};
   snprintf(str, MAX_FREQ_STR_LENGTH + 1, "%08ld", _freq);
   strncpy (big_str, str, 2 * sizeof(char));
   display.setFont(&FreeSansBold12pt7b);
   display.setCursor(FREQ_BIG_TEXT_POS_X,FREQ_TEXT_POS_Y);
   display.setTextColor(_color);
   display.print(big_str);
   display.setCursor(FREQ_SMALL_TEXT_POS_X,FREQ_TEXT_POS_Y);
   display.setFont(&FreeSansBold12pt7b);
   display.print(str + 2 * sizeof(char));
}

void setModulation(int _modulation, uint16_t _color)
{
    const static int16_t MOD_TEXT_POS_X PROGMEM = 108;
    const static int16_t MOD_TEXT_POS_Y PROGMEM = 50;
    const static char mod_cw[] PROGMEM = "CW";
    const static char mod_am[] PROGMEM = "AM";
    const static char mod_fm[] PROGMEM = "FM";
    const static char mod_usb[] PROGMEM = "USB";
    const static char mod_lsb[] PROGMEM = "LSB";
    const static char* const modulations[] PROGMEM = {
        mod_cw, mod_am, mod_fm, mod_usb, mod_lsb
    };
    display.setTextSize(1);
    display.setFont();
    display.setCursor(MOD_TEXT_POS_X,MOD_TEXT_POS_Y);
    display.setTextColor(_color);
    display.print((char*)(modulations[_modulation]));
}

void setup()
{
  display.drawFastHLine(0, 31, 128, Adafruit_GFX_dummy_display::WHITE);
  display.drawFastHLine(0, 40, 128, Adafruit_GFX_dummy_display::WHITE);
}

void loop()
{
   char str[50] = {0};
   display.setTextSize(0);
   display.setFont();
   display.setCursor(10,10);
   display.setTextColor(Adafruit_GFX_dummy_display::WHITE);
   display.print("Cibi default freq.");
   display.setCursor(10, 30);
   snprintf(str, 50, "%d / %d", 1, 5);
   display.print(str);
   setModulation(1,Adafruit_GFX_dummy_display::WHITE);
   display.display();
}

int main()
{
   
   setup();

   loop();
   // for(int i = 0; i < 100; i++)
   // {
   //    loop();
   // }
   sleep(10);
   return 0;
}
