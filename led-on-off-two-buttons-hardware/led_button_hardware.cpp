/*
 * Turn ON LED if button1 is pressed, Turn OFF LED if button2 is pressed
 * Platform: Hardware (Arduino Uno)
 *
 * Connections (no external resistors needed for the buttons):
 *   LED anode (+)  -> Pin 8 (through 220 ohm resistor), LED cathode (-) -> GND
 *   Button1        -> one leg to Pin 2, other leg to GND
 *   Button2        -> one leg to Pin 3, other leg to GND
 *
 * Buttons use the Arduino's internal pull-up resistors,
 * so a pressed button reads LOW.
 */

const int led = 8;
const int button1 = 2;   // ON button
const int button2 = 3;   // OFF button

bool ledState = false;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button1, INPUT_PULLUP);   // internal pull-up enabled
  pinMode(button2, INPUT_PULLUP);   // internal pull-up enabled
  Serial.begin(9600);
}

void loop()
{
  // Button 1 pressed (LOW) -> LED ON
  if (digitalRead(button1) == LOW && !ledState)
  {
    digitalWrite(led, HIGH);
    ledState = true;
    Serial.println("Button 1 pressed: LED ON");
    delay(50);   // simple debounce
  }

  // Button 2 pressed (LOW) -> LED OFF
  if (digitalRead(button2) == LOW && ledState)
  {
    digitalWrite(led, LOW);
    ledState = false;
    Serial.println("Button 2 pressed: LED OFF");
    delay(50);   // simple debounce
  }
}
