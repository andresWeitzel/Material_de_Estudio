

#include "sistem.h"
#include "cmdOP.h"
#include "cmdAD.h"
#include "arduino.h"

extern String str;

void initPorts(void)
{
    pinMode(OP00,OUTPUT);
    pinMode(OP01,OUTPUT);
    pinMode(OP02,OUTPUT);
    pinMode(AZUL,OUTPUT);
    
    digitalWrite(OP00,0);
    digitalWrite(OP01,0);
    digitalWrite(OP02,0);
}


//*******************************************************
//Configura Timer2
//Interrup c/1ms
//******************************************************
void initTimer2(void)
{
   SREG = 0b01111111;       //Desabilitar interrupciones
   TIMSK2 = 0b00000001;     //Habilita la interrupcion por desbordamiento
   TCCR2B = 0b00000011;     //Configura preescala para que FT2 sea de 250KHz
   SREG = 0b10000000;       //Habilitar interrupciones //Desabilitar interrupciones
   TCNT2=5;                 //255-5 =250 (el valor que queremos)
}  

//*************************************************************************************
//Rec los carac que entran x el pto serial, cuando hay un paquete completo retorna 1
//*************************************************************************************

bool captureData(char car)
{
  char datoRet=0;
  switch (car)
  {
    case '>':
    {
      str="";
      break;
    }
    case '<':
    {
      datoRet=1;
      break;
    }  
    default:
    {
      str=str+car;
    }
  }
  return datoRet;
}

//str=SOP021
void parseMsg()
{
  String tipoCmd=str.substring(1,3); //captura del car 1 al car 3 (2 caracter) ej: recibe; SP1234 y se queda con P1
  String Valor;
  
  if(tipoCmd=="OP")
  {
    cmdOP();
  }
  if(tipoCmd=="AD")
  {
    cmdAD();
  }
}

/*
void cmdP1()
{
  String tipoMsg=str.substring(0,1); //se queda con  Q o S
  if(tipoMsg=="Q")
  {
    rP1();
  }
  if(tipoMsg=="S")
  {
    sP1=(mensValido.substring(3,6)); //ej:SP1234 se queda con 234
    rP1();
  }
}

//mens de respuesta
void rP1()
{
  Serial.println(">RP1"+sP1+"<");
}
*/
