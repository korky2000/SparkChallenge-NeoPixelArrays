#include <Adafruit_NeoPixel.h>
#include "frames.h"

Adafruit_NeoPixel strip(64, 6);
int whichFrame = 0;
int colors [5][3] {
  {0, 0, 0},
  {255, 0, 0},
  {255, 0, 255},
  {0, 0, 255},
  {255, 255, 0}
};
void setup() {
  strip.setBrightness(10);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();
}
void loop() {
  int i;
  int k;
  for (k = 0; k < 64 * 5; k++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 64 / strip.numPixels()) + k) & 255));
    }
    strip.show();
    delay(10);
  }

}
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;  return strip.Color(0, 0, 0);
}
