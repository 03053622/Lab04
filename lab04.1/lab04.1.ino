#include "SevSeg.h"
SevSeg sevseg; //Instantiate a seven segment object
int Hour=0;
int Min=0;
void setup() {
byte numDigits = 4;
byte digitPins[] = {5,4,3,2}; //千百十個
byte segmentPins[] = {10,8,11,12,13,14,9}; //a-g
sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
}

void loop() {
  sevseg.setNumber(Hour * 100 + Min, 0);
  Min += 1;
  if(Min == 60){
    Min = 0;
    if(Hour == 23)
      Hour=0;
    else
      Hour++;
  }
  sevseg.refreshDisplay();
  delay(300);
}
