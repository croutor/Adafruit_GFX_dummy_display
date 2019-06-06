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
#include <Adafruit_GFX_dummy_display.h>
#include <graphics.h>

Adafruit_GFX_dummy_display::Adafruit_GFX_dummy_display(uint8_t w, uint8_t h) :
Adafruit_GFX(w, h)
{
   char size_str[50] = {0};
   const char* title = "Adafruit Dummy display";
   snprintf(size_str, 50, "w: %hhu, h: %hhu", w, h);
   int gd = DETECT,gm;
   initgraph(&gd,&gm,NULL);
   rectangle(0, 0, w, h);
   outtextxy(10, h + 10, (char*)title);
   outtextxy(10, h + 20, (char*)size_str);
}

Adafruit_GFX_dummy_display::~Adafruit_GFX_dummy_display()
{
   closegraph();
}

void Adafruit_GFX_dummy_display::display(void)
{
}

void Adafruit_GFX_dummy_display::clearDisplay(void)
{
   cleardevice();
}

void Adafruit_GFX_dummy_display::drawPixel(int16_t x, int16_t y, uint16_t color)
{
   circle(x, y, 0);
}

void Adafruit_GFX_dummy_display::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
   line(x, y, x, y+h);
}

void Adafruit_GFX_dummy_display::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
   line(x, y, x+w, y);
}

void Adafruit_GFX_dummy_display::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
   bar(x, y, x+w, y+h);
}

void Adafruit_GFX_dummy_display::fillScreen(uint16_t color)
{

}

