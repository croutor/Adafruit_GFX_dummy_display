#include <Adafruit_GFX_dummy_display.h>
#include <sstream>
#include <graphics.h>

Adafruit_GFX_dummy_display::Adafruit_GFX_dummy_display(uint8_t w, uint8_t h) :
Adafruit_GFX(w, h)
{
   std::ostringstream legend(std::ostringstream::ate);
   legend << "Adafruit Dummy display " << "w: " << w << " ,h: " << h;
   int gd = DETECT,gm;
   //int left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50
   initgraph(&gd,&gm,NULL);
   rectangle(0, 0, w, h);
   // circle(x, y, radius);
   // bar(left + 300, top, right + 300, bottom);
   // line(left - 10, top + 150, left + 410, top + 150);
   // ellipse(x, y + 200, 0, 360, 100, 50);
   outtextxy(10, h + 10, (char*)legend.str().c_str());
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

size_t Adafruit_GFX_dummy_display::write(uint8_t c)
{
   // uint8_t str[2] = {c, 0};
   // outtextxy(cursor_x,  cursor_y, (char*)str);
   // cursor_x++;
   putchar(c);
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

