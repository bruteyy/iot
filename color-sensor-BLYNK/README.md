# Color Sensor Interfacing with Blynk

## Problem Statement
Write a program to interface a color sensor with Blynk.

## Aim
To detect the color of an object (Red, Green or Blue) using a TCS3200 color sensor and an ESP8266, and show the result on the Blynk app.

## Components
| Component | Quantity |
|-----------|----------|
| ESP8266 NodeMCU | 1 |
| TCS3200 color sensor | 1 |
| Jumper wires / breadboard | as needed |
| Wi-Fi connection | 1 |
| Blynk IoT account (cloud dashboard) | 1 |

## Connections
| TCS3200 pin | NodeMCU pin |
|-------------|-------------|
| S0 | D1 |
| S1 | D2 |
| S2 | D3 |
| S3 | D4 |
| OUT | D5 |
| VCC | 3.3V |
| GND | GND |

## Blynk setup
| Virtual pin | Widget | Purpose |
|-------------|--------|---------|
| V0 | LED | Red indicator |
| V1 | LED | Green indicator |
| V2 | LED | Blue indicator |
| V3 | Label / Value display | Detected color text |

## Working
1. The ESP8266 connects to Wi-Fi and to the Blynk cloud.
2. S0 = HIGH and S1 = LOW set the sensor output frequency scaling.
3. The sensor is read through its red, green and blue filters (S2, S3 select the filter). The output pulse width is measured with `pulseIn()`.
4. The color with the lowest pulse width (highest intensity) is taken as the detected color.
5. The detected color is shown as text on V3 and the matching LED (V0/V1/V2) turns on in the Blynk app.
6. If no color matches, "No Color Detected" is shown and all LEDs stay off.
7. Detection runs every 1 second after a 3-second sensor stabilization delay.

## How to run
1. Create a Blynk template with the datastreams above and note the device auth token.
2. Open the Arduino IDE, create a new sketch, and copy the code from `color_sensor_blynk.cpp` into it.
3. Replace `YOUR_BLYNK_AUTH_TOKEN`, `YOUR_WIFI_SSID` and `YOUR_WIFI_PASSWORD`.
4. Install the **Blynk** library and the **ESP8266** board package.
5. Select **NodeMCU 1.0 (ESP-12E Module)**, choose the COM port and upload.
6. Open the Serial Monitor at **115200 baud**, then hold a red, green or blue object in front of the sensor.

## Sample output
```
Waiting for sensor stabilization...
Sensor Ready → Now detecting colors!
R=12 G=40 B=38
Detected: RED (Red ON, Green OFF, Blue OFF)
```
