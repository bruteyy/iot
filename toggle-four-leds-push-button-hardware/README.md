# Push-Button Toggle of Four LEDs (Hardware)

## Problem Statement
Simulate a push-button LED control system where pressing the push button toggles the four LEDs ON and OFF, changing state with each press. (Hardware)

## Aim
To control four LEDs with a single push button, where each press toggles all the LEDs between ON and OFF, using an Arduino Uno on real hardware.

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno with USB cable | 1 |
| LEDs | 4 |
| 220 ohm resistors (one per LED) | 4 |
| Push button | 1 |
| Breadboard and jumper wires | as needed |

## Connections
| Component | Arduino pin |
|-----------|-------------|
| LED 1 anode (+) via 220 ohm resistor | Pin 8 |
| LED 2 anode (+) via 220 ohm resistor | Pin 9 |
| LED 3 anode (+) via 220 ohm resistor | Pin 10 |
| LED 4 anode (+) via 220 ohm resistor | Pin 11 |
| All LED cathodes (-) | GND |
| Push button (one leg) | Pin 2 |
| Push button (other leg) | GND |

No resistor is needed for the button. The code uses `INPUT_PULLUP`, so Pin 2 reads HIGH normally and LOW when the button is pressed.

## Working
1. All four LEDs start OFF.
2. The code checks the button in a loop and remembers its previous state.
3. When the button goes from not pressed to pressed, the LED state is flipped (ON becomes OFF, OFF becomes ON).
4. The new state is written to all four LEDs.
5. A real button bounces (makes several quick on/off contacts for a few milliseconds) when pressed or released. The code checks the button only once every 50 ms (`delay(50)`), so the bounce is ignored and one press gives exactly one toggle.
6. Holding the button does not toggle again. Only a new press does.

## How to run
1. Make the connections as per the table above.
2. Open the Arduino IDE, create a new sketch, and copy the code from `button_toggle_leds_hardware.cpp` into it.
3. Select **Board: Arduino Uno** and the correct COM port, then click **Upload**.
4. Press the button to turn all LEDs ON, press again to turn them OFF.
