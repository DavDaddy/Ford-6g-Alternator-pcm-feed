# Ford-6g-Alternator-pcm-feed
This is an attempt to simulate the pcm signal and drive a Ford alternator outside of the vehicle

Modern Ford alternators (Gen 6, & the Gen 4 from 2003) need to receive a signal from the pcm (power train control module) inorder to generate any power.<br> <br>
This signal is pwm with a frequency of 125mhz and a duty cycle ranging from (5% for 12v) to (95% for 16v) output.  This is an Arduino sketch attempting to simulate that input signal 
using an Arduino Uno r3.
