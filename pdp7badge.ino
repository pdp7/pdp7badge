/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 
 */

#define NDIGIT 4
#define NSEQ 2
#define MIN_BRIGHT 75

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to


int sensorValue = 0;        // value read from the pot
int max_brightness = 0;        // value output to the PWM (analog out)


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
    digitalWrite(pin[i], HIGH);
  }
  delay(5000);
  Serial.begin(9600); 
}

void readMax() {
  sensorValue = analogRead(analogInPin);            
  // map it to the range of the analog out:
  max_brightness = map(sensorValue, 0, 1023, 0, 255);  
   // print the results to the serial monitor:
  Serial.print("sensor = " );                       
  Serial.print(sensorValue);      
  Serial.print("\t output = ");      
  Serial.println(max_brightness); 
}

void loop()  { 
  


  for(int seq = 0; seq < NSEQ; seq++) {

    for(int i=0; i<NDIGIT; i++) {
      readMax();      
      int b = MIN_BRIGHT;
      while(b < max_brightness) {
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
      while(b < max_brightness) {
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
  delay(500);
}






