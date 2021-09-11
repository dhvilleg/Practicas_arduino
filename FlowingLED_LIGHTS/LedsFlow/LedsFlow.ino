const int lowestPin = 5;
const int highestestPin = 13;
const int keyPin = 4;
const int thisPinw = 11;
void setup() {
  // put your setup code here, to run once:
  pinMode(keyPin,INPUT);
  for(int thisPin = lowestPin;thisPin <= highestestPin;thisPin++)
  {
    pinMode(thisPin,OUTPUT);
  }
  pinMode(thisPinw,OUTPUT);
  Serial.begin(9600);
  Serial.write("write this");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(keyPin) == HIGH)
  {
    //Serial.print(78);
    for(int thisPin = lowestPin; thisPin <= highestestPin; thisPin++)
    {
      Serial.print(thisPin);
      digitalWrite(thisPin,HIGH);
      delay(50);
    }
    for(int thisPin = highestestPin; thisPin >= lowestPin; thisPin--)
    {
      Serial.print(thisPin);
      digitalWrite(thisPin,LOW);
      delay(50);
    }
  }
  else
  {
    //Serial.println("78");
    
    digitalWrite(thisPinw,HIGH);
  }
}
