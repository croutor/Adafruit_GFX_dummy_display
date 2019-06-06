#ifndef Adafruit_GFX_dummy_display_h
#define Adafruit_GFX_dummy_display_h

#include "Arduino.h"
#include "Adafruit_GFX.h"




class Adafruit_GFX_dummy_display : public Adafruit_GFX
{
    public:
        Adafruit_GFX_dummy_display(uint8_t w, uint8_t h); // Constructor
	    ~Adafruit_GFX_dummy_display();
	    void display(void);
        void clearDisplay(void);
	    void drawPixel(int16_t x, int16_t y, uint16_t color);
        size_t write(uint8_t c);
        void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
        void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
        void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
        void fillScreen(uint16_t color);
        /* to match graphics.h */
        const static uint16_t BLACK = 15;
        const static uint16_t WHITE = 15;
    private:

};

#endif
