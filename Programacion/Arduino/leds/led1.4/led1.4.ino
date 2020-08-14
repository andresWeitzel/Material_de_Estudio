void setup() {
  pinMode(2, OUTPUT);

}

void loop() {

  int i=0;//variable de contro tipo entero

  for(i=0; i<10; i++){
  
    digitalWrite(2,HIGH);
    delay(100*i);
    digitalWrite(2,LOW);
    delay(1000);
}
  

}
