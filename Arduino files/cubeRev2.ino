
/*****************************************************************************/
//Team:    Gustavo Correa, Elijah Marchese, Jiunne Stow
//Project: LED Matrix 3D Projection Mapping
//Date:    April 3, 2016
//Event:   BeachHacks
/*******************************************************************************/

#include <Wire.h>
#include "MMA7660.h"
MMA7660 accelemeter;

int clockPin  = 10;   int latchPin  = 9;   int dataPin  = 8;
int clockPinx = 13;   int latchPinx = 12;  int dataPinx = 11;

byte getColByte(int number);
byte getRowByte(int number);
void SetStates (byte statesx);
void GroundCorrectLED (byte states);
void lightLed(int, int);
void resetReg();

int getXPoint(double xAngl, double yAngl);
int getYPoint(double xAngl, double zAngl);
void getXY(const double& xVal,const double& yVal, int& xCoord, int& yCoord );

void outputHorizontal(int, int);

void setup()
{
  pinMode(latchPinx, OUTPUT);   pinMode(clockPinx, OUTPUT);   pinMode(dataPinx, OUTPUT);
  pinMode(latchPin, OUTPUT);    pinMode(clockPin, OUTPUT);    pinMode(dataPin, OUTPUT);
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, B11111111);  
  digitalWrite(latchPin, HIGH);
  
  accelemeter.init();  
  Serial.begin(9600);
}

void loop()
{
  int8_t x, y, z = 0;
  double avgX,avgY,avgZ = 0;

  int counter = 10;
  for(int i = 0; i < counter; ++i)
{
  accelemeter.getXYZ(&x,&y,&z);

  avgX += x;
  avgY += y;
  avgZ += z;
}

    avgX = (avgX/counter) - 4;
    avgY /= counter;
    avgZ /= counter;

  int xCoord, yCoord = 0;
  Serial.print("x = "); Serial.println(avgX);
  Serial.print("y = "); Serial.println(avgY);
  
  getXY(avgX, avgY, xCoord, yCoord );

  Serial.print("    xCoord = ");  Serial.println(xCoord);
  Serial.print("    yCoord = ");  Serial.println(yCoord);  
  Serial.println("*******");

  lightLed(xCoord,yCoord);
  delay(100);
}


//converts sensor data to x&y coordinates
void getXY(const double& xVal,const double& yVal, int& xCoord, int& yCoord )
{
  double x = map(xVal,-22,22,0,80);
  double y = map(yVal,-22,22,0,80);

  double xPosBound[10] = {0,10,20,30,40,50,60,70,80,90};
  int xPos[8] = {0,1,2,3,4,5,6,7};
  
  double yPosBound[7] = {0,20,40,60,80,100,120};
  int yPos[6] = {0,1,2,3,4,5};

  for(int i = 0; i < 10; ++i)
  {
    if(x >= xPosBound[i] && x < xPosBound[i + 1])
      xCoord = xPos[8-i-1];
  }
  for(int i = 0; i < 7; ++i)
  {
    if(y >= yPosBound[i] && y < yPosBound[i + 1])
      yCoord = yPos[i];
  }

  
}

//General light specific LED 
void lightLed(int C, int R)
{
      byte LED = getColByte(C);
      byte gLED = getRowByte(R);

      SetStates(LED);
      GroundCorrectLED (gLED);
}

//sets the states for the cathode pins
void GroundCorrectLED (byte states){
  
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, states);  
    digitalWrite(latchPin, HIGH);
    
}

//sets the states for the cathode pins
void SetStates (byte statesx){
       
    digitalWrite(latchPinx, LOW);
    shiftOut(dataPinx, clockPinx, LSBFIRST, statesx);  
    digitalWrite(latchPinx, HIGH);
    
     }

//gets binary representation for column byte
byte getColByte(int number){
  
  if(number == 0)
      return B10000000;
  if(number == 1)
      return B01000000;
  if(number == 2)
      return B00100000;
  if(number == 3)
      return B00010000;
      
  if(number == 4)
      return B00001000;
  if(number == 5)
      return B00000100;
  if(number == 6)
      return B00000010;
  if(number == 7)
      return B00000001; 

   return B00000000;
}

//gets binary representation for row byte
byte getRowByte(int number){
  if(number == 0)
      return B01111000;
  if(number == 1)
      return B10111000;
  if(number == 2)
      return B11011000;
  if(number == 3)
      return B11101000;
      
  if(number == 4)
      return B11110000;

   return B11111111;
}

//turns all bits low
void resetReg()
{
  byte ledState = 00000000;
  byte gLedState = 00000000;

  GroundCorrectLED(gLedState);
  SetStates(ledState);

  return;
}
