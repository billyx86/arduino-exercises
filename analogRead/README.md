# analogRead

Reads an analog pin and prints the voltage it corresponds to, twice a
second.

- **Input** on A3 — wire a signal (or a potentiometer between 5 V and GND,
  wiper on A3) to the pin
- **Serial** (9600 baud): `2.31v read on pin 15`

The raw 10-bit ADC value (0–1023) is scaled to 0–5 V:
`voltage = (5.0 / 1023) * raw`.
