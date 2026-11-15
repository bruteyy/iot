# Push-Button Toggle of Four LEDs (Tinkercad)

## Problem Statement
Simulate a push-button LED control system in Tinkercad where pressing the push button toggles the four LEDs ON and OFF, changing state with each press.

## Aim
To simulate a push-button LED control system in Tinkercad, where each press of a push button toggles four LEDs between ON and OFF.

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
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
5. Holding the button does not toggle again. Only a new press does.

## How to run in Tinkercad
1. Open Tinkercad, go to **Circuits** and create a new circuit.
2. Build the circuit as per the connection table.
3. Click **Code**, choose **Text**, and paste the code from `button_toggle_leds_tinkercad.cpp`.
4. Click **Start Simulation** and click the button. The LEDs switch ON, then OFF, with each click.
