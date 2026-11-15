# PIR Motion Sensor with LED and Buzzer

## Problem Statement
Detect motion using a PIR sensor and turn ON an LED and a buzzer when motion is detected.

## Aim
To detect motion using a PIR sensor and indicate it with an LED and a buzzer, while printing the status on the Serial Monitor.

## Components
| Component | Quantity |
|-----------|----------|
| Arduino Uno | 1 |
| PIR motion sensor (HC-SR501) | 1 |
| LED | 1 |
| 220 ohm resistor | 1 |
| Buzzer | 1 |
| Breadboard and jumper wires | as needed |

## Connections
| Component | Arduino pin |
|-----------|-------------|
| PIR OUT | D2 |
| PIR VCC | 5V |
| PIR GND | GND |
| LED anode (+) via 220 ohm resistor | D4 |
| LED cathode (-) | GND |
| Buzzer (+) | D6 |
| Buzzer (-) | GND |

## Working
1. The PIR sensor output goes HIGH when it senses motion (change in infrared radiation).
2. The Arduino reads this on pin 2 using `digitalRead()`.
3. If motion is detected, the LED and buzzer turn ON and "Motion detected!" is printed.
4. Otherwise both turn OFF and "Motion not detected" is printed.
5. The loop repeats every 1 second (`delay(1000)`).

## How to run
1. Make the connections as per the table above.
2. Open the Arduino IDE, create a new sketch, and copy the code from `pir_motion_detector.cpp` into it.
3. Select **Board: Arduino Uno** and the correct COM port, then click **Upload**.
4. Open the Serial Monitor at **9600 baud**.
5. Move in front of the sensor to see the LED glow, the buzzer sound, and the message change.

## Sample output
```
Motion not detected
Motion not detected
Motion detected!
Motion detected!
Motion not detected
```
