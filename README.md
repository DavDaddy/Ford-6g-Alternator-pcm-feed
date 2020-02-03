# Ford-6g-Alternator-pcm-feed
This is an attempt to simulate the pcm signal and drive a Ford alternator outside of the vehicle

Modern Ford alternators (Gen 6, & the Gen 4 from 2003) need to receive a signal from the pcm (power train control module) inorder to generate any power.<br> <br>
This signal is pwm with a frequency of 125mhz and a duty cycle ranging from (5% for 12v) to (95% for 16v) output.  This is an Arduino sketch attempting to simulate that input signal 
using an Arduino Uno r3.

*To make use of this sketch you will need to download and install the library located here: <a>https://github.com/jpmarques19/arduino-pwm-frequency</a><br> <br>

**Update the alternator I had intended to use with his has a bad voltage regulator. (I got it off of Craigslist for $8 so I can't say I'm shocked.) Given that I am unable to continue with this project at this time. :(
Hopefully I will be able to return to it in the near future, or someone comes along and incorporates it into something useful.  I had planned to add the following: <br> <br>

1.  Add potentiometer to adjust the duty cycle and output voltage instead of having to flash a fixed duty cycle onto the Arduino.<br> <br>

2.  Make use of the PWM signal put out by the alternaor's stator to enable automatic adjustments for steady voltage output under varying levels of load.<br> <br>

3.  Create and upload a gerber file and a component list so that a pcb can be easily created. 
