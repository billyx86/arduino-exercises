int readPIN { A3 };
int delayTime { 250 };
int brightness {};
int redPin { 9 };

void setup() {
  pinMode(readPIN, INPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  brightness = (analogRead(readPIN) / 1023.) * 255;
  Serial.println(brightness);

  if (brightness < 2) { // There was some noise when at 0, necessary to stop the blinking
    brightness = 0;
  }

  analogWrite(redPin, brightness);
}
