int readPIN { A3 };
int delayTime { 500 };
float v2 {};

void setup() {
  pinMode(readPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  v2 = (5./1023.)*analogRead(readPIN);
  Serial.print(v2);
  Serial.print("v read on pin ");
  Serial.println(readPIN);
  delay(delayTime);
}
