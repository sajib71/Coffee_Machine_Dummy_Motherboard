#define buttonRow_1 7
#define buttonRow_2 8
#define buttonCol_1 4
#define buttonCol_2 5
#define buttonCol_3 6
byte buttonVal_1 = 0;
byte buttonVal_2 = 0;
byte buttonVal_3 = 0;
byte buttonVal_4 = 0;
byte buttonVal_5 = 0;
byte buttonVal_6 = 0;
byte *buttonValues [6] = {&buttonVal_1, &buttonVal_2, &buttonVal_3, 
                          &buttonVal_4, &buttonVal_5, &buttonVal_6};
byte button_config  [3] [5] = {{LOW, HIGH, HIGH, 0, 3},
                               {HIGH, LOW, HIGH, 1, 5},
                               {HIGH, HIGH, LOW, 2, 4}};
void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (buttonRow_1, INPUT);
  pinMode (buttonRow_2, INPUT);
  pinMode (buttonCol_1, OUTPUT);
  pinMode (buttonCol_2, OUTPUT);
  pinMode (buttonCol_3, OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  for (int i=0; i<3; i++){
    buttonRead(button_config[i][0], button_config[i][1], button_config[i][2], buttonValues[button_config[i][3]], buttonValues[button_config[i][4]]);
  }
  Serial.print("B ");
  for(int i = 0; i < 6; i++){
    Serial.print(*buttonValues[i]);
    if(i != 5) Serial.print(", ");
  }
  Serial.println();
  delay(100);
}
void buttonRead (bool col1_val, bool col2_val, bool col3_val, byte *val_1, byte *val_2){
  
  digitalWrite(buttonCol_1, col1_val);
  digitalWrite(buttonCol_2, col2_val);
  digitalWrite(buttonCol_3, col3_val);
  *val_1 = digitalRead (buttonRow_1);
  *val_2 = digitalRead (buttonRow_2);
}
