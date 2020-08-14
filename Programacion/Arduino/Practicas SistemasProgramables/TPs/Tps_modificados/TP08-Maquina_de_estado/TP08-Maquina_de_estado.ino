
//BLINK1

#include "sistem.h"
#include "display.h"

int cont1=0;
int cont2=0;
int numDisplay=1; //indica que display se enciende 1 unid. 2dec 3 cen

bool estado=0;
bool flag=0;
bool tiempoMultDisp=0;
bool startTimer2sec=0;   //0 disable  1 enable habilita timer 2 sec para mostar SP1
bool destello=0;  //0 no destella 1 destella

int setPoint1=0; 
int contSP1=0;
int latch_p1=0;          
int latch_p2=0;
bool latch3=1;  //latch P1+P2 

int unidad=0;
int decena=0;
int centena=0;

int lecturaAD;
int tempActual;

int mEstado=0;  //Maquina de estado

void setup() 
{
  Serial.begin(9600);
  initPorts();
  initTimer2();
}

void loop() 
{

  lecturaAD = analogRead(A0);       //0-1023
  tempActual = ((lecturaAD*10)/102);  //0-100 grados

  tempActualmap=(analogRead(A0),0,1023,0,100);


/*
 if (digitalRead(P1)==1 && latch_p1==0)
  {
    
   latch_p1=1;
  }
 
  
if (digitalRead(P1)==0 && latch_p1==1)
  {
  
   latch_p1=0;
 
   }

if (digitalRead(P2)==1 && latch_p2==0)
  {
    
   latch_p2=1;
  }
 
  
if (digitalRead(P2)==0 && latch_p2==1)
  {
  
   latch_p2=0;
 
   }
*/

  //animacion led testigo
  if(flag)
  {
    flag=0;
    estado=!estado;
    digitalWrite(AZUL,estado);
    //Serial.println(String(unidad));
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
  
  
  
  if (mEstado==0)
  {
    unidad=getUnidad(tempActual);
    decena=getDecena(tempActual);
    centena=getCentena(tempActual);
 
  }
  //Muestra SP1 durante 2 seg
  if (mEstado==1)
  {
    unidad=1;
    decena='P';
    centena=5;
    startTimer2sec=1; //Arranca timer 2 seg para mostrar SP1
 
  }
  if(mEstado==2)
  {
    destello=1;
    unidad=getUnidad(setPoint1);
    decena=getDecena(setPoint1);
    centena=getCentena(setPoint1);
  }
  


  //testeo pulsadores
  if(digitalRead(P1)==1 && digitalRead(P2)==1 &&(latch3==1))
  {
    latch3=0;
    mEstado++;
  }
  
  if(digitalRead(P1)==0 && digitalRead(P2)==0 &&(latch3==0))
  {
    latch3=1;
    
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
  //tiempoSP1
  if(startTimer2sec) 
  {
    contSP1++;
    if(contSP1==TPSP1)
    {
      contSP1=0;
      startTimer2sec=0;
      mEstado++;
      
    }
  }
  
  
}
