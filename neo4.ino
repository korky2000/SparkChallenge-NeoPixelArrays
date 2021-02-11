#include <Adafruit_NeoPixel.h>
#include "frames.h"
//first one is number of pixels, second is ping
//kalista ur a dipshit
Adafruit_NeoPixel strip(64, 6);
int whichFrame = 0;
int colors [5][3]{
{0,0,0},
{255,0,0},
{255,0,255},
{0,0,255},
{255,255,0}
};
void setup() {
  strip.setBrightness(10);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();
}
void loop() {
  for(int i=0; i<=64; i++) { // For each pixel in strip...
    strip.setPixelColor(i, 255,0,0);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(50);
  }
  for(uint16_t i=strip.numPixels(); i>0; i--) {
      strip.setPixelColor(i, 0,0,0);
      strip.show();
      delay(50);
  }

  
  }
  
