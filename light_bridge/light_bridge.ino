#include "Display.h"
const int LDR = A2;
const int GreenLED = 5;
enum State {
  LIGHTED, SHADED
};

State state = LIGHTED;

int Dark_Threshold = 400;
int Light_Threshold = 600;
int number = 0;



void setup() {

  pinMode(LDR, INPUT);
  pinMode(GreenLED, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  bool State_checker = false;
  State_checker = LDRTHRES();
  if (State_checker == true) {
    digitalWrite(GreenLED, HIGH);
    delay(150);
    digitalWrite(GreenLED, LOW);
    delay(150);
    digitalWrite(GreenLED, HIGH);
    delay(150);
    digitalWrite(GreenLED, LOW);
    Display.show(++number);
  Serial.println("number");

  }


}

bool LDRTHRES() {

  bool returner = false;
  int val = analogRead(LDR);
  // Serial.println(val);
  if ( state == LIGHTED && val < Dark_Threshold) {
    returner = true;
    state = SHADED;
//Serial.println("Ready");
  }

  else if (state == SHADED && val > Light_Threshold) {
    returner = false;
    state = LIGHTED;
  //  Serial.println("nop");
  }

  return returner;
}
