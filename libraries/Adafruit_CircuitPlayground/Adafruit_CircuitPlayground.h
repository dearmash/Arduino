/*------------------------------------------------------------------------
  This file is part of the Adafruit Dot Star library.

  Adafruit Dot Star is free software: you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public License
  as published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  Adafruit Dot Star is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with DotStar.  If not, see <http://www.gnu.org/licenses/>.
  ------------------------------------------------------------------------*/

#include "utility/Adafruit_CPlay_NeoPixel.h"
#include "utility/Adafruit_CPlay_LIS3DH.h"
#include "utility/CPlay_CapacitiveSensor.h"

#ifndef _ADAFRUIT_CIRCUITPLAYGROUND_H_
#define _ADAFRUIT_CIRCUITPLAYGROUND_H_


#define CPLAY_REDLED 13
#define CPLAY_NEOPIXELPIN 17
#define CPLAY_SLIDESWITCHPIN 21
#define CPLAY_LEFTBUTTON 4
#define CPLAY_RIGHTBUTTON 19
#define CPLAY_LIGHTSENSOR A5
#define CPLAY_LIS3DH_CS 8
#define CPLAY_THERMISTORPIN A0
#define CPLAY_SOUNDSENSOR A4
#define CPLAY_BUZZER 5
#define CPLAY_CAPSENSE_SHARED 30

#define SERIESRESISTOR 10000
// resistance at 25 degrees C
#define THERMISTORNOMINAL 10000
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25

// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor


#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif

class Adafruit_CircuitPlayground {
 public:
  boolean begin(uint8_t brightness=20);

  Adafruit_CPlay_NeoPixel strip;
  Adafruit_CPlay_LIS3DH lis;
  CPlay_CapacitiveSensor cap[8];

  boolean slideSwitch(void);
  void redLED(boolean v);
  void playTone(uint16_t freq, uint16_t time);
  boolean leftButton(void);
  boolean rightButton(void);
  uint16_t lightSensor(void);
  uint16_t soundSensor(void);
  float temperature(void);
  float temperatureF(void);

  uint16_t readCap(uint8_t p, uint8_t samples=10);

  float motionX(void);
  float motionY(void);
  float motionZ(void);

  // neopixels
  void clearPixels(void) { strip.clear(); strip.show(); }
  void setPixelColor(uint8_t p, uint32_t c) {strip.setPixelColor(p, c); strip.show();}
  void setPixelColor(uint8_t p, uint8_t r, uint8_t g, uint8_t b) {strip.setPixelColor(p, r, g, b); strip.show();}

  uint32_t colorWheel(uint8_t x);
 private:


};



extern Adafruit_CircuitPlayground CircuitPlayground;

#endif
