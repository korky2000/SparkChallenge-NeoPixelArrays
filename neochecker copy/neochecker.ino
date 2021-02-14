#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(64, 6);
boolean flip = false;
void setup() { //sets up
  strip.setBrightness(10);
  Serial.begin(9600);
  strip.begin();
  strip.clear();
  strip.show();

}
void loop() {
  for (int i = 0; i < 64; i++) {
  if(i%8 == 0 ){
    flip =! flip;
  }
  flip=!flip;
  if(flip){
    strip.setPixelColor(i,255,0,0);
  }else{
    strip.setPixelColor(i,0,0,0);
  }
  }

  
  strip.show(); 
  // Update strip with new contents
  delay(50);                 // Pause for a moment

}
