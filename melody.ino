/*
Written by Engr Brandon NM
Dec 22 2021
*/
#include <LiquidCrystal_I2C.h>
#include"pitches.h"
#define melodyPin 9
//
LiquidCrystal_I2C lcd(0x27,16,2); 
// Jingle Bells
int melody[]={
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_G5, NOTE_C5, NOTE_D5,
  NOTE_E5,
  NOTE_F5, NOTE_F5, NOTE_F5, NOTE_F5,
  NOTE_F5, NOTE_E5, NOTE_E5, NOTE_E5, NOTE_E5,
  NOTE_E5, NOTE_D5, NOTE_D5, NOTE_E5,
  NOTE_D5, NOTE_G5
};
int tempo[]={
  8, 8, 4,
  8, 8, 4,
  8, 8, 8, 8,
  2,
  8, 8, 8, 8,
  8, 8, 8, 16, 16,
  8, 8, 8, 8,
  4, 4
};

// We wish you a merry Christmas
int wish_melody[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};
int wish_tempo[] = {
  4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 4,
  4, 8, 8, 8, 8,
  4, 4, 8, 8,
  4, 4, 4,
  2
};

// Santa Claus is coming to town
int santa_melody[]={
  NOTE_G4,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, NOTE_C5,
  NOTE_E4, NOTE_F4, NOTE_G4, NOTE_G4, NOTE_G4,
  NOTE_A4, NOTE_G4, NOTE_F4, NOTE_F4,
  NOTE_E4, NOTE_G4, NOTE_C4, NOTE_E4,
  NOTE_D4, NOTE_F4, NOTE_B3,
  NOTE_C4
};
int santa_tempo[]={
  8,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 4, 4,
  8, 8, 4, 2,
  4, 4, 4, 4,
  4, 2, 4,
  1
};

int switchOne = 0;
int switchTwo = 0;
int switchThree = 0;
//
int red=6;
int green=10;
int blue=11;

//A simple function to set for each color from 0 - 255
void setColor(int redvalue, int greenvalue, int bluevalue){
  analogWrite(red,255-redvalue);
  analogWrite(green,255-greenvalue);
  analogWrite(blue,255-bluevalue);
}
//
void e(){
  setColor(255,0,0);
  delay(300);
  setColor(0,255,0);
  delay(300);
  setColor(0,0,255);
  delay(300);
  setColor(255,255,0);
  delay(300);
  setColor(255,0,255);
  delay(300);
  setColor(255,0,255);
  delay(300);
  setColor(255,255,255);
  delay(300);
  setColor(250,49,155);
  delay(300);
  setColor(29,0,55);
  delay(300);
  setColor(255,100,180);
  delay(300);
  setColor(255,1000,55);
  delay(300);
  setColor(25,39,95);
  delay(300);
  setColor(25,65,255);
  delay(300);
  //
}
//
void setup(void){
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  
  pinMode(9,OUTPUT); // Buzzer
  pinMode(13,OUTPUT); // Led indicator when singing a note
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  //
  lcd.init();
  lcd.clear();
  lcd.backlight();

 /* lcd.setCursor(2,0);
  lcd.print("Designed by");
  lcd.setCursor(0,1);
  lcd.print("Engr Brandon NM");
  delay(5000);
  lcd.clear();
*/
  lcd.setCursor(0,0);
  lcd.print("Welcome! Press");
  lcd.setCursor(0,1);
  lcd.print("any button");
  //
}
void d(){
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
}

void loop(){ 
  //
  
  switchOne=digitalRead(2);
  switchTwo=digitalRead(3);
  switchThree=digitalRead(4);
  if(switchOne==HIGH) {
    sing(1);
      e();
      d();
  } 
  else if(switchTwo==HIGH) {
    sing(2);
      e();
      d();
  } 
  else if(switchThree==HIGH) {
    sing(3);
      e();
      d();
  }
}
int song = 0;

void sing(int s) {
  // iterate over the notes of the melody:
  song = s;
  if (song == 3) {
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("We wish you a ");
    lcd.setCursor(0,1);
    lcd.print("Merry Christmas");
    //
    Serial.println(" 'We wish you a Merry Christmas'");
    int size = sizeof(wish_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / wish_tempo[thisNote];

      buzz(melodyPin, wish_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
    }
    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MERRY CHRISTMASS");
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("from us to");
  delay(3000);
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("NERVTEK");
  } 
}  else if (song == 2) {
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Santa Claus is");
    lcd.setCursor(0,1);
    lcd.print("coming to town");
    //
    Serial.println(" 'Santa Claus is coming to town'");
    int size = sizeof(santa_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 900 / santa_tempo[thisNote];

      buzz(melodyPin, santa_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);

    lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("MERRY CHRISTMASS");
  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("from us to");
  delay(3000);
  lcd.clear();
  lcd.setCursor(4,1);
  lcd.print("NERVTEK");
} 
  }else {
    lcd.setCursor(0,0);
    lcd.clear();
    lcd.print("Jingle bells");
//
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];

       buzz(melodyPin, melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);

      // stop the tone playing:
      buzz(melodyPin, 0, noteDuration);
    }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("MERRY CHRISTMASS");
    lcd.clear();
    lcd.setCursor(2,0);
    lcd.print("from us to");
    delay(3000);
    lcd.clear();
    lcd.setCursor(4,1);
    lcd.print("NERVTEK");
  }
}
void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }  
  digitalWrite(13, LOW);
//
}
