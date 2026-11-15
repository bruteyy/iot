/*
 * Color Detection and Monitoring Using ESP8266 and ThingSpeak
 * Platform: NodeMCU ESP8266 + TCS3200 color sensor + ThingSpeak
 *
 * Before uploading, replace the placeholders below:
 *   ssid / pass -> your Wi-Fi name and password
 *   apiKey      -> your ThingSpeak channel Write API Key
 *
 * Pin connections (NodeMCU -> TCS3200):
 *   D1 -> S0, D2 -> S1, D5 -> S2, D6 -> S3, D7 -> OUT
 *   3.3V -> VCC, GND -> GND
 *
 * ThingSpeak channel fields:
 *   Field1 = Red pulse width, Field2 = Green pulse width, Field3 = Blue pulse width,
 *   Field4 = Color code (1 = Red, 2 = Green, 3 = Blue, 0 = No color)
 *   Status = Color name
 */

#include <ESP8266WiFi.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";

// ThingSpeak server and API details
const char* host = "api.thingspeak.com";
const char* apiKey = "YOUR_THINGSPEAK_WRITE_API_KEY";

// TCS3200 pins
#define S0 D1
#define S1 D2
#define S2 D5
#define S3 D6
#define SENSOR_OUT D7

// If every pulse width is above this value, there is no object in front of the sensor
const int NO_COLOR_LIMIT = 150;

// Select a color filter and measure the output pulse width (microseconds)
// A smaller pulse width means more of that color
int readColor(bool s2, bool s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(50);                                  // let the filter settle
  return pulseIn(SENSOR_OUT, LOW, 100000);    // 100 ms timeout, returns 0 on timeout
}

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(SENSOR_OUT, INPUT);

  // Output frequency scaling 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
}

void loop() {
  // Read the three color values
  int red   = readColor(LOW, LOW);
  int green = readColor(HIGH, HIGH);
  int blue  = readColor(LOW, HIGH);

  // The color with the smallest pulse width is the dominant color
  String colorName = "NO_COLOR";   // no space, because the name goes inside the URL
  int colorCode = 0;

  if (red > 0 && green > 0 && blue > 0) {
    if (red < green && red < blue && red < NO_COLOR_LIMIT) {
      colorName = "RED";
      colorCode = 1;
    }
    else if (green < red && green < blue && green < NO_COLOR_LIMIT) {
      colorName = "GREEN";
      colorCode = 2;
    }
    else if (blue < red && blue < green && blue < NO_COLOR_LIMIT) {
      colorName = "BLUE";
      colorCode = 3;
    }
  }

  Serial.print("R=");  Serial.print(red);
  Serial.print(" G="); Serial.print(green);
  Serial.print(" B="); Serial.print(blue);
  Serial.print(" -> "); Serial.println(colorName);

  // Create WiFi client
  WiFiClient client;

  // Connect to ThingSpeak and send the data
  if (client.connect(host, 80)) {
    String url = "/update?api_key=" + String(apiKey) +
                 "&field1=" + String(red) +
                 "&field2=" + String(green) +
                 "&field3=" + String(blue) +
                 "&field4=" + String(colorCode) +
                 "&status=" + colorName;

    Serial.print("Requesting URL: ");
    Serial.println(url);

    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
  }
  else {
    Serial.println("Connection to ThingSpeak failed");
  }

  client.stop();  // Close the connection
  delay(16000);   // Wait at least 15 sec for next update (free ThingSpeak limit)
}
