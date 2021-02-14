#include <Adafruit_NeoPixel.h>
#include "frames.h"
//first one is number of pixels, second is ping
//kalista ur a dipshit
Adafruit_NeoPixel strip(64, 6);
int whichFrame = 0;
int colors [5][3] {
  {255, 0, 255},
  {255, 255, 0},
  {255, 255, 255},
  {0, 255, 0},
  {255, 255, 255}
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
    int pixAddress = pixelMap[i];
    int whichColor = animation[whichFrame][i];
    int red = colors[whichColor][0];
    int green = colors[whichColor][1];
    int blue = colors[whichColor][2];
    if (pixAddress != -1) {
      strip.setPixelColor(pixAddress, red, green, blue);
    }
  }




  /* for (int i = 0; i < strip.numPixels(); i++) {
     int whichColor = pixelMap[whichFrame][i];

     int red = colors[whichColor][0];
     int green = colors[whichColor][1];
     int blue = colors[whichColor][2];
     strip.setPixelColor(i, red, green, blue);

    }*/
  strip.show();
  //whichFrame = (whichFrame + 1) %2;
  //delay(100);

  delay(500);
  whichFrame = (whichFrame + 1) %2;
  



}
