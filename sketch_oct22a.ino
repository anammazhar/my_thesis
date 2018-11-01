
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX

// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = A0;                  // x-axis of the accelerometer
const int ypin = A1;                  // y-axis
const int zpin = A2;                  // z-axis (only on 3-axis models)
int  xval,yval;
int b1 = 2;
int b2 = 3;
int led = 13;

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);
    mySerial.begin(9600);
  pinMode(b1, INPUT_PULLUP);
  pinMode(b2, INPUT_PULLUP);
  pinMode(led, OUTPUT);     

  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
 // pinMode(groundpin, OUTPUT);
 // pinMode(powerpin, OUTPUT);
 // digitalWrite(groundpin, LOW); 
 // digitalWrite(powerpin, HIGH);
}

void loop()
{
//delay(500); slow  
  if(digitalRead(b1) == LOW)
  { 
     digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
 
 mySerial.print("6");
Serial.print("6");
delay(500);
// while(digitalRead(b1) == LOW){delay(100); } 
 digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
delay(500);
  }  
  if(digitalRead(b2) == LOW)
  { 
 digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  mySerial.print("7");
Serial.print("7");
delay(500);
// while(digitalRead(b2) == LOW){delay(100); } 
 digitalWrite(led, LOW);   // turn the LED on (HIGH is the voltage level)
delay(500);
  }  
  
  xval=analogRead(xpin);
  Serial.print(xval);
  Serial.print("\t");
  yval=analogRead(ypin);
Serial.print(yval);
  // print a tab between values:
  Serial.print("\t");
//  Serial.print(analogRead(zpin));
  Serial.println();
  // delay before next reading:
///*
if(xval>260 && xval<330){
  Serial.print("RIGHT ");Serial.println();
      Serial.print("3 ");//Serial.println();
     mySerial.print("3");

}else
if(xval>360 && xval<440){
  Serial.print("LEFT ");Serial.println();
 Serial.print("4 ");///Serial.println();
 mySerial.print("4");

}else
if(yval>260 && yval<330){
      Serial.print("up ");Serial.println();
      Serial.print("1 ");//Serial.println();
 mySerial.print("1");
 }else
if(yval>360 && yval<440){
      Serial.print("dwn ");Serial.println();
      Serial.print("2 ");//Serial.println();
 mySerial.print("2");
}else{
//Serial.print("6 ");
}
//*/

 // delay(1000);
}
