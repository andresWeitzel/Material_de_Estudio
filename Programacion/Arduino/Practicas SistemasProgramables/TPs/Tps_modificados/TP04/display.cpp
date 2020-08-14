

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
void ShowDisplay(int num, int pos)
{
  switch (num)
  {
    case 0:
    {
      SEGA=1;
      SEGB=1;
      SEGC=1;
      SEGD=1;
      SEGE=1;
      SEGF=1;
      SEGG=0;
      break;
    }
    case 1:
    {
      SEGA=0;
      SEGB=1;
      SEGC=1;
      SEGD=0;
      SEGE=0;
      SEGF=0;
      SEGG=0;
      break;
    }
  }
  switch (pos)
  {
    case 1:
    {
      T1=1;
      T2=0;
      T3=0;
    }
    case 2:
    {
      T1=1;
      T2=0;
      T3=0;
    }
  }
}


