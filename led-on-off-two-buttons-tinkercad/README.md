# LED ON/OFF Using Two Buttons (Tinkercad)

## Problem Statement
Turn ON the LED if button 1 is pressed, turn OFF the LED if button 2 is pressed. (Tinkercad)

## Aim
To turn ON an LED when button 1 is pressed and turn it OFF when button 2 is pressed, using Arduino Uno in Tinkercad Circuits.

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| LED | 1 |
| 220 ohm resistor (for LED) | 1 |
| Push buttons | 2 |
| 10k ohm resistors (pull-down) | 2 |
| Breadboard and jumper wires | as needed |

## Connections
| Component | Arduino pin |
|-----------|-------------|
| LED anode (+) via 220 ohm resistor | Pin 8 |
| LED cathode (-) | GND |
| Button 1 (one leg to 5V, other leg to Pin 2) | Pin 2 |
| 10k resistor between Pin 2 and GND | pull-down for button 1 |
| Button 2 (one leg to 5V, other leg to Pin 3) | Pin 3 |
| 10k resistor between Pin 3 and GND | pull-down for button 2 |

The 10k pull-down resistors keep each input LOW when the button is not pressed. Pressing the button connects the pin to 5V, so it reads HIGH.

## Working
1. Pins 2 and 3 are inputs for button 1 and button 2. Pin 8 is the LED output.
2. When button 1 is pressed (HIGH) the LED turns ON.
3. When button 2 is pressed (HIGH) the LED turns OFF.
4. The LED keeps its state after the button is released.
5. The status is printed on the Serial Monitor. A message is printed only when the state changes.
6. If both buttons are pressed together, the LED ends up OFF.

## How to run in Tinkercad
1. Open Tinkercad, go to **Circuits** and create a new circuit.
2. Build the circuit as per the connection table.
3. Click **Code**, choose **Text**, and paste the code from `led_button_tinkercad.cpp`.
4. Click **Start Simulation** and press the buttons. Open the Serial Monitor to see the messages.

## Sample output
```
Button 1 pressed: LED ON
Button 2 pressed: LED OFF
```
