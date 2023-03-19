/*
 * TpdPixel.cpp - Simple intuitive Arduino library
 * to read different events on a single button.
 * 
   Based on the work of Bill Earl:
   https://learn.adafruit.com/multi-tasking-the-arduino-part-3/put-it-all-together-dot-dot-dot
 * 
 * Author: Ubaldo Andrea Desiato | theprototypedesigner
 * Created: 18 Feb 2023
 * Last update: 19 Mar 2023
 */

#include "TpdPixel.h"


TpdPixel::TpdPixel(uint16_t numLeds, uint8_t dataPin, uint8_t type, uint8_t brightness):Adafruit_NeoPixel(numLeds, dataPin, type)
{
  begin();
  setBrightness(brightness);
  
}




//Set attributes

// Update the pattern
void TpdPixel::update()
    {
        if((millis() - _lastUpdate) > _interval) // time to update
        {
            _lastUpdate = millis();
            switch(_activePattern)
            {
                case BLINK:
                    blinkUpdate();
                    break;
                case PULSE:
                    pulseUpdate();
                    break;
                default:
                    break;
            }
        }
    }

    // Increment the Index and reset at the end
    void TpdPixel::increment()
    {
      
      //Serial.println("increment");
        if (_direction == FORWARD)
        {
           _index++;
           
           if (_index >= _totalSteps)
            {
              //Serial.println("here");
                _index = 0;
                if (_reverse == true)
                {
                    changeSteps();
                    reverse();
                }
            }
        }
        else // Direction == REVERSE
        {
            --_index;
            if (_index <= 0)
            {
                _index = _totalSteps-1;
                if (_reverse == true)
                {
                    changeSteps();
                    reverse();
                }
            }
        }
    }

    // Reverse pattern direction
    void TpdPixel::reverse()
    {
        if (_direction == FORWARD)
        {
            _direction = REVERSE;
            _index = _totalSteps-1;
        }
        else
        {
            _direction = FORWARD;
            _index = 0;
        }
    }
    
void TpdPixel::changeSteps() {
  if(_nSteps1!=_nSteps2) {
    _totalSteps=_totalSteps==_nSteps1?_nSteps2:_nSteps1;
  }
}

void TpdPixel::on(uint32_t color, uint16_t led) {
  _activePattern = NONE;
  led==-1?fill(color):setPixelColor(led,color);
  show();
}

void TpdPixel::off(uint16_t led) {
  _activePattern = NONE;
  led==-1?clear():setPixelColor(led,0);
  show();
}

void TpdPixel::blink(uint32_t color, uint16_t onTime,uint16_t offTime, uint16_t led, direction dir) {
  _activePattern = BLINK;
  _interval = 1;
  _color = color;
  _nSteps1 = onTime;
  _nSteps2 = offTime;
  _totalSteps = onTime;
  _index = 0;
  _direction = dir;
  _reverse = true;
  _led = led;
}


void TpdPixel::blinkUpdate() {
  if(_direction == FORWARD) {

    if(_led == -1) {
      for(int i=0;i<numPixels();i++) {
        setPixelColor(i,_color);
      }
    } else {
        setPixelColor(_led,_color);
    }
  }
  else {
    clear();
    //Serial.println("blink off");
  }
  show();
  increment();
}


void TpdPixel::pulse(uint16_t hue, uint8_t interval, uint16_t led, direction dir) {
  _activePattern = PULSE;
  _color = hue;
  _nSteps1 = _nSteps2 = _totalSteps = 255;
  _interval = interval;
  _index = 0;
  _direction = dir;
  _reverse = true;
  _led = led;
}

void TpdPixel::pulseUpdate() {
  if(_led==-1) {
    for(int i=0;i<numPixels();i++) {
      setPixelColor(i,ColorHSV(_color,255,_index));
    }
  } else {
    setPixelColor(_led,ColorHSV(_color,255,_index));
  }
  show();
  increment();
}
