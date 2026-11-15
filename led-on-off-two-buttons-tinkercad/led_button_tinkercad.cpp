/*
 * Turn ON LED if button1 is pressed, Turn OFF LED if button2 is pressed
 * Platform: Tinkercad Circuits (Arduino Uno)
 *
 * Connections:
 *   LED anode (+)  -> Pin 8 (through 220 ohm resistor), LED cathode (-) -> GND
 *   Button1        -> one leg to 5V, other leg to Pin 2 (+ 10k resistor from Pin 2 to GND)
 *   Button2        -> one leg to 5V, other leg to Pin 3 (+ 10k resistor from Pin 3 to GND)
 */

const int led = 8;
const int button1 = 2;   // ON button
const int button2 = 3;   // OFF button

bool ledState = false;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT);   // external 10k pull-down resistor used
  pinMode(button2, INPUT);   // external 10k pull-down resistor used
  Serial.begin(9600);
}

void loop()
{
  // Button 1 pressed -> LED ON
  if (digitalRead(button1) == HIGH && !ledState)
  {
    digitalWrite(led, HIGH);
    ledState = true;
    Serial.println("Button 1 pressed: LED ON");
  }

  // Button 2 pressed -> LED OFF
  if (digitalRead(button2) == HIGH && ledState)
  {
    digitalWrite(led, LOW);
    ledState = false;
    Serial.println("Button 2 pressed: LED OFF");
  }
}
