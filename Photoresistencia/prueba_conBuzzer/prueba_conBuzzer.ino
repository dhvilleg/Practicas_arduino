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

const int buzzerPin = 3; 
const int songLength = 18;
char notes[] = "cdfda ag cdfdg gf ";
int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};
int tempo = 113;
void setup() {
  Serial.begin(9600);
  Serial.write("write this");
  pinMode(buzzerPin, OUTPUT);
  for (int led = 0; led < NbrLEDs; led++)
  {
    pinMode(ledPins[led], OUTPUT);// make all the LED pins outputs
  }
}

void music()
{
  int i, duration;
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms
    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  // We only want to play the song once, so we'll pause forever:
  while(true){}
  return 0;
}

void loop() {
  
  sensorValue = analogRead(photocellPin);
  Serial.print("SensorValue ");
  Serial.println(sensorValue);
  ledLevel = map(sensorValue, 300, 1023, 0, NbrLEDs);  // map to the number of LEDs
  if(sensorValue >= 100 && sensorValue <= 662)
  {
    for(int i = 0;i < NbrLEDs; i++)
    {
      digitalWrite(ledPins[i],HIGH);
    }
  }
  else
  {
    
    for(int i = NbrLEDs;i > 0; i--)
    {
      digitalWrite(ledPins[i],LOW);
      delay(30);
    }
    music();
  }

}

int frequency(char note) 
{
  // This function takes a note character (a-g), and returns the
  // corresponding frequency in Hz for the tone() function.
  int i;
  const int numNotes = 8;  // number of notes we're storing
  // The following arrays hold the note characters and their
  // corresponding frequencies. The last "C" note is uppercase
  // to separate it from the first lowercase "c". If you want to
  // add more notes, you'll need to use unique characters.
  // For the "char" (character) type, we put single characters
  // in single quotes.
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  // Now we'll search through the letters in the array, and if
  // we find it, we'll return the frequency for that note.
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);  // We looked through everything and didn't find it,
              // but we still need to return a value, so return 0.
}
      
