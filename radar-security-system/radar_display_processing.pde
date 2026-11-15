import processing.serial.*;

Serial myPort;

int angle = 0;
int distance = 200;
int maxDistance = 200;

void setup() {
  size(900, 600);
  println(Serial.list());

  // Change the index if Arduino is not on the first listed port.
  // Close Arduino Serial Monitor before running this sketch.
  myPort = new Serial(this, Serial.list()[0], 9600);
  myPort.bufferUntil('\n');
}

void draw() {
  background(0);
  translate(width / 2, height - 40);

  // Radar range arcs
  noFill();
  stroke(0, 220, 0);
  strokeWeight(2);
  for (int r = 50; r <= maxDistance; r += 50) {
    arc(0, 0, r * 4, r * 4, PI, TWO_PI);
  }

  // Radar angle lines
  for (int a = 0; a <= 180; a += 30) {
    float x = maxDistance * 2 * cos(radians(a));
    float y = -maxDistance * 2 * sin(radians(a));
    line(0, 0, x, y);
  }

  // Current scanning line
  stroke(0, 255, 0);
  float sx = maxDistance * 2 * cos(radians(angle));
  float sy = -maxDistance * 2 * sin(radians(angle));
  line(0, 0, sx, sy);

  // Draw detected object
  if (distance > 0 && distance <= maxDistance) {
    float objectX = distance * 2 * cos(radians(angle));
    float objectY = -distance * 2 * sin(radians(angle));
    fill(255, 0, 0);
    noStroke();
    ellipse(objectX, objectY, 12, 12);
  }

  // Status text
  resetMatrix();
  fill(0, 255, 0);
  textSize(20);
  text("ULTRASONIC RADAR", 25, 35);
  text("Angle: " + angle + " degrees", 25, 70);
  text("Distance: " + distance + " cm", 25, 100);

  if (distance > 0 && distance <= 30) {
    fill(255, 0, 0);
    text("WARNING: OBJECT NEAR!", 25, 135);
  } else {
    fill(0, 255, 0);
    text("Area clear", 25, 135);
  }
}

void serialEvent(Serial p) {
  String data = p.readStringUntil('\n');
  if (data != null) {
    data = trim(data);
    String[] values = split(data, ',');
    if (values.length == 2) {
      angle = int(values[0]);
      distance = int(values[1]);
    }
  }
}
