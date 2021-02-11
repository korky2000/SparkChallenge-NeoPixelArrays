#include <Adafruit_NeoPixel.h>
#include "frames.h"
//first one is number of pixels, second is ping
//kalista ur a dipshit
Adafruit_NeoPixel strip(64, 6);
int whichFrame = 0;
int colors [5][3]{
{0,0,0},
{255,0,0},
{165,42,42},
{0,255,0},
{255,255,255}
};
void setup() {
  strip.setBrightness(10);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();
}
void loop() {
  for (int i = 0; i < strip.numPixels(); i++) {
    int whichColor = animation[whichFrame][i];
    
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];
    strip.setPixelColor(i, red, green, blue);
    
  }
  strip.show();
  whichFrame = (whichFrame + 1) %2;
  delay(100);
 
  delay(500);



}
