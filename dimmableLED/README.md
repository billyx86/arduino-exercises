# dimmableLED

A potentiometer controls an LED's brightness in real time via PWM.

- **Potentiometer** on A3 (wiper to A3, outer legs to 5 V and GND)
- **LED** on pin 9 (PWM), through a ~220 Ω resistor to GND
- **Serial** (9600 baud): brightness 0–255, once every 250 ms

`brightness = (analogRead(A3) / 1023.0) * 255`. Readings below 5 are clamped
to 0 — raw readings jitter around 0–4 with the pot at full-off, which made
the LED flicker.
