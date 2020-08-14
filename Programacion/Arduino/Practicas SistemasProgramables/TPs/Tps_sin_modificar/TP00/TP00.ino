
#define ROJO 2
#define AMARILLO 3
#define P1 6
#define TIEMPO 1000


void setup() 
{
  pinMode(ROJO,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  pinMode(P1,INPUT);
}

void loop() 
{
  digitalWrite(ROJO,0);
  delay(TIEMPO);
  digitalWrite(ROJO,1);
  delay(TIEMPO);

  if(digitalRead(P1)==HIGH)
  {
    digitalWrite(AMARILLO,1);
  }
  else
  {
    digitalWrite(AMARILLO,0);
  }
}
