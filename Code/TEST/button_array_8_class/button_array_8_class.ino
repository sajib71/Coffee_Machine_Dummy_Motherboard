/*
 * This example shows how to encapsulate codes in a class.
 * Created by: Wahidul Islam Rahim
 * https://github.com/wirahim
 * 
 */
#include "button_class.h"
#define buttonRow_1 7
#define buttonRow_2 8
#define buttonCol_1 4
#define buttonCol_2 5
#define buttonCol_3 6

Buttons button;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  button.begin(buttonCol_1, buttonCol_2, buttonCol_3, buttonRow_1, buttonRow_2);
}
void loop() {
  // put your main code here, to run repeatedly:
  button.loop();
  
  for (int i = 0; i < 6; i++){
    if(button.readShortPress(i)){
      Serial.print("Button ");
      Serial.print(i+1);
      Serial.println(" has been pressed!");
      button.clear(i);
    }
    else if(button.readLongPress(i)){
      Serial.print("Button ");
      Serial.print(i+1);
      Serial.println(" has been long pressed!");
      button.clear(i);
    }
  }

  delay(100);
}
