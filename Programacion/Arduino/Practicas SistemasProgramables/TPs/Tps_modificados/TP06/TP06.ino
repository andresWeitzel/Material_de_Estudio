
//BLINK1

#include "sistem.h"
#include "display.h"

int cont1=0;
int cont2=0;
int numDisplay=1; //indica que display se enciende 1 unid. 2dec 3 cen
int contMseg1=0;
bool latch=0;
//bool inpToTest=0; 
//int timeOut=0;
int valor_inicial=500;

bool estado=0;
bool flag=0;
bool tiempoMultDisp=0;

//int numero=127;
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
  unidad=getUnidad(valor_inicial);
  decena=getDecena(valor_inicial);
  centena=getCentena(valor_inicial);

  if (digitalRead(P1))
  {
   valor_inicial++;
  }
if (digitalRead(P2))
  {
   valor_inicial--;
  }
 
  //multip del disp
  if(tiempoMultDisp)
  {
    tiempoMultDisp=0;
    switch(numDisplay)
    {
      case 1:
      {
        showDisplay(unidad,1);
        break;
      }
       case 2:
      {
        showDisplay(decena,2);
        break;
      }
       case 3:
      {
        showDisplay(centena,3);
        break;
      }
    }
    numDisplay++;
    if(numDisplay==4)
    {
      numDisplay=1;
    }
  }
  

  //animacion led testigo
    if(flag)
  {
    flag=0;
    estado=!estado;
    digitalWrite(AZUL,estado);
   }

}


//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2=5;
  cont1++;
  cont2++;
  if(cont1==TOSC) 
  {
    cont1=0;
    flag=1;
  }
  if(cont2==TDISP) 
  {
    cont2=0;
    tiempoMultDisp=1;
  }
  contMseg1++;
    antirrebote();
    if(contMseg1==TIEMPO1) 
    {
      contMseg1=0;
    }
}
