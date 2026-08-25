String myColour {};
int redPin { 2 };
int greenPin { 4 };
int bluePin { 6 };
int delayTime { 5000 };

// Read a line from the Serial Monitor, strip the trailing \r and \n that
// readString() keeps, and lower-case it so "Red", "RED" and " red " all work.
String readColourInput() {
  while (!Serial.available());
  String input = Serial.readStringUntil('\n');

  input.trim();            // drop surrounding whitespace
  // readStringUntil('\n') keeps a trailing '\r' when the line is CRLF.
  if (input.endsWith("\r")) {
    input.remove(input.length() - 1);
  }
  input.toLowerCase();
  return input;
}

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("What colour LED would you like to blink? (red / green / blue)");
  myColour = readColourInput();

  if (myColour == "red") {
    Serial.println("Blinking red...");
    digitalWrite(redPin, HIGH);
    delay(delayTime);
    digitalWrite(redPin, LOW);
  } else if (myColour == "green") {
    Serial.println("Blinking green...");
    digitalWrite(greenPin, HIGH);
    delay(delayTime);
    digitalWrite(greenPin, LOW);
  } else if (myColour == "blue") {
    Serial.println("Blinking blue...");
    digitalWrite(bluePin, HIGH);
    delay(delayTime);
    digitalWrite(bluePin, LOW);
  } else {
    Serial.print("Sorry, I don't know the colour \"");
    Serial.print(myColour);
    Serial.println("\". Try red, green or blue.");
  }
}
