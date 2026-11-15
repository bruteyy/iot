# Color Detection and Monitoring Using ESP8266 and ThingSpeak

## Problem Statement
Color detection and monitoring using ESP8266 and ThingSpeak.

## Aim
To detect the color of an object (Red, Green or Blue) using a TCS3200 color sensor and an ESP8266, and upload the readings to the ThingSpeak cloud for monitoring.

## Components
| Component | Quantity |
|-----------|----------|
| ESP8266 NodeMCU | 1 |
| TCS3200 color sensor | 1 |
| Jumper wires / breadboard | as needed |
| Wi-Fi connection | 1 |
| ThingSpeak account (free) | 1 |

## Connections
| TCS3200 pin | NodeMCU pin |
|-------------|-------------|
| S0 | D1 |
| S1 | D2 |
| S2 | D5 |
| S3 | D6 |
| OUT | D7 |
| VCC | 3.3V |
| GND | GND |

## ThingSpeak setup
1. Create a ThingSpeak account and a new **Channel**.
2. Enable four fields:

| Field | Name | Meaning |
|-------|------|---------|
| Field 1 | Red | Red pulse width (smaller = more red) |
| Field 2 | Green | Green pulse width (smaller = more green) |
| Field 3 | Blue | Blue pulse width (smaller = more blue) |
| Field 4 | Color code | 1 = Red, 2 = Green, 3 = Blue, 0 = No color |

3. Copy the channel's **Write API Key**. The detected color name is also sent as the channel **Status**.

## Working
1. The ESP8266 connects to Wi-Fi.
2. S0 = HIGH and S1 = LOW set the sensor output frequency scaling to 20%.
3. S2 and S3 select the red, green or blue filter. The sensor output pulse width is measured with `pulseIn()`.
4. The color with the smallest pulse width (strongest color) is the detected color. If all pulse widths are above 150 (or the reading times out), the result is NO_COLOR.
5. The three pulse widths, the color code and the color name are sent to ThingSpeak with an HTTP GET request to `/update` on port 80.
6. The program waits 16 seconds before the next update, because the free ThingSpeak plan accepts one update per 15 seconds.

## How to run
1. Open the Arduino IDE, create a new sketch, and copy the code from `color_detection_esp8266_thingspeak.cpp` into it.
2. Replace `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD` and `YOUR_THINGSPEAK_WRITE_API_KEY`.
3. Install the **ESP8266** board package.
4. Select **NodeMCU 1.0 (ESP-12E Module)**, choose the COM port and upload.
5. Open the Serial Monitor at **115200 baud**, then hold a red, green or blue object in front of the sensor.
6. Open your ThingSpeak channel to see the graphs and the latest status.

## Calibration
Pulse widths depend on the sensor and the lighting. If the wrong color is detected, hold a red, green and blue object in front of the sensor, check the values printed on the Serial Monitor, and adjust `NO_COLOR_LIMIT` in the code.

## Sample output
```
Connecting to WiFi....
WiFi connected!
R=30 G=120 B=125 -> RED
Requesting URL: /update?api_key=YOUR_THINGSPEAK_WRITE_API_KEY&field1=30&field2=120&field3=125&field4=1&status=RED
```
