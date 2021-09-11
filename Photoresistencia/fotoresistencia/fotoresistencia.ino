//www.RobotLinking.com
//2015.5.7
/*
  Bargraph sketch

 Turns on a series of LEDs proportional to a value of an analog sensor.
 Six LEDs are controlled but you can change the number of LEDs by changing
 the value of NbrLEDs and adding the pins to the ledPins array
 */

const int NbrLEDs = 8;
const int ledPins[] = { 6, 7, 8, 9, 10, 11, 12, 13};
const int photocellPin = A0;                          
int sensorValue = 0;        // value read from the sensor
int ledLevel = 0;           // sensor value converted into LED 'bars'

void setup() {
  Serial.begin(9600);
  Serial.write("write this");
  for (int led = 0; led < NbrLEDs; led++)
  {
    pinMode(ledPins[led], OUTPUT);// make all the LED pins outputs
  }
}

void loop() {
  
  sensorValue = analogRead(photocellPin);
  Serial.print("SensorValue ");
  Serial.println(sensorValue);
  ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs);  // map to the number of LEDs
  for (int led = 0; led < NbrLEDs; led++)
  {
      Serial.print("led is ");
      Serial.print(led);
      Serial.print(" ledLevel is ");
      Serial.print(ledLevel);
    if (led < ledLevel ) {
      digitalWrite(ledPins[led], HIGH);     // turn on pins less than the level
       Serial.println(" minnor");
    }
    else {
      digitalWrite(ledPins[led],LOW);      // turn off pins higher than 
                                                // the level
      Serial.println(" major");
    }
    delay(5000);
  }
}
      
