#include "pitches.h"

const int buttonPin = 2;
const int buzzerPin = 8;
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_C5, NOTE_B4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_G5, NOTE_E5, NOTE_C5, NOTE_B4, NOTE_A4,
  NOTE_F5, NOTE_F5, NOTE_E5, NOTE_C5, NOTE_D5, NOTE_C5
};
int noteDurations[] = {
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 4, 2,
  4, 8, 4, 4, 4, 2
};
void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    for (int i = 0; i < sizeof(melody) / sizeof(int); i++) {
      int noteDuration = 1000 / noteDurations[i];
      tone(buzzerPin, melody[i], noteDuration);

      discoEffect();

      delay(noteDuration * 1.3);
      noTone(buzzerPin);
    }
  } else {
    analogWrite(redPin, 0);
    analogWrite(greenPin, 0);
    analogWrite(bluePin, 0);
  }
}

void discoEffect() { //rgb lightup
  analogWrite(redPin, random(0, 256));
  analogWrite(greenPin, random(0, 256));
  analogWrite(bluePin, random(0, 256));
}
