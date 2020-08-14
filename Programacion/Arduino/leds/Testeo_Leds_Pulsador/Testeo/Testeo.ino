#define ledRojo 2
#define ledAmarillo 3
#define ledVerde 4
#define ledAzul 5
#define S1 6
#define S2 7
int estado_s1=0;
int estado_s2=0;

void setup() {
pinMode(ledRojo,OUTPUT);
pinMode(ledAmarillo,OUTPUT);
pinMode(ledVerde,OUTPUT);
pinMode(ledAzul,OUTPUT);
pinMode(S1,INPUT);
}

void loop() {
  estado_s1=digitalRead(S1);
  estado_s2=digitalRead(S2);
  if(estado_s1==HIGH){
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
  }else{
    digitalWrite(ledAzul,LOW);
digitalWrite(ledRojo,LOW);
digitalWrite(ledVerde,LOW);
digitalWrite(ledAmarillo,LOW);
delay(300);
  }

  if(estado_s2==HIGH){
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
  }else{
    digitalWrite(ledAzul,LOW);
digitalWrite(ledRojo,LOW);
digitalWrite(ledVerde,LOW);
digitalWrite(ledAmarillo,LOW);
delay(300);
  }
}
