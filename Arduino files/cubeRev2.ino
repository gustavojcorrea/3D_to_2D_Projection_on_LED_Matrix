
/*****************************************************************************/
//Team:    Gustavo Correa, Elijah Marchese, Jiunne Stow
//Project: LED Matrix 3D Projection Mapping
//Date:    April 3, 2016
//Event:   BeachHacks
/*******************************************************************************/
#include <MAX7219.h>

int data = 5;    // DIN pin of MAX7219 module
int load = 6;    // CS pin of MAX7219 module
int clock = 7;  // CLK pin of MAX7219 module

byte char_code[95][6] = {
{B00000000, B00000000, B00000000, B00000000, B00000000, B00000000}, // space
{B01011111, B00000000, B00000000, B00000000, B00000000, B00000000}, // !
{B00000011, B00000000, B00000011, B00000000, B00000000, B00000000}, // "
{B00010100, B00111110, B00010100, B00111110, B00010100, B00000000}, // #
{B00100100, B01101010, B00101011, B00010010, B00000000, B00000000}, // $
{B01100011, B00010011, B00001000, B01100100, B01100011, B00000000}, // %
{B00110110, B01001001, B01010110, B00100000, B01010000, B00000000}, // &
{B00000011, B00000000, B00000000, B00000000, B00000000, B00000000}, // '
{B00011100, B00100010, B01000001, B00000000, B00000000, B00000000}, // (
{B01000001, B00100010, B00011100, B00000000, B00000000, B00000000}, // )
{B00101000, B00011000, B00001110, B00011000, B00101000, B00000000}, // *
{B00001000, B00001000, B00111110, B00001000, B00001000, B00000000}, // +
{B10110000, B01110000, B00000000, B00000000, B00000000, B00000000}, // ,
{B00001000, B00001000, B00001000, B00001000, B00000000, B00000000}, // -
{B01100000, B01100000, B00000000, B00000000, B00000000, B00000000}, // .
{B01100000, B00011000, B00000110, B00000001, B00000000, B00000000}, // /
{B00111110, B01000001, B01000001, B00111110, B00000000, B00000000}, // 0
{B01000010, B01111111, B01000000, B00000000, B00000000, B00000000}, // 1
{B01100010, B01010001, B01001001, B01000110, B00000000, B00000000}, // 2
{B00100010, B01000001, B01001001, B00110110, B00000000, B00000000}, // 3
{B00011000, B00010100, B00010010, B01111111, B00000000, B00000000}, // 4
{B00100111, B01000101, B01000101, B00111001, B00000000, B00000000}, // 5
{B00111110, B01001001, B01001001, B00110000, B00000000, B00000000}, // 6
{B01100001, B00010001, B00001001, B00000111, B00000000, B00000000}, // 7
{B00110110, B01001001, B01001001, B00110110, B00000000, B00000000}, // 8
{B00000110, B01001001, B01001001, B00111110, B00000000, B00000000}, // 9
{B00010100, B00000000, B00000000, B00000000, B00000000, B00000000}, // :
{B10000000, B01010000, B00000000, B00000000, B00000000, B00000000}, // ;
{B00001000, B00010100, B00100010, B00000000, B00000000, B00000000}, // <
{B00010100, B00010100, B00010100, B00000000, B00000000, B00000000}, // =
{B00100010, B00010100, B00001000, B00000000, B00000000, B00000000}, // >
{B00000010, B01011001, B00001001, B00000110, B00000000, B00000000}, // ?
{B00111110, B01001001, B01010101, B01011101, B00001110, B00000000}, // @
{B01111110, B00010001, B00010001, B01111110, B00000000, B00000000}, // A
{B01111111, B01001001, B01001001, B00110110, B00000000, B00000000}, // B
{B00111110, B01000001, B01000001, B00100010, B00000000, B00000000}, // C
{B01111111, B01000001, B01000001, B00111110, B00000000, B00000000}, // D
{B01111111, B01001001, B01001001, B01000001, B00000000, B00000000}, // E
{B01111111, B00001001, B00001001, B00000001, B00000000, B00000000}, // F
{B00111110, B01000001, B01001001, B01111010, B00000000, B00000000}, // G
{B01111111, B00001000, B00001000, B01111111, B00000000, B00000000}, // H
{B01000001, B01111111, B01000001, B00000000, B00000000, B00000000}, // I
{B00110000, B01000000, B01000001, B00111111, B00000000, B00000000}, // J
{B01111111, B00001000, B00010100, B01100011, B00000000, B00000000}, // K
{B01111111, B01000000, B01000000, B01000000, B00000000, B00000000}, // L
{B01111111, B00000010, B00001100, B00000010, B01111111, B00000000}, // M
{B01111111, B00000100, B00001000, B00010000, B01111111, B00000000}, // N
{B00111110, B01000001, B01000001, B00111110, B00000000, B00000000}, // O
{B01111111, B00001001, B00001001, B00000110, B00000000, B00000000}, // P
{B00111110, B01000001, B01000001, B10111110, B00000000, B00000000}, // Q
{B01111111, B00001001, B00001001, B01110110, B00000000, B00000000}, // R
{B01000110, B01001001, B01001001, B00110010, B00000000, B00000000}, // S
{B00000001, B00000001, B01111111, B00000001, B00000001, B00000000}, // T
{B00111111, B01000000, B01000000, B00111111, B00000000, B00000000}, // U
{B00001111, B00110000, B01000000, B00110000, B00001111, B00000000}, // V
{B00111111, B01000000, B00111000, B01000000, B00111111, B00000000}, // W
{B01100011, B00010100, B00001000, B00010100, B01100011, B00000000}, // X
{B00000111, B00001000, B01110000, B00001000, B00000111, B00000000}, // Y
{B01100001, B01010001, B01001001, B01000111, B00000000, B00000000}, // Z
{B01111111, B01000001, B00000000, B00000000, B00000000, B00000000}, // [
{B00000001, B00000110, B00011000, B01100000, B00000000, B00000000}, // \ backslash
{B01000001, B01111111, B00000000, B00000000, B00000000, B00000000}, // ]
{B00000010, B00000001, B00000010, B00000000, B00000000, B00000000}, // hat
{B01000000, B01000000, B01000000, B01000000, B00000000, B00000000}, // _
{B00000001, B00000010, B00000000, B00000000, B00000000, B00000000}, // `
{B00100000, B01010100, B01010100, B01111000, B00000000, B00000000}, // a
{B01111111, B01000100, B01000100, B00111000, B00000000, B00000000}, // b
{B00111000, B01000100, B01000100, B00101000, B00000000, B00000000}, // c
{B00111000, B01000100, B01000100, B01111111, B00000000, B00000000}, // d
{B00111000, B01010100, B01010100, B00011000, B00000000, B00000000}, // e
{B00000100, B01111110, B00000101, B00000000, B00000000, B00000000}, // f
{B10011000, B10100100, B10100100, B01111000, B00000000, B00000000}, // g
{B01111111, B00000100, B00000100, B01111000, B00000000, B00000000}, // h
{B01000100, B01111101, B01000000, B00000000, B00000000, B00000000}, // i
{B01000000, B10000000, B10000100, B01111101, B00000000, B00000000}, // j
{B01111111, B00010000, B00101000, B01000100, B00000000, B00000000}, // k
{B01000001, B01111111, B01000000, B00000000, B00000000, B00000000}, // l
{B01111100, B00000100, B01111100, B00000100, B01111000, B00000000}, // m
{B01111100, B00000100, B00000100, B01111000, B00000000, B00000000}, // n
{B00111000, B01000100, B01000100, B00111000, B00000000, B00000000}, // o
{B11111100, B00100100, B00100100, B00011000, B00000000, B00000000}, // p
{B00011000, B00100100, B00100100, B11111100, B00000000, B00000000}, // q
{B01111100, B00001000, B00000100, B00000100, B00000000, B00000000}, // r
{B01001000, B01010100, B01010100, B00100100, B00000000, B00000000}, // s
{B00000100, B00111111, B01000100, B00000000, B00000000, B00000000}, // t
{B00111100, B01000000, B01000000, B01111100, B00000000, B00000000}, // u
{B00011100, B00100000, B01000000, B00100000, B00011100, B00000000}, // v
{B00111100, B01000000, B00111100, B01000000, B00111100, B00000000}, // w
{B01000100, B00101000, B00010000, B00101000, B01000100, B00000000}, // x
{B10011100, B10100000, B10100000, B01111100, B00000000, B00000000}, // y
{B01100100, B01010100, B01001100, B00000000, B00000000, B00000000}, // z
{B00001000, B00110110, B01000001, B00000000, B00000000, B00000000}, // {
{B01111111, B00000000, B00000000, B00000000, B00000000, B00000000}, // |
{B01000001, B00110110, B00001000, B00000000, B00000000, B00000000}, // }
{B00001000, B00000100, B00001000, B00000100, B00000000, B00000000} // ~
};

MAX7219 dotMatrix(5, data, load, clock);

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

  dotMatrix.begin();
  dotMatrix.scanlimit(0x07);      
  dotMatrix.decodemode(0x00);
  dotMatrix.shutdown(0x01);    
  dotMatrix.displaytest(0x00); 
  dotMatrix.intensity(0x0f);
  dotMatrix.noop(0x00);
  dotMatrix.clear();

  
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
  setStringWithShift("BEACH HACKS 2016 RULES!!!");
  //delay(100);
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



void setStringWithShift(char* input)
{
  dotMatrix.clear();
  dotMatrix.reload();
  int16_t string_size = -stringSize(input);
  int16_t column = 5*8;
  for (; column>string_size; column--)
  {
    setString(input, column);
    dotMatrix.reload();
    delay(100);
  }
}


void setString(char* input, int16_t column)
{
  int16_t column_value = column;
  while (*input != 0)
  {
    byte output = *input - 0x20;
    for (int y=0; y<6; y++)
    {
      boolean send = true;
      if (char_code[output][y]==B00000000)
        if (char_code[output][y-1]==B00000000)
          send = false;
      
      if (send)
      {
        dotMatrix.setData(column_value,char_code[output][y]);
        column_value++;
      }
    } 
    if (output==0x00)
      for (int y=0; y<3; y++)
      {
        dotMatrix.setData(column_value,char_code[output][y]);
        column_value++;
      }
    input++;
  }
}

int stringSize(char* input)
{
  int returnX = 0;
  while (*input != 0)
  {
    byte output = *input - 0x20;
    for (int y=0; y<6; y++)
    {
      boolean send = true;
      if (char_code[output][y]==B00000000)
        if (char_code[output][y-1]==B00000000)
          send = false;
      
      if (send)
        returnX++;
    } 
    if (output==0x00)
      returnX = returnX+3;
    input++;
  }
  return (returnX);
}
