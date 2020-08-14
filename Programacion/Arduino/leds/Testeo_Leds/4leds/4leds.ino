#define ledRojo 2
#define ledAmarillo 3
#define ledVerde 4
#define ledAzul 5

void setup() {
pinMode(ledRojo,OUTPUT);
pinMode(ledAmarillo,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledAzul,OUTPUT);
}

void loop() {
digitalWrite(ledAzul,HIGH);
digitalWrite(ledRojo,HIGH);
digitalWrite(ledVerde,HIGH);
digitalWrite(ledAmarillo,HIGH);
delay(300);
digitalWrite(ledAzul,LOW);
digitalWrite(ledRojo,LOW);
digitalWrite(ledVerde,LOW);
digitalWrite(ledAmarillo,LOW);
delay(300);
}
