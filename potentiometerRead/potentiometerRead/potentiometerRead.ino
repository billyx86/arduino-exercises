int readPIN { A3 };
int delayTime { 500 };
float V2 {};

void setup() {
  pinMode(readPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  V2 = (5./1023.) * analogRead(readPIN);
  Serial.println(V2);
  delay(delayTime);
}
