/*
 * PIR Motion Sensor with LED and Buzzer
 * Platform: Arduino Uno (works on Tinkercad / Wokwi too)
 *
 * Pin connections:
 *   PIR sensor OUT -> Digital pin 2
 *   LED (anode)    -> Digital pin 4 (via 220 ohm resistor, cathode to GND)
 *   Buzzer (+)     -> Digital pin 6 (- to GND)
 *   PIR VCC -> 5V, PIR GND -> GND
 */

int pirpin = 2;
int led =4;
int buzzer=6;
void setup()
{
  pinMode(pirpin,INPUT);
  pinMode(led,OUTPUT);
  pinMode(buzzer,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int motion = digitalRead(pirpin);
  
  if(motion==HIGH){
    digitalWrite(led,HIGH);
    digitalWrite(buzzer,HIGH);
    Serial.println("Motion detected!");
  }
  else{
     digitalWrite(led,LOW);
     digitalWrite(buzzer,LOW);
    Serial.println("Motion not detected");
  }
  delay(1000);
  
}
