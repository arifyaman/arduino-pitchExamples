#include "pitches.h"


int pitch = 300;
int btn_state = 0;
boolean btn_lock = false;

int istiklalMarsi[] = {

  NOTE_B4,NOTE_E5,NOTE_FS5,NOTE_G5,NOTE_FS5,NOTE_DS5,NOTE_FS5,NOTE_E5,
  NOTE_E5,NOTE_DS5,NOTE_E5,NOTE_A5,NOTE_B5,NOTE_C6,NOTE_B5,NOTE_GS5,NOTE_B5,NOTE_A5,
  
  NOTE_B5,NOTE_AS5,NOTE_B5,NOTE_FS5,NOTE_FS5,NOTE_A5,NOTE_G5,NOTE_DS5,NOTE_E5,

  
  NOTE_FS5,NOTE_G5,NOTE_A5,NOTE_B5,NOTE_C6,NOTE_D6,NOTE_E6,NOTE_D6,

  NOTE_D5,NOTE_CS5,NOTE_D5,NOTE_B5,NOTE_A5,NOTE_G5,

  NOTE_B4,NOTE_A4,NOTE_B4,NOTE_FS5,NOTE_B4,NOTE_B5,NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_G5,NOTE_E5,

  
  NOTE_E6,NOTE_D6,NOTE_C6,NOTE_B5,NOTE_A5,NOTE_G5,NOTE_FS5,NOTE_E5,NOTE_B5, NOTE_B4, NOTE_E5
  
};


int touchMyTalala[] = {
  NOTE_F6, NOTE_D6, NOTE_E6, NOTE_F6,NOTE_D6, NOTE_E6, NOTE_F6,NOTE_D6, NOTE_E6,NOTE_F6,NOTE_A6,NOTE_G6,NOTE_F6,NOTE_E6,
  NOTE_C6, NOTE_D6, NOTE_E6, NOTE_C6, NOTE_D6, NOTE_E6,NOTE_C6, NOTE_D6, NOTE_E6, NOTE_G6, NOTE_F6,NOTE_E6
  
};


int coffinDance[] = {
 NOTE_D6,NOTE_D6, NOTE_D6, NOTE_D6, NOTE_F6, NOTE_F6, NOTE_F6, NOTE_F6,
 NOTE_E6,NOTE_E6, NOTE_E6, NOTE_E6,NOTE_G6, NOTE_G6, NOTE_G6, NOTE_G6,
 NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A6, NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A6,NOTE_A6,

 NOTE_A6,NOTE_G6,NOTE_F6,NOTE_E6,NOTE_C6,

 NOTE_D6,NOTE_D6,NOTE_A6,NOTE_G6,NOTE_F6,NOTE_E6,NOTE_E6,NOTE_E6, NOTE_G6,NOTE_F6,NOTE_E6,NOTE_D6,
 
 NOTE_D6,NOTE_D7,NOTE_C7,NOTE_D7,NOTE_C7,NOTE_D7,NOTE_D6,NOTE_D6,NOTE_D7,NOTE_C7,NOTE_D7,NOTE_C7,NOTE_D7,
 NOTE_D6,NOTE_D6,NOTE_A6,NOTE_G6,NOTE_F6,NOTE_E6,NOTE_E6,NOTE_E6, NOTE_G6,NOTE_F6,NOTE_E6,NOTE_D6,
 
 NOTE_D6,NOTE_D7,NOTE_C7,NOTE_D7,NOTE_C7,NOTE_D7,NOTE_D6,NOTE_D6,NOTE_D7,NOTE_C7,NOTE_D7,NOTE_C7,NOTE_D7
};



void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
  pinMode(7, INPUT);
}

void checkBtnState(int digital) {
  if(digital == 0) btn_lock = false;
  
  if(btn_lock)return;
  
  if(digital == 1) {
    btn_state++;
    btn_state = btn_state % 600;
    
    btn_lock = true;
  }
  
  
}


void loop() {
  checkBtnState(digitalRead(7));
  int note = coffinDance[btn_state];
  Serial.print(note);
  Serial.print(" - ");
  Serial.print(btn_state);
  Serial.print("\n");
  tone(8, note);
  
  
}
