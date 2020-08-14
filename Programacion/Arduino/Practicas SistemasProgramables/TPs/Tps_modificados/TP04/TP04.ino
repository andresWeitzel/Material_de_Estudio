
//BLINK1

#include "sistem.h"
#include "display.h"

int cont=0;
bool estado=0;
bool flag=0;

int numero=127;
int unidad=0;
int decena=0;
int centena=0;

void setup() 
{
  Serial.begin(9600);
  initPorts();
  initTimer2();
}

void loop() 
{
  //animacion led testigo
  if(flag)
  {
    flag=0;
    estado=!estado;
    digitalWrite(AZUL,estado);
    //Serial.println(String(unidad));
  }
  
  unidad=getUnidad(numero);
  decena=getDecena(numero);
  centena=getCentena(numero);

  showDisplay(unidad,1);
  showDisplay(decena,2);

  
  Serial.print(String("Unidad: "));
  Serial.println(String(unidad));
  Serial.print(String("Decena: "));
  Serial.println(String(decena));
  Serial.print(String("Centena: "));
  Serial.println(String(centena));
}


//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2=5;
  cont++;
  if(cont==TOSC) 
  {
    cont=0;
    flag=1;
  }
}
