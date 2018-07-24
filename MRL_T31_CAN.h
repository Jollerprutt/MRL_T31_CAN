#ifndef	MRL_T31_CAN_H
#define	MRL_T31_CAN_H

#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel SLED = Adafruit_NeoPixel(1, 6, NEO_RGB + NEO_KHZ800);

void statusLED(char LED_color, int LED_brightness){
  uint32_t newColor;
  int bright = map(LED_brightness, 0, 100, 0, 255);
  if (LED_color=='O'){newColor = SLED.Color(0, 0, 0);}
  else if (LED_color=='R'){newColor = SLED.Color(bright, 0, 0);}
  else if (LED_color=='G'){newColor = SLED.Color(0, bright, 0);}
  else if (LED_color=='B'){newColor = SLED.Color(0, 0, bright);}
  else {newColor = SLED.Color(255, 0, 255);}
  SLED.setPixelColor(0, newColor); //  no  color.
  SLED.show(); // This sends the updated pixel color to the hardware.
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return SLED.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return SLED.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return SLED.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

#endif