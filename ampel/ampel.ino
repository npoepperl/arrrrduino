#define RED 1
#define YELLOW 2
#define GREEN 3

#define BUTTON 8

int currentLed = RED;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
}

void loop() {
  delay(500);

  if(digitalRead(BUTTON) == LOW){
    currentLed = currentLed < GREEN ? currentLed + 1 : RED;
  }

  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);

  delay(500);

  digitalWrite(currentLed, HIGH);
}
