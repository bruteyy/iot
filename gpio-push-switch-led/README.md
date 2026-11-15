# GPIO Configuration and Application of Push Switches and LEDs

## Aim
To understand GPIO connection and configuration and demonstrate the use of a push switch to control an LED.

## Components Required
- Arduino Uno
- LED
- Push button switch
- 220 ohm resistor for the LED
- 10 kilo-ohm pull-down resistor for the button input
- Breadboard and jumper wires
- USB cable

## Connections
| Component | Arduino connection |
|---|---|
| LED anode (+) | Digital pin 3 through a 220 ohm resistor |
| LED cathode (-) | GND |
| Push button | One side to 5V, other side to digital pin 2 |
| Pull-down resistor | 10 kilo-ohm between digital pin 2 and GND |

## Working
1. The LED pin (D3) is configured as OUTPUT.
2. The push-button pin (D2) is configured as INPUT.
3. When the button is pressed, D2 reads HIGH and the LED turns ON.
4. When the button is released, D2 reads LOW and the LED turns OFF.

## Procedure
1. Make the connections as shown in the connection table.
2. Connect the Arduino Uno to the computer using a USB cable.
3. Open Arduino IDE and paste the code from `gpio_push_switch_led.cpp` into a new sketch.
4. Select Arduino Uno and the correct COM port.
5. Upload the program.
6. Press and release the push button and observe the LED.

## Code
The supplied Arduino code is included in `gpio_push_switch_led.cpp`.

## Note
The supplied code uses `INPUT`, so the button input needs a defined LOW state when the button is not pressed. Use the external 10 kilo-ohm pull-down resistor shown above. Without a pull-down resistor (or another defined input-bias arrangement), the input may float and the LED may behave unpredictably.
