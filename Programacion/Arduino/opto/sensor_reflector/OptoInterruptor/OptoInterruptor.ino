#define LED1 2
#define LED2 3  
#define Opto A4

int Opto_lee;
                                            
void setup() {
 pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(Opto, INPUT);

}

void loop() {
  Opto_lee = digitalRead(Opto);

  if (Opto_lee == 1) {
   digitalWrite(LED1, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    delay(500);
    digitalWrite(LED2, HIGH);
    delay(500);
    digitalWrite(LED2, LOW);
    delay(500);
  } else {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
  }  }
