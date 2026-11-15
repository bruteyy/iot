# IoT Practicals

| Problem statement | Platform | Folder | Code file |
|---|---|---|---|
| PIR motion sensor with LED and buzzer | Arduino Uno | `pir-motion-detector-led-buzzer` | `pir_motion_detector.cpp` |
| Gas detection using MQ2, NodeMCU and Blynk | NodeMCU ESP8266, Blynk | `gas-detection-mq2-blynk` | `mq2_gas_detection.cpp` |
| Interface DHT11 and upload sensor data to the cloud | NodeMCU ESP8266, ThingSpeak | `dht11-upload-data-thingspeak` | `dht11_thingspeak.cpp` |
| Color detection and monitoring using ESP8266 and ThingSpeak | NodeMCU ESP8266, TCS3200, ThingSpeak | `color-detection-esp8266-thingspeak` | `color_detection_esp8266_thingspeak.cpp` |
| LED ON with button 1, OFF with button 2 (Tinkercad) | Arduino Uno, Tinkercad | `led-on-off-two-buttons-tinkercad` | `led_button_tinkercad.cpp` |
| Stepper motor interfacing with Raspberry Pi | Raspberry Pi, Python | `stepper-motor-raspberry-pi` | `stepper_motor_raspberry_pi.py` |
| LED ON with button 1, OFF with button 2 (Hardware) | Arduino Uno | `led-on-off-two-buttons-hardware` | `led_button_hardware.cpp` |
| Push button toggles four LEDs (Hardware) | Arduino Uno | `toggle-four-leds-push-button-hardware` | `button_toggle_leds_hardware.cpp` |
| Push button toggles four LEDs (Tinkercad) | Arduino Uno, Tinkercad | `toggle-four-leds-push-button-tinkercad` | `button_toggle_leds_tinkercad.cpp` |
| Color sensor with Blynk | NodeMCU ESP8266, TCS3200, Blynk | `color-sensor-blynk` | `color_sensor_blynk.cpp` |

Each folder has a `README.md` (problem statement, aim, components, connections, working, how to run) and the code file.

The Arduino and NodeMCU code files use the `.cpp` extension so they open and copy as plain text anywhere. To use one, copy its code into a new sketch in the Arduino IDE (or save it with a `.ino` extension).

Wi-Fi names, passwords, Blynk tokens and ThingSpeak keys are placeholders such as `YOUR_WIFI_SSID`. Replace them with your own values before uploading to a board.

| Object counting using IR sensor and Microsoft Excel Data Streamer | Arduino Uno, IR sensor, Excel Data Streamer | `object-counting-excel-data-streamer` | `object_counting_excel.cpp` |

| GPIO configuration and push switch control of LED | Arduino Uno, push button, LED | `gpio-push-switch-led` | `gpio_push_switch_led.cpp` |

| Radar-based security system using ultrasonic sensor and servo motor | Arduino Uno, HC-SR04, servo motor, buzzer, Processing | `radar-security-system` | `radar_security_arduino.cpp`, `radar_display_processing.pde` |

| Interface ultrasonic sensor with Raspberry Pi to monitor object distance | Raspberry Pi, HC-SR04 ultrasonic sensor, resistors | `raspberry-pi-ultrasonic-distance` | `ultrasonic_distance_raspberry_pi.py` |
