#include "Adafruit_GFX_dummy_display.h"
#include <unistd.h>
#include <cstdio>

#define WIDTH 128
#define HEIGHT 64


Adafruit_GFX_dummy_display display(WIDTH,HEIGHT);



void setup()
{
  display.drawFastHLine(0, 31, 128, Adafruit_GFX_dummy_display::WHITE);
  display.drawFastHLine(0, 40, 128, Adafruit_GFX_dummy_display::WHITE);
}

void loop()
{
   char str[50] = {0};
   display.setTextSize(2);
   display.setFont();
   display.setCursor(10,10);
   display.setTextColor(Adafruit_GFX_dummy_display::WHITE);
   display.print("Cibi default freq.");
   display.setCursor(10, 30);
   snprintf(str, 50, "%d / %d", 1, 5);
   display.print(str);
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
   sleep(5);
   return 0;
}
