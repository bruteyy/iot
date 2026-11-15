/*
  Project: Object Counting System
  Hardware: Arduino Uno + IR Sensor
  Software: Microsoft Excel Data Streamer

  Working:
  1. IR sensor detects an object.
  2. Arduino increments the object count.
  3. Arduino sends the count and sensor state
     to Excel through USB serial communication.
*/

// Define the digital pin connected to the IR sensor
const int sensorPin = 2;

// Variable to store the total number of objects
unsigned long objectCount = 0;

// Variables to store the current and previous sensor states
int currentState;
int lastState = HIGH;

// Store the time of the last valid detection
unsigned long lastDetectionTime = 0;

// Minimum time interval between valid detections
const unsigned long debounceDelay = 100;

// Function executed once when Arduino starts
void setup()
{
  // Configure sensor pin as an input
  pinMode(sensorPin, INPUT);

  // Start serial communication at 9600 baud
  // Excel Data Streamer must use the same baud rate
  Serial.begin(9600);

  // Send column headings to Excel in CSV format
  Serial.println("ObjectCount,SensorState");
}

// Function executed repeatedly
void loop()
{
  // Read the current signal from the IR sensor
  currentState = digitalRead(sensorPin);

  // Detect a HIGH-to-LOW transition.
  // This assumes the sensor output becomes LOW
  // when an object is detected.
  if (lastState == HIGH && currentState == LOW)
  {
    // Get the current time in milliseconds
    unsigned long now = millis();

    // Check whether enough time has passed
    // since the previous valid detection
    if (now - lastDetectionTime >= debounceDelay)
    {
      // Increase the object count by one
      objectCount++;

      // Save the time of this detection
      lastDetectionTime = now;
    }
  }

  // Save the current state for the next loop
  lastState = currentState;

  // Variable to control how often data is sent
  static unsigned long lastSendTime = 0;

  // Send updated data every 200 milliseconds
  if (millis() - lastSendTime >= 200)
  {
    // Send the total object count
    Serial.print(objectCount);

    // Separate the two values with a comma
    Serial.print(",");

    // Send 1 when an object is detected,
    // otherwise send 0
    Serial.println(currentState == LOW ? 1 : 0);

    // Update the last transmission time
    lastSendTime = millis();
  }
}
