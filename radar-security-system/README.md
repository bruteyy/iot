# Radar-Based Security System using Ultrasonic Sensor and Servo Motor

## Aim
To design and develop a simple radar-based security system using an ultrasonic sensor and servo motor to scan the surroundings, detect objects within a specified range, display their positions on a radar-like interface, and generate an alert.

## Components Required
- Arduino Uno
- HC-SR04 ultrasonic sensor
- SG90 servo motor
- Buzzer
- Breadboard and jumper wires
- USB cable
- Computer with Arduino IDE and Processing IDE

## Connections
| Component pin | Arduino Uno |
|---|---|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D10 |
| HC-SR04 ECHO | D11 |
| Servo signal (orange/yellow) | D9 |
| Servo VCC (red) | 5V (use a suitable external 5V supply if the servo causes resets) |
| Servo GND (brown/black) | GND |
| Buzzer positive (+) | D3 |
| Buzzer negative (-) | GND |

**Important:** If using an external 5V supply for the servo, connect its GND to Arduino GND. Do not connect a servo signal wire to 5V.

## Working
1. The servo motor turns the ultrasonic sensor from 0 to 180 degrees and back.
2. At each angle, the HC-SR04 sends an ultrasonic pulse and measures the returning echo.
3. Arduino calculates the distance in centimetres.
4. Arduino sends the angle and distance to the computer through USB serial communication.
5. The Processing program reads the serial data and displays the scan on a radar-like screen.
6. If an object is detected within 30 cm, the buzzer sounds and the interface displays a warning.

## Arduino IDE Procedure
1. Connect the components according to the connection table.
2. Open Arduino IDE and create a new sketch.
3. Copy `radar_security_arduino.cpp` into the sketch.
4. Select **Arduino Uno** and the correct COM port.
5. Upload the program.
6. Close the Arduino Serial Monitor before opening the Processing display.

## Radar Display Procedure
1. Install and open Processing IDE on the computer.
2. Open `radar_display_processing.pde`.
3. Run the sketch.
4. If Arduino is not on the first serial port listed, check the port list printed by Processing and change `Serial.list()[0]` to the correct index.
5. Keep the Arduino connected. Move an object in front of the sensor and observe its angle and distance on the radar display.

## Code Files
- `radar_security_arduino.cpp` — Arduino code for servo scanning, distance measurement, serial transmission, and buzzer alert.
- `radar_display_processing.pde` — Processing code for the radar-like display.

## Notes
- The scan range is set to 0–180 degrees.
- The maximum displayed distance is 200 cm.
- The buzzer alert threshold is 30 cm. Change `30` in the Arduino code if another threshold is required.
- The HC-SR04 is a distance sensor, not a camera; it reports distance in the direction it is facing.
- Servo motors can draw more current than an Arduino 5V pin can reliably supply. If the board resets or the servo jitters, use a separate regulated 5V supply for the servo and connect grounds together.
- This is a simple demonstration project, not a certified security alarm system.
