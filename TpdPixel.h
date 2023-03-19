/*
   TpdPixel.h - Simple intuitive Arduino library
   to read different events on a single button.

   Based on the work of Bill Earl:
   https://learn.adafruit.com/multi-tasking-the-arduino-part-3/put-it-all-together-dot-dot-dot

   Author: Ubaldo Andrea Desiato | theprototypedesigner
   Created: 18 Feb 2023
   Last update: 18 Mar 2023
*/

#ifndef TPD_PIXEL_H
#define TPD_PIXEL_H

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include "Colors.h"


class TpdPixel : public Adafruit_NeoPixel {

  private:
    enum  direction { FORWARD, REVERSE };
    enum  pattern { NONE, BLINK, PULSE, LOADING};
    
    pattern  _activePattern;   // which pattern is running
    direction _direction;      // direction to run the pattern
    unsigned long _interval;   // milliseconds between updates
    unsigned long _lastUpdate; // last update of position
    uint32_t _color;
    uint16_t _nSteps1;
    uint16_t _nSteps2;
    uint16_t _totalSteps;  // total number of steps in the pattern
    uint16_t _index;  // current step within the pattern
    bool _reverse = false;
    uint16_t _led;
    void reverse();
    void changeSteps();

  public:

    TpdPixel(uint16_t numLeds, uint8_t dataPin, uint8_t type, uint8_t brightness = 255);
    
    
    void update();
    void increment();
    
    void on(uint32_t color, uint16_t led = -1);
    void off(uint16_t led = -1);
    void blink(uint32_t color, uint16_t onTime,uint16_t offTime, uint16_t led = -1, direction dir = FORWARD);
    void blinkUpdate();
    void pulse(uint16_t hue, uint8_t interval, uint16_t led = -1, direction dir = FORWARD);
    void pulseUpdate();
};

#endif
