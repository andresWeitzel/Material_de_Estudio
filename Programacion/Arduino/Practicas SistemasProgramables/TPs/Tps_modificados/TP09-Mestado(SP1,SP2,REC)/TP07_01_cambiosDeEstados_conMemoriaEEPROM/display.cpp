

#include "sistem.h"
#include "display.h"
#include "arduino.h"

int unidad = 0;
int decena = 0;
int centena = 0;
int numDisplay = 1; //indica que display se enciende 1 unid. 2dec 3 cen
extern bool tiempoMultDisp;

int getUnidad(int valor)
{
  int uni = 0;
  uni = valor % 10;

  return uni;

  //return(valor%10);
}
int getDecena(int valor)
{
  int dec = 0;
  dec = (valor / 10) % 10;

  return dec;

  //return(valor%10);
}
int getCentena (int valor)
{
  int cen = 0;
  cen = valor / 100;

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
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 1);
        break;
      }
    case 1:
      {
        digitalWrite(SEGA, 1);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 1);
        digitalWrite(SEGG, 1);
        break;
      }
    case 2:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 1);
        digitalWrite(SEGG, 0);
        break;
      }
    case 3:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 1);
        digitalWrite(SEGG, 0);
        break;
      }
    case 4:
      {
        digitalWrite(SEGA, 1);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 5:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 6:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 7:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 1);
        digitalWrite(SEGG, 1);
        break;
      }
    case 8:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 9:
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }

  }
  switch (pos)
  {
    case 1:
      {
        digitalWrite(T1, 1);
        digitalWrite(T2, 0);
        digitalWrite(T3, 0);
        break;
      }
    case 2:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 1);
        digitalWrite(T3, 0);
        break;
      }
    case 3:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 0);
        digitalWrite(T3, 1);
        break;
      }
  }
}




void Multiplex()
{
  if (tiempoMultDisp)
  {
    tiempoMultDisp = 0;
    switch (numDisplay)
    {
      case 1:
        {
          showDisplay(unidad, 1);
          break;
        }
      case 2:
        {
          showDisplay(decena, 2);
          break;
        }
      case 3:
        {
          showDisplay(centena, 3);
          break;
        }
    }
    numDisplay++;
    if (numDisplay == 4)
    {
      numDisplay = 1;
    }
  }
}

void uniDecCen(int numeroA)
{
  unidad = getUnidad(numeroA);
  decena = getDecena(numeroA);
  centena = getCentena(numeroA);
}





void parpadeoSP1 (int num, int pos)
{

  switch (num)
  {
    case 2: // letra "S"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 1: // letra "P"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 0:  // numero "1"
      {
        digitalWrite(SEGA, 1);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 1);
        digitalWrite(SEGG, 1);
        break;
      }


  }
  switch (pos)
  {
    case 1:
      {
        digitalWrite(T1, 1);
        digitalWrite(T2, 0);
        digitalWrite(T3, 0);
        break;
      }
    case 2:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 1);
        digitalWrite(T3, 0);
        break;
      }
    case 3:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 0);
        digitalWrite(T3, 1);
        break;
      }
  }


}
void MultiplexParpadeoSP1()
{
  if (tiempoMultDisp)
  {
    tiempoMultDisp = 0;
    switch (numDisplay)
    {
      case 1:
        {
          parpadeoSP1(0, 1);
          break;
        }
      case 2:
        {
          parpadeoSP1(1, 2);
          break;
        }
      case 3:
        {
          parpadeoSP1(2, 3);
          break;
        }
    }
    numDisplay++;
    if (numDisplay == 4)
    {
      numDisplay = 1;
    }
  }
}








void parpadeoSP2 (int num, int pos)
{

  switch (num)
  {
    case 2: // letra "S"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 0);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 1);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 1: // letra "P"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 0:  // numero "2"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 0);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 1);
        digitalWrite(SEGG, 0);
        break;
      }


  }
  switch (pos)
  {
    case 1:
      {
        digitalWrite(T1, 1);
        digitalWrite(T2, 0);
        digitalWrite(T3, 0);
        break;
      }
    case 2:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 1);
        digitalWrite(T3, 0);
        break;
      }
    case 3:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 0);
        digitalWrite(T3, 1);
        break;
      }
  }


}
void MultiplexParpadeoSP2()
{
  if (tiempoMultDisp)
  {
    tiempoMultDisp = 0;
    switch (numDisplay)
    {
      case 1:
        {
          parpadeoSP2(0, 1);
          break;
        }
      case 2:
        {
          parpadeoSP2(1, 2);
          break;
        }
      case 3:
        {
          parpadeoSP2(2, 3);
          break;
        }
    }
    numDisplay++;
    if (numDisplay == 4)
    {
      numDisplay = 1;
    }
  }
}




void parpadeoREC (int num, int pos)
{

  switch (num)
  {
    case 2: // letra "R"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 1);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 1);
        break;
      }
    case 1: // letra "E"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 0);
        break;
      }
    case 0:  // numero "C"
      {
        digitalWrite(SEGA, 0);
        digitalWrite(SEGB, 1);
        digitalWrite(SEGC, 1);
        digitalWrite(SEGD, 0);
        digitalWrite(SEGE, 0);
        digitalWrite(SEGF, 0);
        digitalWrite(SEGG, 1);
        break;
      }


  }
  switch (pos)
  {
    case 1:
      {
        digitalWrite(T1, 1);
        digitalWrite(T2, 0);
        digitalWrite(T3, 0);
        break;
      }
    case 2:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 1);
        digitalWrite(T3, 0);
        break;
      }
    case 3:
      {
        digitalWrite(T1, 0);
        digitalWrite(T2, 0);
        digitalWrite(T3, 1);
        break;
      }
  }


}
void MultiplexParpadeoREC()
{
  if (tiempoMultDisp)
  {
    tiempoMultDisp = 0;
    switch (numDisplay)
    {
      case 1:
        {
          parpadeoREC(0, 1);
          break;
        }
      case 2:
        {
          parpadeoREC(1, 2);
          break;
        }
      case 3:
        {
          parpadeoREC(2, 3);
          break;
        }
    }
    numDisplay++;
    if (numDisplay == 4)
    {
      numDisplay = 1;
    }
  }
}
