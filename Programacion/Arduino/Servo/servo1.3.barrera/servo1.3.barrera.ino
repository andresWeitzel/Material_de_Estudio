#include <Servo.h>

/*
   2 pulsadores
   1ro levanta
   2do baja barrera 180°


*/
Servo chino;

void setup() {

  Serial.begin(9600);
  chino.attach(4);
  pinMode(5, INPUT);
  pinMode(6, INPUT);



}

void loop() {

  if (digitalRead(5) == HIGH && digitalRead(6) == LOW) {
    for (int i = 0; i < 180; i++) {
      chino.write(i);
      Serial.print("Grados Servo:\n");
      Serial.print(i);
      delay(15);
    }
  }
  if (digitalRead(5) == LOW && digitalRead(6) == HIGH) {
    for (int i = 180; i > 0; i--) {
      chino.write(i);
      Serial.print("Grados Servo:\n");
      Serial.print(i);
      delay(15);
    }
  }
}





