

#include "sistem.h"
#include "arduino.h"
 
 extern int timeOut=0;
 extern bool latch;  
 extern bool inpToTest=0; 


//*******************************************************
//Configura puertos
//******************************************************
void initPorts(void)
{
  pinMode(ROJO,OUTPUT);
  pinMode(AMARILLO,OUTPUT);
  pinMode(AZUL,OUTPUT);
  pinMode(SEGA,OUTPUT);
  pinMode(SEGB,OUTPUT);
  pinMode(SEGC,OUTPUT);
  pinMode(SEGD,OUTPUT);
  pinMode(SEGE,OUTPUT);
  pinMode(SEGF,OUTPUT);
  pinMode(SEGG,OUTPUT);
  pinMode(SEGSP,OUTPUT);
  pinMode(T1,OUTPUT);
  pinMode(T2,OUTPUT);
  pinMode(T3,OUTPUT);
  pinMode(P1,INPUT);
  pinMode(P2,INPUT);
  
}
void antirrebote(void)
{
  
  bool inputReal;
  inputReal=digitalRead(P1);
  if(inputReal!=latch)
  {
    latch=inputReal;
    timeOut=ANTIRREBOTE;
  }
  else
  {
   
    if(timeOut>0)
    {
      timeOut--;
    }
    else
    {
      inpToTest=latch;
    }
  }
}

//*******************************************************
//Configura Timer2
//******************************************************
void initTimer2(void)
{
   SREG = 0b01111111;       //Desabilitar interrupciones
   TIMSK2 = 0b00000001;     //Habilita la interrupcion por desbordamiento
   TCCR2B = 0b00000011;     //Configura preescala para que FT2 sea de 250KHz
   SREG = 0b10000000;       //Habilitar interrupciones //Desabilitar interrupciones
   TCNT2=5;                 //255-5 =250 (el valor que queremos)
}  
