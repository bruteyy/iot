# IoT Practicals – Short Viva Questions & Answers

**37 Questions · Quick Revision**

> **How to prepare:** Learn the definition, working principle and purpose of each component. Answers are kept short and easy to speak during a practical viva.

## Contents

1. [Practical 1: GPIO Pins and Push Button](#practical-1-gpio-pins-and-push-button)
2. [Practical 2: PIR Sensor](#practical-2-pir-sensor)
3. [Practical 3: DHT11 and DHT22](#practical-3-dht11-and-dht22)
4. [Practical 4: Ultrasonic Sensor](#practical-4-ultrasonic-sensor)
5. [Practical 5: Stepper Motor](#practical-5-stepper-motor)
6. [Practical 6: Color Sensor and ESP8266](#practical-6-color-sensor-and-esp8266)
7. [Practical 7: Gas Sensor and NodeMCU](#practical-7-gas-sensor-and-nodemcu)
8. [Practical 8: Radar-Based Security System](#practical-8-radar-based-security-system)
9. [Practical 9: Object Counting System](#practical-9-object-counting-system)
10. [Important Full Forms](#important-full-forms)

---

## Practical 1: GPIO Pins and Push Button

**1. What is a GPIO pin?**
1. GPIO stands for General Purpose Input/Output.
2. It connects external devices to a board.
3. It receives input signals.
4. It sends output signals.
5. It can be configured as INPUT or OUTPUT.

**2. What is the role of pull-up and pull-down resistors?**
1. They maintain a stable input state.
2. Pull-up keeps the pin HIGH.
3. Pull-down keeps the pin LOW.
4. They prevent floating inputs.
5. They ensure accurate button readings.

**3. How does `digitalRead()` work?**
1. It reads a digital pin.
2. It detects HIGH or LOW.
3. HIGH represents 1.
4. LOW represents 0.
5. It is commonly used with buttons and sensors.

**4. What happens if no resistor is used with a push button?**
1. The input pin may float.
2. It may give random readings.
3. False button presses may occur.
4. The circuit may behave unpredictably.
5. A pull-up or pull-down resistor prevents this.

**5. Can GPIO pins be configured dynamically during runtime?**
1. Yes, GPIO pins can be reconfigured.
2. Arduino uses `pinMode()`.
3. Pins can be INPUT or OUTPUT.
4. `INPUT_PULLUP` is also available.
5. Configuration can change during execution.

---

## Practical 2: PIR Sensor

**6. What is the working principle of a PIR sensor?**
1. PIR means Passive Infrared Sensor.
2. It detects infrared radiation.
3. Humans emit infrared radiation.
4. It detects changes in infrared energy.
5. It generates an output when motion is detected.

**7. What is the range of a typical PIR sensor?**
1. Typically 5–7 metres.
2. It depends on the model.
3. HC-SR501 detects up to around 7 metres.
4. Its angle is around 110°–120°.
5. Sensitivity can be adjusted.

**8. Why is `delay()` used in the code?**
1. It pauses program execution.
2. It accepts milliseconds.
3. `delay(1000)` means one second.
4. It controls timing.
5. It creates waiting intervals.

---

## Practical 3: DHT11 and DHT22

**9. What is a DHT11 sensor?**
1. It is a digital sensor.
2. It measures temperature.
3. It measures humidity.
4. It provides digital output.
5. It is used in weather monitoring.

**10. Difference between DHT11 and DHT22?**

| Feature | DHT11 | DHT22 |
|---|---|---|
| Accuracy | Lower | More accurate |
| Temperature range | 0–50°C | −40–80°C |
| Humidity range | 20–90% | 0–100% |

**11. What type of signal does DHT11 generate?**
1. It generates a digital signal.
2. It uses one data pin.
3. It sends temperature data.
4. It sends humidity data.
5. It does not require an external ADC.

**12. What is the working principle of DHT11?**
1. It has temperature and humidity sensing elements.
2. It measures surrounding temperature.
3. It measures relative humidity.
4. Its internal controller processes readings.
5. It sends digital data to the microcontroller.

**13. How many pins does DHT11 have?**

It has four pins:

| Pin | Function |
|---|---|
| VCC | Power supply |
| DATA | Data transmission |
| NC | Not connected |
| GND | Ground connection |

---

## Practical 4: Ultrasonic Sensor

**14. What is an ultrasonic sensor?**
1. It measures distance.
2. It uses sound waves.
3. It sends ultrasonic waves.
4. Waves reflect from objects.
5. It calculates distance using time.

**15. What are the main pins of HC-SR04?**

It has four pins:

| Pin | Function |
|---|---|
| VCC | 5V supply |
| GND | Ground |
| TRIG | Sends ultrasonic waves |
| ECHO | Produces a pulse representing the return time |

**16. How many GPIO pins are available on Raspberry Pi?**
1. Most modern models have a 40-pin header.
2. 26 are commonly counted as GPIO pins.
3. GPIO means General Purpose Input/Output.
4. They support digital input and output.
5. They operate at 3.3V.

**17. Why do we divide the distance formula by 2?**
1. Sound travels towards the object.
2. It reflects back to the sensor.
3. Time measures the round trip.
4. We need one-way distance.
5. Therefore, we divide by 2.

---

## Practical 5: Stepper Motor

**18. What is a stepper motor?**
1. It is an electric motor.
2. It rotates in fixed steps.
3. It works using electrical pulses.
4. It provides position control.
5. It is used in robotics and 3D printers.

**19. Why do stepper motors require driver circuits?**
1. They require sufficient current.
2. Drivers control motor coils.
3. They control rotation direction.
4. They provide the required switching sequence.
5. They protect the microcontroller.

**20. What is the role of ULN2003/A4988 driver?**
1. They control stepper motors.
2. ULN2003 drives unipolar motors.
3. A4988 drives bipolar motors.
4. They control motor movement.
5. A4988 supports microstepping.

**21. What are full-step and half-step modes?**
1. They are motor driving methods.
2. Full-step moves one complete step.
3. Half-step moves half a step.
4. Half-step provides better resolution.
5. Both control motor rotation.

---

## Practical 6: Color Sensor and ESP8266

**22. What is the working principle of a color sensor?**
1. It detects object colours.
2. It uses photodiodes.
3. It detects red, green and blue light.
4. It converts light into electrical signals.
5. A microcontroller identifies the colour.

**23. Why is ESP8266 used?**
1. It is a Wi-Fi-enabled microcontroller.
2. It connects devices to the internet.
3. It reads sensor data.
4. It transmits data wirelessly.
5. It is used in IoT projects.

**24. How does ThingSpeak receive data from ESP8266?**
1. ESP8266 connects to Wi-Fi.
2. It collects sensor data.
3. It sends data through HTTP or MQTT.
4. ThingSpeak receives the data.
5. It displays readings in graphs.

**25. What is the use of S0–S3 pins on TCS3200?**
1. S0 and S1 control frequency scaling.
2. S2 and S3 select colour filters.
3. They help detect RGB colours.
4. The sensor generates an output frequency.
5. The microcontroller identifies the colour.

---

## Practical 7: Gas Sensor and NodeMCU

**26. What gases can MQ-2 detect?**
1. LPG.
2. Methane.
3. Propane.
4. Butane.
5. Hydrogen and smoke.

**27. How does MQ-2 work?**
1. It is a semiconductor gas sensor.
2. It contains tin dioxide (SnO₂).
3. It has a heating element.
4. Gas changes its electrical resistance.
5. It generates an output signal.

**28. What is the use of NodeMCU?**
1. It is based on ESP8266.
2. It provides Wi-Fi connectivity.
3. It reads sensor data.
4. It processes sensor readings.
5. It sends data to cloud platforms.

**29. Why is Blynk used instead of ThingSpeak?**
1. Blynk provides mobile monitoring.
2. It displays real-time readings.
3. It supports notifications.
4. It allows remote device control.
5. ThingSpeak mainly focuses on data storage and analysis.

---

## Practical 8: Radar-Based Security System

**30. How does the ultrasonic sensor detect objects in radar?**
1. It sends ultrasonic waves.
2. Waves hit nearby objects.
3. Reflected waves return.
4. It calculates the distance.
5. Arduino displays object position and distance.

**31. What is the function of servo motor?**
1. It rotates the ultrasonic sensor.
2. It provides angular movement.
3. It scans from different angles.
4. It helps detect nearby objects.
5. It is controlled by Arduino.

**32. Why is Processing IDE used?**
1. It creates a radar interface.
2. It receives Arduino data.
3. It displays scanning angles.
4. It shows detected objects.
5. It displays object distance.

**33. How are object position and distance displayed?**
1. Arduino collects sensor readings.
2. It sends angle and distance data.
3. Processing receives the data.
4. Angle shows object position.
5. Distance shows how far the object is.

---

## Practical 9: Object Counting System

**34. How does an IR sensor detect objects?**
1. IR means Infrared.
2. It has a transmitter and receiver.
3. It sends infrared light.
4. Objects reflect the light.
5. The receiver detects the reflected signal.

**35. What is the role of Arduino Uno?**
1. It acts as the main controller.
2. It receives IR sensor signals.
3. It detects passing objects.
4. It increases the object count.
5. It sends data to the computer.

**36. Why is Excel Data Streamer used?**
1. It connects Arduino with Excel.
2. It receives real-time data.
3. It displays object counts.
4. It helps create graphs.
5. It supports data analysis.

**37. How is real-time object count displayed in Excel?**
1. Arduino sends counting data.
2. Excel receives serial data.
3. Values appear in worksheet cells.
4. The count updates when objects are detected.
5. Charts help analyse the collected data.

---

## Important Full Forms

| Short | Full Form |
|---|---|
| GPIO | General Purpose Input/Output |
| PIR | Passive Infrared Sensor |
| DHT | Digital Humidity and Temperature |
| IR | Infrared |
| IoT | Internet of Things |
| PWM | Pulse Width Modulation |
| RGB | Red, Green, Blue |
| ADC | Analog-to-Digital Converter |

---

> **Technical note:** The original question says "M102 sensor." The short answer above assumes the intended component is **MQ-2**. Confirm the exact model printed on your sensor or manual. Also, Raspberry Pi GPIO counts vary by model; the 40-pin-header answer applies to common modern models.
