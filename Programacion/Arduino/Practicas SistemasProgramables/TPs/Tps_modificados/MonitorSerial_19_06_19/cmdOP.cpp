
#include "sistem.h"
#include "cmdOP.h"
#include "arduino.h"

extern String str; //var global definida en el .ino

void cmdOP()
{
  String accion=str.substring(0,1); //se queda con  Q o S
  if(accion=="Q")
  {
    rOP();
  }
  if(accion=="S")
  {
    sOP();
  }
}

//mens de respuesta
void rOP()
{
  char str1[10];
  int numOP=str.substring(3,5).toInt(); //QOP02 captura 02
  int x=getOP(numOP);
  sprintf(str1,">ROP%02d%d<",numOP,x);
  Serial.println(str1);
}

//SOP021
void sOP()
{
  int numOP=str.substring(3,5).toInt(); //SOP021 captura 02
  int estOP=str.substring(5,6).toInt();
  setOP(numOP,estOP);
  rOP();
}

void setOP(int numOP, int estOP)
{
  switch(numOP)
  {
    case 0:
    {
      digitalWrite(OP00,estOP);
      break;
    }
    case 1:
    {
      digitalWrite(OP01,estOP);
      break;
    }
    case 2:
    {
      digitalWrite(OP02,estOP);
      break;
    }
  }
}

//devuelve el estado de la salida pasada como argumento
int getOP(int numOP)
{
  int resp;
  switch(numOP)
  {
    case 0:
    {
      resp=digitalRead(OP00);
      break;
    }
    case 1:
    {
      resp=digitalRead(OP01);
      break;
    }
    case 2:
    {
      resp=digitalRead(OP02);
      break;
    }
  }
  return resp;
}
