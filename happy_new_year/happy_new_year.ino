#include <Adafruit_NeoPixel.h>

#define PIN 4
#define NLEDS 160
#define PINK 0xF2319E

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NLEDS, PIN, NEO_RGB + NEO_KHZ800);

uint8_t mapping[29][29] = {
  {   0,  -1,  -1,  -1,  10,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {   1,  -1,  -1,  -1,  11,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {   2,  -1,  -1,  -1,  12,  -1,  -1,  27,  28,  29,  -1,  -1,  35,  36,  37,  38,  -1,  -1,  47,  48,  49,  50,  -1,  -1,  55,  -1,  -1,  -1,  60}, 
  {   3,   7,   8,   9,  13,  -1,  -1,  -1,  -1,  -1,  30,  -1,  34,  -1,  -1,  -1,  42,  -1,  46,  -1,  -1,  -1,  54,  -1,  56,  -1,  -1,  -1,  61}, 
  {   4,  -1,  -1,  -1,  14,  -1,  -1,  26,  25,  24,  23,  -1,  33,  39,  40,  41,  -1,  -1,  45,  51,  52,  53,  -1,  -1,  -1,  57,  58,  59,  62}, 
  {   5,  -1,  -1,  -1,  15,  -1,  17,  -1,  -1,  -1,  22,  -1,  32,  -1,  -1,  -1,  -1,  -1,  44,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  63}, 
  {   6,  -1,  -1,  -1,  16,  -1,  -1,  18,  19,  20,  21,  -1,  31,  -1,  -1,  -1,  -1,  -1,  43,  -1,  -1,  -1,  -1,  -1,  -1,  66,  65,  64,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 104,  -1,  -1,  -1,  94,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 105,  -1,  -1,  -1,  95,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 106, 103,  -1,  -1,  96,  -1,  -1,  83,  82,  81,  -1,  -1,  79,  -1,  -1,  -1,  68,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 107,  -1, 102,  -1,  97,  -1,  93,  -1,  -1,  -1,  80,  -1,  78,  -1,  -1,  -1,  69,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 108,  -1,  -1, 101,  98,  -1,  92,  84,  85,  86,  87,  -1,  77,  -1,  74,  -1,  70,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 109,  -1,  -1,  -1,  99,  -1,  91,  -1,  -1,  -1,  -1,  -1,  76,  -1,  73,  -1,  71,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1, 110,  -1,  -1,  -1, 100,  -1,  -1,  90,  89,  88,  -1,  -1,  -1,  75,  -1,  72,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1, 112,  -1,  -1,  -1, 120,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1, 113,  -1,  -1,  -1, 121,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1, 114,  -1,  -1,  -1, 122,  -1,  -1, 133, 134, 135,  -1,  -1,  -1, 144, 145, 146,  -1,  -1, 155,  -1, 157, 158,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1, 115,  -1, 119,  -1,  -1, 123,  -1,  -1,  -1, 136,  -1,  -1,  -1,  -1,  -1, 147,  -1, 154, 156,  -1,  -1, 159,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1, 118,  -1,  -1,  -1, 124, 132, 131, 130, 129,  -1,  -1, 143, 142, 141, 148,  -1, 153,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1, 117,  -1,  -1,  -1, 125,  -1,  -1,  -1,  -1,  -1, 137,  -1,  -1,  -1, 149,  -1, 152,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
  {  -1,  -1,  -1,  -1,  -1, 116,  -1,  -1,  -1,  -1, 126, 127, 128,  -1,  -1,  -1, 138, 139, 140, 150,  -1, 151,  -1,  -1,  -1,  -1,  -1,  -1,  -1}, 
};

uint8_t cursive[NLEDS] = {
  0, 1, 2, 3, 4, 5, 6, 10, 11, 12, 13, 14, 15, 16, 7, 8, 9,
  24, 25, 26, 17, 18, 19, 20, 27, 28, 29, 30, 23, 22, 21,
  35, 34, 33, 32, 31, 36, 37, 38, 42, 41, 40, 39,
  47, 46, 45, 44, 43, 48, 49, 50, 54, 53, 52, 51,
  55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,
  110, 109, 108, 107, 106, 105, 104, 103, 102, 101, 100, 99, 98, 97, 96, 95, 94,
  84, 85, 86, 87, 80, 81, 82, 83, 93, 92, 91, 90, 89, 88,
  79, 78, 77, 76, 75, 73, 74, 72, 71, 70, 69, 68,
  112, 113, 114, 115, 119, 122, 121, 120, 118, 117, 116,
  132, 131, 130, 129, 136, 135, 134, 133, 123, 124, 125, 126, 127, 128,
  141, 142, 143, 137, 138, 139, 140, 144, 145, 146, 147, 148, 149, 150,
  155, 154, 153, 152, 151, 156, 157, 158, 159
};

void setup() {

  strip.begin();
  strip.setBrightness(32);
  strip.show();
}

void loop() {
  cursiveWipe(0xF2319E, 20);
  delay(1000);
  cursiveWipe(0, 0);
  cursiveRainbowWipe(20);
//  rainbowRows(0);
//  rainbowCols(0);
  for(int i=0; i<5; i++)
    cursiveRainbow(20);
  cursiveWipe(0, 0);
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
//  int bucket = 255 / 6;
//  WheelPos = (WheelPos / bucket) * bucket;
//
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

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowRows(uint8_t wait) {
  uint16_t i, j, k;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < 29; i++) {
      for (k = 0; k< 29; k++) {
        strip.setPixelColor(mapping[i][k], Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
    }
    strip.show();
    delay(wait);
  }
}

void cursiveWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(cursive[i], c);
    strip.show();
    delay(wait);
  }
}

void cursiveRainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(cursive[i], Wheel(((i * 256 / strip.numPixels()) + 255 - j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void cursiveRainbowWipe(uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(cursive[i], Wheel(((i * 256 / strip.numPixels()) + 255) & 255));
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCols(uint8_t wait) {
  uint16_t i, j, k;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < 29; i++) {
      for (k = 0; k< 29; k++) {
        strip.setPixelColor(mapping[k][i], Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      }
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
