# LED ON/OFF Using Two Buttons (Hardware)

## Problem Statement
Turn ON the LED if button 1 is pressed, turn OFF the LED if button 2 is pressed. (Hardware)

## Aim
To turn ON an LED when button 1 is pressed and turn it OFF when button 2 is pressed, using an Arduino Uno on real hardware.

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno with USB cable | 1 |
| LED | 1 |
| 220 ohm resistor (for LED) | 1 |
| Push buttons | 2 |
| Breadboard and jumper wires | as needed |

## Connections
| Component | Arduino pin |
|-----------|-------------|
| LED anode (+) via 220 ohm resistor | Pin 8 |
| LED cathode (-) | GND |
| Button 1 (one leg) | Pin 2 |
| Button 1 (other leg) | GND |
| Button 2 (one leg) | Pin 3 |
| Button 2 (other leg) | GND |

No external resistors are needed for the buttons. The code enables the Arduino's internal pull-up resistors with `INPUT_PULLUP`, so each pin reads HIGH normally and LOW when its button is pressed.

## Working
1. Pins 2 and 3 are inputs with internal pull-ups. Pin 8 is the LED output.
2. When button 1 is pressed (LOW) the LED turns ON.
3. When button 2 is pressed (LOW) the LED turns OFF.
4. The LED keeps its state after the button is released.
5. A 50 ms delay after each change works as a simple debounce for the mechanical buttons.
6. The status is printed on the Serial Monitor.

## How to run
1. Make the connections as per the table above.
2. Open the Arduino IDE, create a new sketch, and copy the code from `led_button_hardware.cpp` into it.
3. Select **Board: Arduino Uno** and the correct COM port, then click **Upload**.
4. Press button 1 to turn the LED ON and button 2 to turn it OFF. Open the Serial Monitor at **9600 baud** to see the messages.

## Sample output
```
Button 1 pressed: LED ON
Button 2 pressed: LED OFF
```
