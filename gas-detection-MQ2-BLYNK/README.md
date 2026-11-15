# Gas Detection System Using MQ2 Sensor, NodeMCU and Blynk

## Problem Statement
Design and develop a gas detection system using an MQ2 sensor with NodeMCU and Blynk to monitor air quality and send real-time mobile notifications for safety alerts.

## Aim
To design and develop a gas detection system using an MQ-2 sensor with NodeMCU (ESP8266) and Blynk, to monitor air quality and send real-time mobile alerts for safety.

## Components
| Component | Quantity |
|-----------|----------|
| NodeMCU ESP8266 | 1 |
| MQ-2 gas sensor module | 1 |
| Jumper wires / breadboard | as needed |
| Wi-Fi connection | 1 |
| Blynk IoT account and mobile app | 1 |

## Connections
| MQ-2 pin | NodeMCU pin |
|----------|-------------|
| VCC | VIN (5V) |
| GND | GND |
| AO (analog out) | A0 |

> The NodeMCU A0 pin reads 0 to 3.3 V. If your MQ-2 module's AO output goes above 3.3 V, use a voltage divider.

## Blynk setup
| Virtual pin | Widget | Purpose |
|-------------|--------|---------|
| V0 | Value display / gauge | Gas sensor reading |
| V1 | LED (green) | Safe indicator |
| V2 | LED (red) | Unsafe indicator |

Also create an **Event** in the Blynk template with notifications enabled, for the mobile alert.

## Working
1. The NodeMCU connects to Wi-Fi and the Blynk cloud using `Blynk.begin()`.
2. The MQ-2 analog output is read on A0 (range 0 to 1023) every second.
3. The value is printed on the Serial Monitor and sent to V0 in the Blynk app.
4. If the value is above the threshold (90), the red LED (V2) turns on and a Blynk event is logged to send a mobile notification.
5. Otherwise the green LED (V1) turns on, which means the air is safe.

## How to run
1. Create a Blynk template and device with the datastreams above, and note the template ID and auth token.
2. Open the Arduino IDE, create a new sketch, and copy the code from `mq2_gas_detection.cpp` into it.
3. Replace `YOUR_BLYNK_AUTH_TOKEN`, `YOUR_WIFI_SSID` and `YOUR_WIFI_PASSWORD`. The template ID and name are already set for the original project, so change them to your own template's values if you use a different one.
4. Install the **Blynk** library and the **ESP8266** board package.
5. Select **NodeMCU 1.0 (ESP-12E Module)**, choose the COM port and upload.
6. Open the Serial Monitor at **115200 baud**, then bring a gas source (for example an unlit lighter's gas) near the sensor.

## Sample output
```
MQ-2 Sensor Value: 62
Threshold Not Exceeded! GREEN LED on.
MQ-2 Sensor Value: 148
Threshold Exceeded! RED LED on.
```
