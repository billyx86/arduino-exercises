# 01-digitalInputs

Two momentary buttons drive one LED.

- **Button A** (pin 8, internal pull-up) → LED on while held
- **Button B** (pin 9, internal pull-up) → LED off while held
- **LED** on pin 5

Wire each button between its pin and GND (the internal pull-up keeps the
input HIGH until the button is pressed), and the LED to pin 5 through a
~220 Ω resistor to GND.

There is no serial output. The last button pressed wins on each loop
iteration, so holding both down leaves the LED off (button B is checked
second).
