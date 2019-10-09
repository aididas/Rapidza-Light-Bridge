#include "Display.h"
const int LDR = A2;
const int GreenLED = 5;
int Dark_Threshold = 220;
int Light_Threshold = 500;
int number = 0;
  

void setup() {
  pinMode(LDR,INPUT);
  pinMode(GreenLED,OUTPUT);
}


void loop() {

bool checker = false;
checker = LDRTHRES();
if(checker == true){
    digitalWrite(GreenLED,HIGH);
    delay(500);
    digitalWrite(GreenLED, LOW);
    delay(500);    
    digitalWrite(GreenLED,HIGH);
    delay(500);
    digitalWrite(GreenLED, LOW);
    delay(500);
    Display.show(++number);
  }
  
}

bool LDRTHRES(){

  bool returner = false;
  int val = analogRead(LDR);
  Serial.println(val);
  if (val < Dark_Threshold){
    returner = true;
  }
  
  else if(val > Light_Threshold){ 
    returner = false;
  }

  return returner;
}
