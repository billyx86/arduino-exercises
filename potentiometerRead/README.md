# potentiometerRead

A potentiometer acts as a voltage threshold switch: the LED turns on when
the reading goes above 4 V.

- **Potentiometer** on A3 (wiper to A3, outer legs to 5 V and GND)
- **LED** on pin 9, through a ~220 Ω resistor to GND
- **Serial** (9600 baud): the voltage once every 250 ms, e.g.
  `4.32, redPin set to HIGH: above 4v!`

With a 10 kΩ pot at 9600 baud the threshold sits just under the centre of
the travel, so a quarter-turn either way flips the LED.
