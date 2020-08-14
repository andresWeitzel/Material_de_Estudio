#include <Servo.h>

#define pinServo 3
#define pinPotenciometro A0

Servo servo1;


void setup() {
  servo1.attach(pinServo);
  Serial.begin(9000600);
}

void loop() {
  int lido = analogRead(pinPotenciometro);
  byte angulo = map(lido, 0, 1023, 0, 179);

  servo1.write(angulo);

  Serial.print("A0:");
  Serial.print(lido);
  Serial.print(" angulo:");
  Serial.println(angulo);
  
}
