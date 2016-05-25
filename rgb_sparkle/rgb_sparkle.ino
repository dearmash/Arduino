#include <Adafruit_NeoPixel.h>

#define PIN 4
#define ANIM_SIZE 6
#define NLEDS 250

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NLEDS, PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();

  for (int i = 0; i < NLEDS; i++) {
    strip.setPixelColor(i, Wheel(random(255)));
  }

  strip.show();
}

void loop() {

  int pixel[] = {
    random(0, 50),
    random(50, 100),
    random(100, 150),
    random(150, 200),
    random(200, 250)
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
  long transitionTime = startTime + 100;

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
}

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

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  //  switch (WheelPos % 3) {
  //    case 1:
  //      return 0x996633;
  //    case 2:
  //      return 0x0000ff;
  //    default:
  //      return 0;
  //  }
  //  if(WheelPos < 85) {
  //    WheelPos = 0;
  //  } else if(WheelPos < 170) {
  //    WheelPos = 85;
  //  } else {
  //    WheelPos = 170;
  //  }
  int bucket = 255 / 12;
  WheelPos = (WheelPos / bucket) * bucket;

  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
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
