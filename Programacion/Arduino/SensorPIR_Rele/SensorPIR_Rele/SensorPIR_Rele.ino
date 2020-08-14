int PIR = 2;
int RELE = 3;
int estado = 0;

void setup() {
  pinMode(PIR, INPUT);
  pinMode(RELE, OUTPUT);
  //delay para configuracion del sendor del pir
  delay(20000);

}

void loop() {
estado=digitalRead(PIR);
if (estado== HIGH){
  digitalWrite(RELE,HIGH);
  delay(4000);  
}else{
  digitalWrite(RELE,LOW);
  
}
}
