#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};
int melody2[] = {
  NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int noteDurations2[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};
int sensorPin = A0;
int sensorValue = 0;
int x=0;
int state = 6;
int oldstt;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
state == oldstt;
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
//boolean start = true;
int x=0;
int high=0;
int low=0;


while (x <= 14){
sensorValue = analogRead(sensorPin);

Serial.println(sensorValue);

if(sensorValue > 1000){
  high = high+1;
}
if(sensorValue <= 0){
  low=low+1;
}
x+=1;
delay(50);
}


if (high==15){
state=0;
}

if (high<=14 and high >=13){
state=1;
}


if (high<=12 and high >=9){
state=2;
}


if (high<=8 and high >=4){
state=3;
}

Serial.println(" ");
Serial.println(" ");
Serial.print("   High : ");
Serial.print(high);
Serial.print("   Low : ");
Serial.println(low);
Serial.print("   State : ");
Serial.print(state);
Serial.print("   Old State : ");
Serial.println(oldstt);
Serial.println(" ");

 
 if(state != oldstt){
/*  digitalWrite(7,150);
  digitalWrite(13,HIGH);
  delay(500);
  digitalWrite(7,LOW);
   digitalWrite(13,LOW);
  delay(500);*/
 

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
   
    tone(8, melody2[0]);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    
    delay(250);
    // stop the tone playing:
    noTone(8);
  
 }

oldstt = state;
Serial.print("   Old State : ");
Serial.println(oldstt);
Serial.println("_______________________________________");
Serial.println(" ");
}
