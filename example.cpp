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
#include <Fonts/FreeSansBold9pt7b.h>

/* A rectangle representing the screen area will be displayed */
#define HEIGHT 64
#define WIDTH 128


Adafruit_GFX_dummy_display display(WIDTH,HEIGHT);

void setTitle(int _title_index, uint16_t _color)
{
    const static int16_t TITLE_POS_X PROGMEM = 15;
    const static int16_t TITLE_POS_Y PROGMEM = 20;
    const static int16_t INDEX_POS_X PROGMEM = 30;
    const static int16_t INDEX_POS_Y PROGMEM = 5;
    const static int16_t MAX_STR_LENGTH PROGMEM = 20;
    const static char title_cibi_default_freq[] PROGMEM = "CIBI DEFAULT FREQ.";
    const static char title_cibi_min_freq[] PROGMEM     = "CIBI FREQ. MIN.";
    const static char title_cibi_max_freq[] PROGMEM     = "CIBI FREQ. MAX.";
    const static char* const titles[] PROGMEM = {
        title_cibi_default_freq,
        title_cibi_min_freq,
        title_cibi_max_freq
    };
    char str[MAX_STR_LENGTH] = {0};
    int menu_index = _title_index + 1;
    int menu_items = sizeof(titles) / sizeof(char*);
    display.setTextSize(1);
    display.setFont();
    display.setTextColor(_color);
    snprintf(str, MAX_STR_LENGTH + 1, "CONFIG %d/%d :", menu_index, menu_items);
    display.setCursor(INDEX_POS_X, INDEX_POS_Y);
    display.print(str);
    //strcpy_P(str, (char*)pgm_read_word(&(titles[_title_index])));
    display.setCursor(TITLE_POS_X,TITLE_POS_Y);
    display.print((char*)titles[_title_index]);
    display.drawFastHLine(0, 31, 128, Adafruit_GFX_dummy_display::WHITE);
}

void setValue(uint32_t _value, uint16_t _color)
{
    const static int16_t VALUE_POS_X PROGMEM = 15;
    const static int16_t VALUE_POS_Y PROGMEM = 55;
    display.setTextSize(1);
    display.setFont(&FreeSansBold9pt7b);
    display.setCursor(VALUE_POS_X,VALUE_POS_Y);
    display.setTextColor(_color);
    display.print(_value);
}

void setCursorPos(int _position, uint16_t _color)
{
  const static int16_t CURSOR_POS_X PROGMEM = 25;
  const static int16_t CURSOR_POS_Y PROGMEM = 60;
  const static int16_t CURSOR_BIG_WIDTH PROGMEM = 10;
  const static int16_t FONT2_XADVANCE PROGMEM = 9;
  int16_t x = CURSOR_POS_X + (7 - _position) * FONT2_XADVANCE;
  bool draw = (-1 == _position ? false : true);
    
  if(draw)
    display.drawRect(x, CURSOR_POS_Y, CURSOR_BIG_WIDTH, 2, _color);
}

void setup()
{
}

int cursor_position = 0;
uint32_t value = 25000000;
void loop()
{
   setTitle(1,Adafruit_GFX_dummy_display::WHITE);
   setValue(value, Adafruit_GFX_dummy_display::WHITE);
   setCursorPos(cursor_position, Adafruit_GFX_dummy_display::WHITE);
   display.display();
   sleep(1);
   display.clearDisplay();
   value = (value + 1) % 30000000;
   cursor_position = (cursor_position + 1) % 7;
}

int main()
{
   
   setup();

   for(int i = 0; i < 100; i++)
   {
      loop();
   }
   sleep(10);
   return 0;
}
