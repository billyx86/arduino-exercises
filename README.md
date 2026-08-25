# arduino-exercises

A repository of code I use for my Arduino projects. Each sketch lives in its
own folder (`<sketch>/<sketch>.ino`) and opens directly in the Arduino IDE.

## Sketches

| Sketch | What it does | Pins | Serial (9600) |
| --- | --- | --- | --- |
| [01-digitalInputs](01-digitalInputs/) | Two momentary buttons drive one LED: button A turns it on, button B turns it off. | LED 5, button A 8 (pull-up), button B 9 (pull-up) | — |
| [analogRead](analogRead/) | Reads an analog pin and prints the corresponding 0–5 V voltage twice a second. | A3 | voltage, e.g. `2.31v read on pin 15` |
| [dimmableLED](dimmableLED/) | A potentiometer sets an LED's PWM brightness live; a small dead zone stops flicker at zero. | pot A3, LED 9 (PWM) | brightness 0–255 |
| [potentiometerRead](potentiometerRead/) | A potentiometer switches an LED on when the voltage goes above 4 V. | pot A3, LED 9 | voltage, with a note when the LED turns on |
| [serialMonitorInput](serialMonitorInput/) | Type a number (1–100) in the Serial Monitor and the LED blinks that many times. | LED 5 | prompt, then `Blinking N times...` |
| [stringRead](stringRead/) | Type a colour (`red`, `green` or `blue`) and that RGB LED channel blinks for five seconds. | red 2, green 4, blue 6 | prompt, then `Blinking red...` etc. |

Target board is the Arduino Uno (10-bit ADC, PWM on pin 9); any board with the
same pin-out will work. All serial output is at 9600 baud.

## Building / compiling

**Arduino IDE** — File → Open, pick the sketch folder. Select
*Boards → Arduino Uno*, then *Sketch → Verify/Compile*.

**arduino-cli** (headless):

```sh
arduino-cli core update-index
arduino-cli core install arduino:avr
arduino-cli compile --fqbn arduino:avr:uno <sketch>/<sketch>
```

## Testing

```sh
python3 tests/validate_sketches.py   # structural checks (layout, setup/loop, docs)
```

Continuous Integration ([.github/workflows/ci.yml](.github/workflows/ci.yml))
runs the validator and compiles **every** sketch for the Uno on every push and
pull request, so a commit that breaks compilation can't land silently.

## Layout

```
<sketch-name>/
  <sketch-name>.ino   # the sketch — folder name must match
  README.md           # what it does, pins, expected serial output
tests/validate_sketches.py
```
