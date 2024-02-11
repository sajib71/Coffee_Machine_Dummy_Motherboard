class Buttons{
  byte buttonTCount[6] = {0};
  byte buttonLVal[6] = {1, 1, 1, 1, 1, 1};
  byte buttonVal[6] = {0};
  byte *buttonValues [6] = {&buttonVal[0], &buttonVal[1], &buttonVal[2], &buttonVal[3], &buttonVal[4], &buttonVal[5]};
  byte button_config  [3] [5] = {{LOW, HIGH, HIGH, 0, 3}, {HIGH, LOW, HIGH, 1, 5}, {HIGH, HIGH, LOW, 2, 4}};
  byte rowPin1 = 0;
  byte rowPin2 = 0;
  byte colPin1 = 0;
  byte colPin2 = 0;
  byte colPin3 = 0;
  byte buttonPVal[6] = {0};

  void buttonRead (bool col1_val, bool col2_val, bool col3_val, byte *val_1, byte *val_2){
    digitalWrite(colPin1, col1_val);
    digitalWrite(colPin2, col2_val);
    digitalWrite(colPin3, col3_val);
    *val_1 = digitalRead (rowPin1);
    *val_2 = digitalRead (rowPin2);
  }
  public:
  void begin(byte cpin1, byte cpin2, byte cpin3, byte rpin1, byte rpin2){
    rowPin1 = rpin1;
    rowPin2 = rpin2;
    colPin1 = cpin1;
    colPin2 = cpin2;
    colPin3 = cpin3;
    pinMode (rowPin1, INPUT);
    pinMode (rowPin2, INPUT);
    pinMode (colPin1, OUTPUT);
    pinMode (colPin2, OUTPUT);
    pinMode (colPin3, OUTPUT);
  }
  void loop(){
    for (int i=0; i<3; i++){
      buttonRead(button_config[i][0], button_config[i][1], button_config[i][2], buttonValues[button_config[i][3]], buttonValues[button_config[i][4]]);
    }
    for(int i = 0; i < 6; i++){
      byte current_value = *buttonValues[i];
      if(buttonLVal[i] == LOW && current_value == HIGH) {
        if(buttonTCount[i]>10)  buttonPVal[i] = 2;
        else                    buttonPVal[i] = 1;
        buttonTCount[i] = 0;
        buttonLVal[i] = HIGH;
      }
      if(current_value == LOW) {
        buttonLVal[i] = LOW;
        buttonTCount[i]++;
      }
    }
  }
  bool readShortPress(byte button){
    return buttonPVal[button] == 1 ? true : false;
  }
  bool readLongPress(byte button){
    return buttonPVal[button] == 2 ? true : false;
  }
  void clearAll(){
    for (int i = 0; i < 6; i++){
      buttonPVal[i] = 0;
    }
  }
  void clear(byte button){
      buttonPVal[button] = 0;
  }
};
