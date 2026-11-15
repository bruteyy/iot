# Interface Ultrasonic Sensor with Raspberry Pi to Monitor Object Distance

## Aim
To interface an HC-SR04 ultrasonic sensor with a Raspberry Pi and measure the distance of an object.

## Components Required
- Raspberry Pi with GPIO header
- HC-SR04 ultrasonic sensor
- 1 kΩ resistor
- 2 kΩ resistor
- Breadboard and jumper wires
- Raspberry Pi power supply

## Connections (BCM GPIO numbering)
| HC-SR04 pin | Raspberry Pi connection |
|---|---|
| VCC | 5V pin (physical pin 2 or 4) |
| GND | GND (physical pin 6) |
| TRIG | GPIO 23 (physical pin 16) |
| ECHO | GPIO 24 (physical pin 18) through a voltage divider |

## Important ECHO voltage protection
Raspberry Pi GPIO pins are **3.3V tolerant only**. The HC-SR04 ECHO output can be 5V, so **do not connect ECHO directly** to Raspberry Pi GPIO 24.

Use a resistor divider:
- HC-SR04 ECHO → 1 kΩ resistor → GPIO 24
- GPIO 24 → 2 kΩ resistor → GND

This reduces the 5V ECHO signal to approximately 3.3V. Connect all grounds together.

## Working
1. Raspberry Pi sends a short trigger pulse to the HC-SR04 sensor.
2. The sensor transmits an ultrasonic wave.
3. The wave reflects from an object and returns to the sensor.
4. The ECHO pin stays HIGH for the time taken by the sound wave to travel to the object and back.
5. Python measures this time and calculates distance in centimetres.
6. The measured distance is printed in the terminal repeatedly.

## Procedure
1. Connect the HC-SR04 sensor to Raspberry Pi as shown in the connection table.
2. Build the resistor divider on the ECHO line before connecting it to GPIO 24.
3. Open the Raspberry Pi terminal.
4. Ensure the `RPi.GPIO` library is available in the Python environment.
5. Copy `ultrasonic_distance_raspberry_pi.py` to the Raspberry Pi.
6. Run the program using Python 3:
   `python3 ultrasonic_distance_raspberry_pi.py`
7. Place an object in front of the sensor and observe the distance displayed in centimetres.
8. Press `Ctrl+C` to stop the program safely.

## Code File
`ultrasonic_distance_raspberry_pi.py` — Python program to trigger the ultrasonic sensor, measure echo time, calculate distance, and display the result.

## Notes
- The program uses BCM GPIO numbering: TRIG is GPIO 23 and ECHO is GPIO 24.
- The typical useful measurement range of an HC-SR04 is approximately 2 cm to 400 cm, depending on the module and target.
- Keep the ECHO voltage divider connected. Raspberry Pi GPIO pins can be damaged by 5V signals.
- This practical displays distance in the terminal; it does not require a display or internet connection.
