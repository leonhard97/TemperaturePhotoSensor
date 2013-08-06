/*
  Analog input, analog output, serial output
 
 Reads an analog input pin, maps the result to a range from 0 to 255
 and uses the result to set the pulsewidth modulation (PWM) of an output pin.
 Also prints the results to the serial monitor.
 
 The circuit:
 * potentiometer connected to analog pin 0.
   Center pin of the potentiometer goes to the analog pin.
   side pins of the potentiometer go to +5V and ground
 * LED connected from digital pin 9 to ground
 
 created 29 Dec. 2008
 modified 9 Apr 2012
 by Tom Igoe
 
 This example code is in the public domain.
 
 */

// These constants won't change.  They're used to give names
// to the pins used:

int photoValue = 0;        // value read from the pot
int LEDValue = 0;        // value output to the PWM (analog out)

int thermistorValue = 0;
int LED2Value = 0;


void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
}

void loop() {
  // read the analog in value:
  photoValue = analogRead(A0);            
  thermistorValue = analogRead(A1);
  
  // map it to the range of the analog out:
  
  LEDValue = map(photoValue, 450, 670, 0, 255);  
  LED2Value = map(thermistorValue, 580,450, 0 ,255);
  
  // change the analog out value:
  analogWrite(9, LEDValue);           
  analogWrite(5, LED2Value);
  
  // print the results to the serial monitor:
  Serial.print("Photosensor = " );                       
  Serial.print(photoValue);      
  Serial.print("\t output = ");      
  Serial.println(LEDValue);   
Serial.print("Temperature sensor = " );                       
  Serial.print(thermistorValue);      
  Serial.print("\t output = ");      
  Serial.println(LED2Value);   
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);                     
}
