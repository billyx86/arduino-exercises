int readPIN { A3 };
int delayTime { 250 };
float V2 {};
int redPin { 9 };

void setup() {
  pinMode(readPIN, INPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  V2 = (5./1023.) * analogRead(readPIN);

  if (V2 > 4) {
    digitalWrite(redPin, HIGH);
    Serial.print(V2);
    Serial.println(", redPin set to HIGH: above 4v!");
  } else {
    digitalWrite(redPin, LOW);
    Serial.println(V2);
  }

  delay(delayTime);
}
