#include "sistem.h"
#include "cmdOP.h"
#include "cmdAD.h"
#include "arduino.h"

extern String str; //var global definida en el .ino
extern int lect_pot; 

void cmdAD()
{
  String accion=str.substring(0,1); //se queda con  Q o S
  if(accion=="Q")
  {
    rAD();
  }
  
}

//mens de respuesta
void rAD()
{
  char str1[10];
  sprintf(str1,">RAD%04d<",lect_pot);
  Serial.println(str1);
}
