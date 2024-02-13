/*
 * Date    : 14 February, 2024
 * Notes   : 74HC595 Shift Register to count from 0 to 255
 * Notes   : Using arrays, 8 elements and parameter in binary
 */
//Pin connected to ST_CP of 74HC595
int latchPin = 5;
//Pin connected to SH_CP of 74HC595
int clockPin = 6;
////Pin connected to DS of 74HC595
int dataPin = 4;
int binaryNumber [8] = {B00000100, B00000111, B00000101, B00000001, B00100000, B00111000, B00101000, B00001000};
int delayValues [4] = {500, 2000, 3000, 1000};

void setup() {
//set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
}
void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[0]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[0]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[1]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[1]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[2]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[2]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[3]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[3]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[4]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[0]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[5]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[1]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[6]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[2]);
  
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, MSBFIRST, binaryNumber[7]);
  digitalWrite(latchPin, HIGH);
  delay(delayValues[3]);
}
