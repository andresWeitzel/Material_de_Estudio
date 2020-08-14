#include "sistem.h"

int flag=0;
int cont1=0;


void setup() {
  initPorts();
  initTimer2();
  Serial.begin(9600);
 // Serial.println("aisvdjabs");
  
}

void loop() {
  animacionLedTestigo();
  
  char receive=Serial.read();
   if(Serial.available()){//si hay algo en el puerto serie luego leemos con la otra funcion serial.read
    
      Serial.println(receive);//imprimimos lo que guardamos en la variable receive
   }

}




//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2 = 5;                              // contador para parpadeo de led
  cont1++;
  
  if (cont1 == TOSC)
  {
    cont1 = 0;
    flag = 1;
  }
  
}

/*void serialEvent(){
  while(Serial.available()){//si hay algo en el puerto serie luego leemos con la otra funcion serial.read
    char receive=Serial.read();
      Serial.println(receive);//imprimimos lo que guardamos en la variable receive

  }
}*/
