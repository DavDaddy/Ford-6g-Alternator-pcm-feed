/*
 This sketch is intended to enable any Ford gen6, or Ford pcm type alternator to function and generate electricity without being attached to the vehicles pcm (Power train, Control Module), Ford speak for an ECU.

 The library allows for a frequency range from 1Hz - 2MHz on 16 bit timers and 31Hz - 2 MHz on 8 bit timers although all Ford pcm's to date run at 125hz. 

When 

 SetPinFrequency()/SetPinFrequencySafe()

is called, a bool is returned which can be tested to verify the 
frequency was actually changed.
 
 This example runs on mega and uno.
 */

#include <PWM.h>

//use pin 11 on the Mega instead, otherwise there is a frequency cap at 31 Hz
int pcm = 9;               
 //the pin that is attached to the Alternator
int dutycycle = 242;         
// Working with a scale from 0-255 where 0 = 0%, and 255 = 100% the acceptable input range is from 13-242 (5%-95%) for a generated 12v-16v
int fadeAmount = 0;         
//Not currently being used
int32_t frequency = 125; 
//Standard Ford pcm frequency (in Hz)

void setup()
{
  //initialize all timers except for 0, to save time keeping functions
  InitTimersSafe(); 

  //sets the frequency for the specified pin
  bool success = SetPinFrequencySafe(pcm, frequency);
  
  //if the pin frequency was set successfully, turn pin 9 on
  if(success) {
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);    
  }
}

void loop()
{
  //use this functions instead of analogWrite on 'initialized' pins
  pwmWrite(pcm, dutycycle);

  dutycycle = 13;
  //5% = 13 outputs 12v
  //30% = 76 outputs 13v
  //50% = 128 outputs 14v
  //95% = 242 outputs 16v
  

  delay(30);      
}
