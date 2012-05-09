/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 
 */

#define NDIGIT 4
#define NSEQ 2
#define MIN_BRIGHT 75
#define MAX_BRIGHT 255

int brightness[4] = { 
  0,0,0,0} 
;    // how bright the LED is
int pin[4] = { 
  3, 5, 6, 9} 
;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

void setup()  { 
  for(int i=0; i<NDIGIT; i++) {
    pinMode(pin[i], OUTPUT);
  }
}

void loop()  { 
  for(int seq = 0; seq < NSEQ; seq++) {

    for(int i=0; i<NDIGIT; i++) {
      int b = MIN_BRIGHT;
      while(b < MAX_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b += fadeAmount;
        delay(10);   
      }
      while(b > MIN_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b -= fadeAmount;
        delay(10);   
      }

    }
    for(int i=NDIGIT-2; i>0; i--) {
      int b = MIN_BRIGHT;
      while(b < MAX_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b += fadeAmount;
        delay(10);   
      }
      while(b > MIN_BRIGHT) {
        // set the brightness of pin 9:
        analogWrite(pin[i], b);    
        // change the brightness for next time through the loop:
        b -= fadeAmount;
        delay(10);   
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
    delay(10);   
  }

  for(int i=0; i<NDIGIT; i++) {
    pinMode(pin[i], INPUT);
  }
  delay(1000);
}






