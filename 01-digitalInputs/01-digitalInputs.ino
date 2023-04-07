int ledPin = 5;
int buttonAPin = 8;
int buttonBPin = 9; // Assign buttons to pins

byte leds = 0; // Define byte "leds" and hold its state

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonAPin, INPUT_PULLUP);
  pinMode(buttonBPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonAPin) == LOW) {
    digitalWrite(ledPin, HIGH); // Turn on the LED when Button A (Pin 8) is pressed
  }
  if (digitalRead(buttonBPin) == LOW) {
    digitalWrite(ledPin, LOW); // Turn off the LED when Button B (Pin 9) is pressed
  }
}