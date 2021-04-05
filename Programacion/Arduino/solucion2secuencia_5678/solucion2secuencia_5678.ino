int leds[]={5,6,7,8};
int tiempo=200;
int n=0;
void setup() {
  for(n=0;n<4;n++) {
    pinMode (leds[n],OUTPUT);
  }
}
void secuencia() {
  for (n=0;n<4;n++) {
    digitalWrite (leds[n],HIGH);
    delay(tiempo);
    digitalWrite (leds[n],LOW);
    delay(tiempo);
  }
}
void loop() {
  secuencia();
}

