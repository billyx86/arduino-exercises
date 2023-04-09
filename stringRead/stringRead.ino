String myColour {};
int redPin { 2 };
int greenPin { 4 };
int bluePin { 6 };
int delayTime { 5000 };

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("What colour LED would you like to blink? ");
  while (Serial.available() == 0);
  myColour = Serial.readString();

  if (myColour == "red") {
    Serial.println("Blinking red...");
    digitalWrite(redPin, HIGH);
    delay(delayTime);
    digitalWrite(redPin, LOW);
  }
  if (myColour == "green") {
    Serial.println("Blinking green...");
    digitalWrite(greenPin, HIGH);
    delay(delayTime);
    digitalWrite(greenPin, LOW);
  }
  if (myColour == "blue") {
    Serial.println("Blinking blue...");
    digitalWrite(bluePin, HIGH);
    delay(delayTime);
    digitalWrite(bluePin, LOW);
  }
}
