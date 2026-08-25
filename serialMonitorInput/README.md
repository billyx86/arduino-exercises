# serialMonitorInput

Type a number in the Serial Monitor (9600 baud, **No line ending** or
**Newline** — both are handled) and an LED blinks that many times.

- **LED** on pin 5, through a ~220 Ω resistor to GND
- Accepted range: **1–100** blinks (each blink is 250 ms on / 250 ms off)

Input is validated: an empty line, non-numeric text, or an out-of-range
number prints an explanation and re-prompts instead of hanging or blinking
zero times. If no input arrives within 5 seconds the prompt repeats.
