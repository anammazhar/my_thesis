#include <Mouse.h>


// set pin numbers for the five buttons:
const int upButton = 2;     
const int downButton = 3;        
const int leftButton = 4;
const int rightButton = 5;
const int mouseButton = 6;
  int upState;  int downState;
 int rightState;  int leftState ;
  int clickState ;
int range = 5;              // output range of X or Y movement; affects movement speed
int responseDelay = 10;     // response delay of the mouse, in ms
char getData;

#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
void setup() {
  // initialize the buttons' inputs:
  pinMode(upButton, INPUT_PULLUP);       
  pinMode(downButton, INPUT_PULLUP);       
  pinMode(leftButton, INPUT_PULLUP);       
  pinMode(rightButton, INPUT_PULLUP);       
  pinMode(mouseButton, INPUT_PULLUP);
mySerial.begin(9600);
    Mouse.begin();
}

void loop() {
  // read the buttons:

 if(digitalRead(upButton) == LOW){
      if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT); 
  delay(1000);
      Mouse.release(MOUSE_LEFT); 
  
  }
//  } 
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT); 
    }  
  }
  delay(100);
 while(digitalRead(upButton) == LOW);
 delay(500); 
 }
 if(digitalRead(downButton) == LOW){
   if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT); 
  delay(1000);
      Mouse.release(MOUSE_RIGHT); 
   }
   
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.release(MOUSE_RIGHT); 
    }
  }
 while(digitalRead(downButton) == LOW);
 delay(500); 
 }


if(mySerial.available() > 0){
getData = mySerial.read();  
if(getData == '1') {
upState =1;}
if(getData == '2') {
downState =1;}
if(getData == '3') {
rightState =1;}
if(getData == '4') {
leftState =1;}
if(getData == '5') {
clickState = 1;}

///*

delay(1000);



if(getData == '6')  {
     if (!Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.press(MOUSE_LEFT); 
  delay(1000);
      Mouse.release(MOUSE_LEFT); 
  
  }
//  } 
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_LEFT)) {
      Mouse.release(MOUSE_LEFT); 
    }  
  }
 // delay(100);
  
 }

if(getData == '7') {
  if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT); 
  delay(1000);
      Mouse.release(MOUSE_RIGHT); 
   }
   
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
    if (Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.release(MOUSE_RIGHT); 
    }
  }    
 }
 //*/
}


//  int upState = digitalRead(upButton);
//  int downState = digitalRead(downButton);
//  int rightState = digitalRead(rightButton);
//  int leftState = digitalRead(leftButton);
//  int clickState = digitalRead(mouseButton);

  // calculate the movement distance based on the button states:
  int  xDistance = (leftState - rightState)*range;
  int  yDistance = (upState - downState)*range;

  // if X or Y is non-zero, move:
  if ((xDistance != 0) || (yDistance != 0)) {
    Mouse.move(xDistance, yDistance, 0);
  }

  // if the mouse button is pressed:
  if (clickState == HIGH) {
    // if the mouse is not pressed, press it:
    if (!Mouse.isPressed(MOUSE_RIGHT)) {
      Mouse.press(MOUSE_RIGHT); 
    }
  } 
  // else the mouse button is not pressed:
  else {
    // if the mouse is pressed, release it:
   // if (Mouse.isPressed(MOUSE_RIGHT)) {
   //   Mouse.release(MOUSE_RIGHT); 
   // }
  }

  // a delay so the mouse doesn't move too fast:
  delay(responseDelay);
   upState=0;   downState=0;
  rightState=0;   leftState=0 ;
   clickState= 0;
getData=0;
}
