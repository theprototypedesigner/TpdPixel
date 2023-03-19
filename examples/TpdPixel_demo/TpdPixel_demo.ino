#include "TpdPixel.h"


//Initialize your leds
//parameters are (number of pixels, pin attached to strip, type of driver)
//TpdPixel strip(12,3,NEO_GRB + NEO_KHZ800);

//you can add a fourth parameter which is the max brightness for the strip. Maximum is 255 which is teh default if not specified
TpdPixel strip(12,3,NEO_GRB + NEO_KHZ800,60);


void setup() {
  
  //turn off the whole strip
  strip.off();

  //turns on the strip in orange, you can also specify your color by using strip.Color(r,g,b)
  strip.on(ORANGE);
  
  //a second parameter turns on only the specified led
  //strip.on(WHITE,4);

  
  //turns off the strip
  //strip.off();
  
  //a second parameter turns off only the specified led
  //strip.off(4);

  //blink the strip in red 
  //strip.blink(RED,500,1000);

  //a fourth parameter blinks only the specified led
  //strip.blink(RED,500,1000,6);

  //make the strip pulsing in blue using the hsv colors, the second parameter specify the speed of the animation
  //strip.pulse(hsvBLUE,5);

  //a third parameter makes only the specified led pulsing
  //strip.pulse(hsvBLUE,5,10);
  
}

void loop() {

  strip.update(); //to update the chosen pattern

  

}
