// Push button toggles 4 LEDs ON/OFF (Tinkercad, Arduino Uno)

int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int button = 2;

int ledState = LOW;       // LEDs start OFF
int lastButton = HIGH;    // button not pressed

void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
  int buttonNow = digitalRead(button);

  // button pressed (goes from HIGH to LOW)
  if (buttonNow == LOW && lastButton == HIGH)
  {
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;

    digitalWrite(led1, ledState);
    digitalWrite(led2, ledState);
    digitalWrite(led3, ledState);
    digitalWrite(led4, ledState);
  }

  lastButton = buttonNow;
}
