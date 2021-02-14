#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(64, 6);
int colors [4][3] {
  {255, 0, 255},
  {0, 0, 255},
  {255, 0, 0},
  {0, 255, 0}
};
int favorite = 0;
void setup() {
  strip.setBrightness(100);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();
}
void loop() {


  for (int i = 0; i < strip.numPixels(); i++) {
     int red = colors[favorite][0];
     int green = colors[favorite][1];
     int blue = colors[favorite][2];
     strip.setPixelColor(i, 255, 0, 0);

    }
    strip.show();
    delay(100);
    favorite=(favorite + 1) % 4;
    delay(500);

  
  strip.show();

}
