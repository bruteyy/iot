/*
 * Interface a Color Sensor (TCS3200) with Blynk
 * Platform: ESP8266 (NodeMCU) + TCS3200 color sensor + Blynk IoT cloud
 *
 * Before uploading, replace the placeholders below:
 *   BLYNK_AUTH_TOKEN -> your Blynk device auth token
 *   ssid / pass      -> your Wi-Fi name and password
 *
 * Pin connections (NodeMCU -> TCS3200):
 *   D1 -> S0, D2 -> S1, D3 -> S2, D4 -> S3, D5 -> OUT
 *   3.3V -> VCC, GND -> GND
 *
 * Blynk datastreams:
 *   V0 = Red LED, V1 = Green LED, V2 = Blue LED, V3 = Text (detected color)
 */

// Blynk setup

#define BLYNK_TEMPLATE_ID "TMPL67ChRbklj"
#define BLYNK_TEMPLATE_NAME "COLOR SENSOR"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk LEDs (virtual pins)
WidgetLED ledR(V0);
WidgetLED ledG(V1);
WidgetLED ledB(V2);

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";        // WiFi Name
char pass[] = "YOUR_WIFI_PASSWORD";   // WiFi Password

// Sensor pins
int S0 = D1;
int S1 = D2;
int S2 = D3;
int S3 = D4;
int sensorOut = D5;

BlynkTimer timer;
bool sensorReady = false;   // NEW FLAG for stabilization

// Read one color value
int readColor(bool s2, bool s3) {
  digitalWrite(S2, s2);
  digitalWrite(S3, s3);
  delay(50);
  return pulseIn(sensorOut, LOW);   // measure frequency
}

// Detect which color is lowest value
String detectColor() {
  int red   = readColor(LOW, LOW);
  int green = readColor(HIGH, HIGH);
  int blue  = readColor(LOW, HIGH);

  Serial.print("R="); Serial.print(red);
  Serial.print(" G="); Serial.print(green);
  Serial.print(" B="); Serial.println(blue);

  if (red < green && red < blue && red < 20)   return "RED";
  if (green < red && green < blue) return "GREEN";
  if (blue < red && blue < green)  return "BLUE";
  return "UNKNOWN";
}

// Send detected color to Blynk
void sendColor() {
  // Skip detection until sensor stabilizes
  if (!sensorReady) {
    Serial.println("Waiting for sensor stabilization...");
    return;
  }

  String color = detectColor();
  Blynk.virtualWrite(V3, color);   // Show text in app

  // Turn off all LEDs first
  ledR.off(); 
  ledG.off(); 
  ledB.off();

  if (color == "RED") {   
      ledR.on();
      Serial.println("Detected: RED (Red ON, Green OFF, Blue OFF)");
  }
  else if (color == "GREEN") {
      ledG.on();
      Serial.println("Detected: GREEN (Green ON, Red OFF, Blue OFF)");
  }
  else if (color == "BLUE")  {
      ledB.on();
      Serial.println("Detected: BLUE (Blue ON, Red OFF, Green OFF)");
  }
  else {
      // UNKNOWN → all OFF
      Blynk.virtualWrite(V3, "No Color Detected");
      Serial.println("No Color Detected → All LEDs OFF");
  }
}

void setup() {
  // Turn off all LEDs first
  ledR.off(); 
  ledG.off(); 
  ledB.off();
  Serial.begin(115200);

  // WiFi + Blynk
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nWiFi Connected!");
  Blynk.config(auth);

  // Sensor pin setup
  pinMode(S0, OUTPUT); pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT); pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  // Sensor frequency scaling
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  // ✅ Default message
  Blynk.virtualWrite(V3, "No Color Detected");
  Serial.println("System Started → Default State: All LEDs OFF");

  // Run every 1 sec
  timer.setInterval(1000L, sendColor);

  // Give sensor 3 sec to stabilize
  timer.setTimeout(3000L, []() {
    sensorReady = true;
    Serial.println("Sensor Ready → Now detecting colors!");
  });
}

void loop() {
  Blynk.run();
  timer.run();
}
