int led = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);




}

void loop() {

  led = digitalRead(2);

  if (led == HIGH)
  {
    digitalWrite(3, HIGH);
  }

  if (led == LOW)
  {
    digitalWrite(3, LOW);
  }


}


