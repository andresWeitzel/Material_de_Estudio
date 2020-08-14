
#include "sistem.h"


#define ROJO 2
#define AZUL 5

bool estLedTest;  //led testigo
bool watchDog=0;
int contWatchDog=0;
String str="";

int lect_pot=0;


void setup() 
{
  initPorts();
  initTimer2();
  Serial.begin(9600);  

}

void loop() 
{
  bool msgNuevo=0;
  if(watchDog)
  {
    lect_pot=analogRead(A0);
    
    watchDog=0;
    estLedTest=!estLedTest;
    digitalWrite(AZUL,estLedTest);
    
  }
  
  if (Serial.available()) 
  {
    char carRec = Serial.read();
    msgNuevo=captureData(carRec);
  }

  if(msgNuevo)
  {
    msgNuevo=0;
    parseMsg();
  }

}

//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2=5;
  contWatchDog++;
  if(contWatchDog==250) 
  {
    contWatchDog=0;
    watchDog=1;
  }
}
