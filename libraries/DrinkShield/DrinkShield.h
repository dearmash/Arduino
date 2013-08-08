/*
  DrinkShield.h - Library for the GfxHax DrinkShield
  Created by Craig Smith August 18, 2010 <craig@gfxhax.com>
  Release into the public domain.
*/

#ifndef DrinkShield_h
#define DrinkShield_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
  #include <pins_arduino.h>
#endif


const int ON = 1;
const int OFF = 0;

class DrinkShield
{
  public:
	DrinkShield(int, int);
	char *version;
	int playerReady;
	void refreshLights();
	void updatePlayerLights();
	void setPlayerLights(int, int);
	void redLight(int);
	void greenLight(int);
	void lightBarLevel(int, int);
	void lightTest();
	void pollSerial();
	void autocalibrate(int);
	int getReading();
	bool isClear();
	int getLightLevel(int);
  private:
	int _mq3pin;
	int _shield_version;
	int _SHpin;
	int _STpin;
	int _DSpin;
	int _blinkCnt;
	int _numLights;

	int _highscore;
	int _startrecording;
	int _baseline;
	int _startTime;

	int _highscoreLevel;
	int _currentLevel;
	int _greenLightState;
	int _redLightState;

};

#endif /* DrinkShield_h */
