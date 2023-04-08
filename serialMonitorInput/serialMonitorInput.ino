int myNumber {};
int redPin { 5 };
int delayTime { 250 };

void setup() {
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Please enter your number: ");
  while (Serial.available() == 0);
  myNumber = Serial.parseInt();
  Serial.print("Blinking ");
  Serial.print(myNumber);
  Serial.println(" times...");

  for (int i = 0; i < myNumber; i++) {
    digitalWrite(redPin, HIGH);
    delay(delayTime);
    digitalWrite(redPin, LOW);
    delay(delayTime);
  }
}
