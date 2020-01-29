/*

 Mimics the fade example but with an extra parameter for frequency. It should dim but with a flicker 
 because the frequency has been set low enough for the human eye to detect. This flicker is easiest to see when 
 the LED is moving with respect to the eye and when it is between about 20% - 60% brighness. The library 
 allows for a frequency range from 1Hz - 2MHz on 16 bit timers and 31Hz - 2 MHz on 8 bit timers. When 
 SetPinFrequency()/SetPinFrequencySafe() is called, a bool is returned which can be tested to verify the 
 frequency was actually changed.
 
 This example runs on mega and uno.
 */

#include <PWM.h>

//use pin 11 on the Mega instead, otherwise there is a frequency cap at 31 Hz
int led = 9;                // the pin that the LED is attached to
int brightness = 255;         // how bright the LED is
int fadeAmount = 0;         // how many points to fade the LED by
int32_t frequency = 125; //frequency (in Hz)

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(led, frequency);
  
  //if the pin frequency was set successfully, turn pin 9 on
  if(success) {
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);    
  }
}

void loop()
{
  //use this functions instead of analogWrite on 'initialized' pins
  pwmWrite(led, brightness);

  brightness = 64;

  delay(30);      
}