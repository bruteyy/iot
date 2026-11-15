#include <Servo.h>

const int trigPin = 10;
const int echoPin = 11;
const int servoPin = 9;
const int buzzerPin = 3;

Servo radarServo;

long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);

  radarServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // Scan from left to right
  for (int angle = 0; angle <= 180; angle += 2) {
    scanAtAngle(angle);
  }

  // Scan from right to left
  for (int angle = 180; angle >= 0; angle -= 2) {
    scanAtAngle(angle);
  }
}

void scanAtAngle(int angle) {
  radarServo.write(angle);
  delay(20);

  // Send a short ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo time and calculate distance in centimetres
  duration = pulseIn(echoPin, HIGH, 25000);
  distance = duration * 0.034 / 2;

  // Ignore invalid readings and objects beyond 200 cm
  if (duration == 0 || distance > 200) {
    distance = 200;
  }

  // Send angle and distance to the radar display
  Serial.print(angle);
  Serial.print(",");
  Serial.println(distance);

  // Sound an alert when an object is within 30 cm
  if (distance > 0 && distance <= 30) {
    tone(buzzerPin, 1000);
  } else {
    noTone(buzzerPin);
  }
}
