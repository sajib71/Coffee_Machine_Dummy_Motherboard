/*
 * 13 February, 2024
 * Code for using a 74HC595 Shift Register to count from 0 to 255
 */
 
//Pin connected to ST_CP of 74HC595
int latchPin = 5;
//Pin connected to SH_CP of 74HC595
int clockPin = 6;
////Pin connected to DS of 74HC595
int dataPin = 4;
void setup() {
//set pins to output so you can control the shift register
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}
void loop() {
// count from 0 to 255 and display the number
// on the LEDs
for (int numberToDisplay = 0; numberToDisplay < 256; numberToDisplay++) {
// take the latchPin low so
// the LEDs don't change while you're sending in bits:
  digitalWrite(latchPin, LOW);
// shift out the bits:
  shiftOut(dataPin, clockPin, MSBFIRST, numberToDisplay);
//take the latch pin high so the LEDs will light up:
  digitalWrite(latchPin, HIGH);
// pause before next value:
  delay(500);
}
}
