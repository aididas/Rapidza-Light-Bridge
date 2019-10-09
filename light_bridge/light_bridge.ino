#include "Display.h"
const int LDR = A2;
const int GreenLED = 5;
enum State {
  LIGHTED, SHADED
};

State state = LIGHTED;

int Dark_Threshold = 450;
int Light_Threshold = 600;
int number = 0;

  

void setup() {

  pinMode(LDR,INPUT);
  pinMode(GreenLED,OUTPUT);
}


void loop() {
bool State_checker = false;
State_checker = LDRTHRES();
if(State_checker == true){
    digitalWrite(GreenLED,HIGH);
    delay(150);
    digitalWrite(GreenLED, LOW);
    delay(150);    
    digitalWrite(GreenLED,HIGH);
    delay(150);
    digitalWrite(GreenLED, LOW);
    Display.show(++number);
  }
  
}

bool LDRTHRES(){

  bool returner = false;
  int val = analogRead(LDR);
  if ( state == LIGHTED && val < Dark_Threshold){
    returner = true;
    state = SHADED;
  }
  
  else if(state == SHADED && val > Light_Threshold){ 
    returner = false;
    state = LIGHTED;
  }

  return returner;
}
