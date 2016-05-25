#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
 #include <avr/power.h>
#endif

uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels

Adafruit_WS2801 strip = Adafruit_WS2801(125, dataPin, clockPin);

void setup() {
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000L)
  clock_prescale_set(clock_div_1); // Enable 16 MHz on Trinket
#endif

  strip.begin();
  
  for (int i = 0; i < 125; i++) {
    strip.setPixelColor(i, Wheel(random(255)));
  }

  strip.show();
}


void loop() {
  // Some example procedures showing how to display to the pixels
  
  int pixel[] = {
    random(0, 25),
    random(25, 50),
    random(50, 75),
    random(75, 100),
    random(100, 125)
  };

  uint32_t startColor[] = {
    strip.getPixelColor(pixel[0]),
    strip.getPixelColor(pixel[1]),
    strip.getPixelColor(pixel[2]),
    strip.getPixelColor(pixel[3]),
    strip.getPixelColor(pixel[4]),
  };
  
  uint32_t endColor[] = {
    Wheel(random(255)),
    Wheel(random(255)),
    Wheel(random(255)),
    Wheel(random(255)),
    Wheel(random(255))
  };

  long startTime = millis();
  long currentTime = startTime;
  long transitionTime = startTime + 500;

  if (startTime > transitionTime) {
    // rollover
    return;
  }

  while (currentTime < transitionTime) {
    for(int i=0; i<5; i++) {
      strip.setPixelColor(pixel[i], colorMap(currentTime, startTime, transitionTime, startColor[i], endColor[i]));
    }
    strip.show();
    currentTime = millis();
  }
  for(int i=0; i<5; i++) {
    strip.setPixelColor(pixel[i], endColor[i]);
  }

  delay(2000);
}

// fill the dots one after the other with said color
// good for testing purposes
void colorWipe(uint32_t c, uint8_t wait) {
  int i;
  
  for (i=0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

/* Helper functions */

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t Wheel(byte WheelPos)
{
  byte r = 0;
  byte g = 0;
  byte b = 0;
  if (WheelPos < 85) {
    r = WheelPos * 3;
    g = 255 - WheelPos * 3;
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   r = 255 - WheelPos * 3;
   b = WheelPos * 3;
  } else {
   WheelPos -= 170; 
   g = WheelPos * 3;
   b = 255 - WheelPos * 3;
  }
  return Color(r>>2,g>>2,b>>2);
}

uint32_t colorMap(long t, long start_t, long end_t, uint32_t start_color, uint32_t end_color) {
  byte start_b = start_color & 0xff; start_color >>= 8;
  byte start_g = start_color & 0xff; start_color >>= 8;
  byte start_r = start_color & 0xff;

  byte end_b = end_color & 0xff; end_color >>= 8;
  byte end_g = end_color & 0xff; end_color >>= 8;
  byte end_r = end_color & 0xff;

  return Color(
           map(t, start_t, end_t, start_r, end_r),
           map(t, start_t, end_t, start_g, end_g),
           map(t, start_t, end_t, start_b, end_b));
}
