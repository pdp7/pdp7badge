/*
Sketch: pdp7badge
Author: Drew Fustini
Date: 2012-06-19
URL: http://www.element14.com/community/blogs/pdp7/tags/pdp7badge
Desc: Twitter name badge displaying "PdP7".  Pot controls speed of illumination pattern.   Based on Fade example from Arduino IDE
*/

#define NDIGIT 4
#define NSEQ 2
#define MIN_BRIGHT 75
#define MAX_BRIGHT 255
#define ANALOG_IN_PIN 0

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int fadeAmount = 5;    // how many points to fade the LED by

int brightness[4] = { 0,0,0,0}; // how bright the each LED is
int pin[4] = { 3, 5, 6, 9};    // how bright the LED is


void setup()  { 
  Serial.begin(9600); 
}

int readDelay() {
  int sensorValue = analogRead(ANALOG_IN_PIN);            
  // map it to the range of the analog out:
  int delayAmount = map(sensorValue, 0, 1023, 1, 20);  
  return delayAmount;
}

void loop()  { 

  int delayAmount = 0;
  
  
  for(int seq = 0; seq < NSEQ; seq++) {

    for(int i=0; i<NDIGIT; i++) {
      delayAmount = readDelay();            
      int b = MIN_BRIGHT;
      while(b < MAX_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b += fadeAmount;
        delay(delayAmount);   
      }
      while(b > MIN_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b -= fadeAmount;
        delay(delayAmount);   
      }
    }
    
    for(int i=NDIGIT-2; i>0; i--) {
      delayAmount = readDelay();      
      int b = MIN_BRIGHT;
      while(b < MAX_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b += fadeAmount;
        delay(delayAmount);   
      }
      while(b > MIN_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b -= fadeAmount;
        delay(delayAmount);   
      }
    }
  }
  
  int b=MIN_BRIGHT;
  while(b > 0) {
    // set the brightness of pin 9:
    for(int i=0; i<NDIGIT; i++) {
      analogWrite(pin[i], b);    
    }
    // change the brightness for next time through the loop:
    b -= fadeAmount;
    delay(delayAmount);   
  }

  for(int i=0; i<NDIGIT; i++) {
    pinMode(pin[i], INPUT);
  }
  delay(10*delayAmount);
}
