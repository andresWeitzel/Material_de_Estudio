
//BLINK1

#define ROJO 2
#define AMARILLO 3
#define P1 6
#define TIEMPO 1
#define TOSC 100


int contMs=0;
bool estado=0;
void setup() 
{
  pinMode(ROJO,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  pinMode(P1,INPUT);
}

void loop() 
{
  delay(TIEMPO);
  contMs++;

  if(contMs==TOSC)
  {
    contMs=0;
    estado=!estado;
    digitalWrite(ROJO,estado);
  }
  
  if(digitalRead(P1)==HIGH)
  {
    digitalWrite(AMARILLO,1);
  }
  else
  {
    digitalWrite(AMARILLO,0);
  }
}
