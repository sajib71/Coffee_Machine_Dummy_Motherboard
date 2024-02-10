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
  digitalWrite(buttonCol_1, LOW);
  digitalWrite(buttonCol_2, HIGH);
  digitalWrite(buttonCol_3, HIGH);
  buttonVal_1 = digitalRead (buttonRow_1);
  buttonVal_4 = digitalRead (buttonRow_2);
  digitalWrite(buttonCol_1, HIGH);
  digitalWrite(buttonCol_2, LOW);
  digitalWrite(buttonCol_3, HIGH);
  buttonVal_2 = digitalRead (buttonRow_1);
  buttonVal_6 = digitalRead (buttonRow_2);
  digitalWrite(buttonCol_1, HIGH);
  digitalWrite(buttonCol_2, HIGH);
  digitalWrite(buttonCol_3, LOW);
  buttonVal_3 = digitalRead (buttonRow_1);
  buttonVal_5 = digitalRead (buttonRow_2);
  Serial.print("B ");
  Serial.print(buttonVal_1);
  Serial.print(" ");
  Serial.print(buttonVal_2);
  Serial.print(" ");
  Serial.print(buttonVal_3);
  Serial.print(" ");
  Serial.print(buttonVal_4);
  Serial.print(" ");
  Serial.print(buttonVal_5);
  Serial.print(" ");
  Serial.print(buttonVal_6);
  Serial.println();
  delay(100);
}
