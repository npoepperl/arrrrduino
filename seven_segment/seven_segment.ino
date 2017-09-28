#include "TimerOne.h"

#define LED_A 2
#define LED_B 3
#define LED_C 4
#define LED_D 5
#define LED_E 6
#define LED_F 7
#define LED_G 8
#define LED_DP 9

#define TRANSISTOR_LEFT 10
#define TRANSISTOR_RIGHT 11

int currentPin;
int currentTransistor;

void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(flipSegment);

  
  for(int led = LED_A; led <= TRANSISTOR_RIGHT; led++){
    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
  }
  
  currentPin = LED_DP;
  currentTransistor = TRANSISTOR_RIGHT;
}

void flipSegment(){
    digitalWrite(currentTransistor, LOW);
    currentTransistor = currentTransistor == TRANSISTOR_LEFT ? TRANSISTOR_RIGHT : TRANSISTOR_LEFT;
    digitalWrite(currentTransistor, HIGH);
}

void loop() {
  digitalWrite(currentPin, LOW);
  
  if(currentPin == LED_DP){
    currentPin = LED_A;
  }
  else{
    currentPin++;
  }
  
  digitalWrite(currentPin, HIGH);

  delay(500);
}
