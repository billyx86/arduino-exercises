int myNumber {};
int redPin { 5 };
int delayTime { 250 };
int inputTimeoutMs { 5000 };   // wait up to 5 s for input before re-prompting
int minBlinks { 1 };
int maxBlinks { 100 };

// Wait (up to inputTimeoutMs) for a line, then read and parse it.
// Returns false and reports why when the input was empty or non-numeric.
bool readBlinkCount() {
  unsigned long start = millis();
  while (!Serial.available()) {
    if (millis() - start > inputTimeoutMs) {
      return false;
    }
    delay(10);
  }

  String line = Serial.readStringUntil('\n');
  line.trim();
  if (line.endsWith("\r")) {
    line.remove(line.length() - 1);
  }

  if (line.length() == 0) {
    Serial.println("Nothing entered. Please type a number (1-100).");
    return false;
  }

  int parsed = line.toInt();
  // toInt() returns 0 for non-numeric text and for anything past the end
  // of its range; a number of blinks must also be within our sane bounds.
  if (parsed < minBlinks || parsed > maxBlinks) {
    Serial.print("Can't blink that many times. Please type a number from ");
    Serial.print(minBlinks);
    Serial.print(" to ");
    Serial.println(maxBlinks);
    return false;
  }

  // Drain the rest of the line so leftover \r or trailing characters can't
  // be re-parsed on the next pass.
  while (Serial.available()) {
    Serial.read();
  }

  myNumber = parsed;
  return true;
}

void setup() {
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
  delay(1500);  // give the Serial Monitor time to open
}

void loop() {
  Serial.println("Please enter your number (1-100):");
  if (!readBlinkCount()) {
    delay(delayTime);
    return;
  }

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
