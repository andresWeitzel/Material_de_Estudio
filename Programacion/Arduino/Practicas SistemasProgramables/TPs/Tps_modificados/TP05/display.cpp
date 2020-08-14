

#include "sistem.h"
#include "display.h"
#include "arduino.h"

int getUnidad(int valor)
{
  int uni=0;
  uni=valor%10;
  
  return uni;

  //return(valor%10);
}
int getDecena(int valor)
{
  int dec=0;
  dec=(valor/10)%10;
  
  return dec;

  //return(valor%10);
}
int getCentena (int valor)
{
  int cen=0;
  cen=valor/100;
  
  return cen;

  //return(valor%10);
}


//num es el num a mostrar (0-9) y pos es el dsiplay que se enciende
void showDisplay(int num, int pos)
{
  switch (num)
  {
    case 0:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,1);
      digitalWrite(SEGE,1);
      digitalWrite(SEGF,1);
      digitalWrite(SEGG,0);
      break;
    }
    case 1:
    {
     digitalWrite(SEGA,0);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,0);
      digitalWrite(SEGE,0);
      digitalWrite(SEGF,0);
      digitalWrite(SEGG,0);
      break;
    }
     case 2:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,0);
      digitalWrite(SEGD,1);
      digitalWrite(SEGE,1);
      digitalWrite(SEGF,0);
      digitalWrite(SEGG,1);
      break;
    }
     case 3:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,1);
      digitalWrite(SEGE,0);
      digitalWrite(SEGF,0);
      digitalWrite(SEGG,1);
      break;
    }
     case 4:
    {
      digitalWrite(SEGA,0);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,0);
      digitalWrite(SEGE,0);
      digitalWrite(SEGF,1);
      digitalWrite(SEGG,1);
      break;
    }
     case 5:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,0);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,1);
      digitalWrite(SEGE,0);
      digitalWrite(SEGF,1);
      digitalWrite(SEGG,1);
      break;
    }
     case 6:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,0);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,1);
      digitalWrite(SEGE,1);
      digitalWrite(SEGF,1);
      digitalWrite(SEGG,1);
      break;
    }
     case 7:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,0);
      digitalWrite(SEGE,0);
      digitalWrite(SEGF,0);
      digitalWrite(SEGG,0);
      break;
    }
     case 8:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,1);
      digitalWrite(SEGE,1);
      digitalWrite(SEGF,1);
      digitalWrite(SEGG,1);
      break;
    }
     case 9:
    {
      digitalWrite(SEGA,1);
      digitalWrite(SEGB,1);
      digitalWrite(SEGC,1);
      digitalWrite(SEGD,0);
      digitalWrite(SEGE,0);
      digitalWrite(SEGF,1);
      digitalWrite(SEGG,1);
      break;
    }
  }
  switch (pos)
  {
    case 1:
    {
      digitalWrite(T1,1);
      digitalWrite(T2,0);
      digitalWrite(T3,0);
    break;
    }
    case 2:
    {
      digitalWrite(T1,0);
      digitalWrite(T2,1);
      digitalWrite(T3,0);
    break;
    }
    case 3:
    {
      digitalWrite(T1,0);
      digitalWrite(T2,0);
      digitalWrite(T3,1);
      break;
    }
  }
}
