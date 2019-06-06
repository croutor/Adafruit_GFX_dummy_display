Adafruit-GFX-dummy-display aims to provide a virtual display to develop graphics using Adafruit-GFX-Library (https://github.com/adafruit/Adafruit-GFX-Library) without hardware.

It is currently using libgraph (https://savannah.nongnu.org/projects/libgraph/) and runs under Linux.

HOW TO :

* First clone this project
```
git clone https://github.com/croutor/Adafruit_GFX_dummy_display.git
```

* Then clone Adafruit_FFX project within this project's directory:
```
cd Adafruit_GFX_dummy_display
git clone https://github.com/adafruit/Adafruit-GFX-Library.git
```

* Patch Adafruit-GFX-Library/Adafruit_GFX.h to add on line 3:
#define ARDUINO 123



It is not an Adafruit project.

Author: Vincent Hervieux




