# Interface DHT11 and Upload Sensor Data to the Cloud

## Problem Statement
Write a program to interface DHT11 and upload sensor data to the cloud.

## Aim
To interface a DHT11 temperature and humidity sensor with a NodeMCU (ESP8266) and upload the sensor data to the ThingSpeak cloud.

## Components
| Component | Quantity |
|-----------|----------|
| NodeMCU ESP8266 | 1 |
| DHT11 sensor | 1 |
| Jumper wires / breadboard | as needed |
| Wi-Fi connection | 1 |
| ThingSpeak account (free) | 1 |

## Connections
| DHT11 pin | NodeMCU pin |
|-----------|-------------|
| VCC | 3.3V |
| GND | GND |
| DATA | D4 |

## ThingSpeak setup
1. Create a ThingSpeak account and a new **Channel**.
2. Enable two fields: **Field 1 = Temperature**, **Field 2 = Humidity**.
3. Copy the channel's **Write API Key** (and Read API Key if needed).

## Working
1. The NodeMCU connects to Wi-Fi.
2. The DHT11 temperature (in Celsius) and humidity (%) are read using the `DHT` library.
3. If a reading fails (`NaN`), an error is printed and the reading is retried after 5 seconds.
4. The values are sent to ThingSpeak with an HTTP GET request to `/update` on port 80, as field1 (temperature) and field2 (humidity).
5. The program waits about 16 seconds before the next update, because the free ThingSpeak plan accepts one update per 15 seconds.

## How to run
1. Open the Arduino IDE, create a new sketch, and copy the code from `dht11_thingspeak.cpp` into it.
2. Install the **DHT sensor library** (Adafruit), the **Adafruit Unified Sensor** library and the **ESP8266** board package.
3. Replace `YOUR_WIFI_SSID`, `YOUR_WIFI_PASSWORD`, `YOUR_THINGSPEAK_WRITE_API_KEY` and `YOUR_THINGSPEAK_READ_API_KEY`.
4. Select **NodeMCU 1.0 (ESP-12E Module)**, choose the COM port and upload.
5. Open the Serial Monitor at **115200 baud** to see the readings.
6. Open your ThingSpeak channel to see the live graphs for temperature and humidity.

## Sample output
```
Connecting to WiFi....
WiFi connected!
Temp: 28.00 °C, Humidity: 62.00 %
Requesting URL: /update?api_key=YOUR_THINGSPEAK_WRITE_API_KEY&field1=28.00&field2=62.00
```
