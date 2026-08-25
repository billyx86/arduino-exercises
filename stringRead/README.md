# stringRead

Type a colour in the Serial Monitor (9600 baud) and that channel of an RGB
LED blinks for five seconds.

- **Red** on pin 2, **green** on pin 4, **blue** on pin 6 — one anode per
  channel (common-cathode RGB), each through a ~220 Ω resistor to GND
- Accepted input: `red`, `green`, `blue` — case- and whitespace-insensitive
  ("Red", " BLUE " both work)
- Any other input prints `Sorry, I don't know the colour "..."`

This is the sketch that taught me `Serial.readString()` keeps the trailing
newline — matching the raw input against `"red"` never worked until the
input is trimmed.
