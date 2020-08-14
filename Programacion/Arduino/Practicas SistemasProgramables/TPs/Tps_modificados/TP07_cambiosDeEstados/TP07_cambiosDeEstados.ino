#include "sistem.h"
#include "display.h"
#include "pulsadores.h"
#include "potenciometro.h"

int cont1 = 0;                        //Vector interrupcion Timer2
int cont2 = 0;                        //Vector interrupcion Timer2
bool flag = 0;                        //Vector interrupcion Timer2
bool tiempoMultDisp = 10;              //Vector interrupcion Timer2
int cont3 = 0;                        //Vector interrupcion Timer2
bool flag3 = 0;                         //Vector interrupcion Timer2


int menu = 0;   // opciones del case
int numeroFinal = 0;  // numero para la funcion de numero en los led de 7 segmentos
int flagMenu = 0;  // oscila entre menu 0 y menu 2 del case
int salidaMenu1 = 0; // activo la salida del menu
int bandera2 = 0; //para parpadeo
int numeroSP1 = 0;   // numero inicial para el menu2(contador con pulsadores)
int numeroFinalAnterior = 0;   // esta variable se usa para el antirrebote de apretar ambos pulsadores en el menu 2

int estadoP1 = 0;  //funcion para detectar si apretamos los dos botones a la vez
int estadoP2 = 0;   //funcion para detectar si apretamos los dos botones a la vez



void setup() {
  initPorts();
  initTimer2();

}

void loop() {
  animacionLedTestigo();

  if (menu == 1)
  {
  }
  else {
    uniDecCen(numeroFinal);
    Multiplex();
  }

  estadoP1 = digitalRead(P1);         //reviso estado de pulsadores
  estadoP2 = digitalRead(P2);
  if (estadoP1 && estadoP2)            // pregunto si los pulsadores estan apretados
  {
    menu = 1;                           // si estan apretados voy al menu 1 donde se encuentra la interfaz de cambio de estado
  }                                     //parpadeo de led's de 7 segmentos.


  switch (menu)                       // este suitch tiene los 3 menus( 0 potenciomentro, 1 parpadeo, 2 pulsadores que suben y bajan los numeros de los led's de 7 segmentos
  {
    case 0: {
        numeroFinal = potenciometro();      // potenciomentro de 0 a 100
        break;
      }
    case 1: {                               // parpadeo de los led de 7 seg


        if (flag3)                          // este if se encargade intercambiar el codigo sp1 y el apagado de los led's 7 seg
        { // funciona con un flag3 que encuentra en el vector de interrupcion
          flag3 = 0;
          salidaMenu1 ++ ;                  // salida del menu se encarga de salir del case 1, aca aumenta
          bandera2 = 1 - bandera2;          // cambia la bandera2 de estado
        }

        if (bandera2 == 1) {                    // si la bandera2 esta en 1 muestra sp1
          MultiplexParpadeoSP1();
        }
        else {                                  // si la bandera no esta en 1, osea se encuentra en 0, se apagan los led's de 7 seg
          digitalWrite(SEGA, 0);
          digitalWrite(SEGB, 0);
          digitalWrite(SEGC, 0);
          digitalWrite(SEGD, 0);
          digitalWrite(SEGE, 0);
          digitalWrite(SEGF, 0);
          digitalWrite(SEGG, 0);
        }

        if (salidaMenu1 == 7) {        // si salidaMenu1 llega a 7  deja de parpadear y selecciona el potenciomentro (menu0) o contador con pulsadores (menu1)
          numeroFinal = numeroSP1;     //  selecciona el numero inicial para el menu 2 con respecto al ultimo numero usado en el menu 2
          flagMenu = 1 - flagMenu;   //memoria de estado para recordar si estaba en el case 0 o case 2
          salidaMenu1 = 0;            // pongo el contador salidaMenu1 en 0 para volver a usarlo luego
          if (flagMenu) {                 // en estos if selecciono a q case voy a ir con respecto al case q estube anteriormente.
            menu = 2;
          }
          if (flagMenu == 0) {
            menu = 0;
          }
        }
        break;

      }
    case 2: {                                       // en el case dos se encuentra la funcion de aumentar o disminuir el numero q se muestra en la pantalla led con los pulsadores

        numeroFinal = deteccionDePusosP1yP2 (numeroFinal);       // funcion de los pulsadores aumenta y disminuyen el numero

        if (numeroFinalAnterior == numeroFinal && estadoP1 == 0 && estadoP2 == 0 )               // los siguientes if  se encargar del antirrebote de los numeros ya q es poco probable que apretemos ambos botones al mismo tiempo
        {
          numeroFinalAnterior = numeroFinal;
          numeroSP1 = numeroFinal ;
        }
        if (numeroFinalAnterior < numeroFinal) {
          numeroSP1 =  numeroFinal - 1;
          numeroFinalAnterior = numeroFinal;
        }
        if  (numeroFinalAnterior > numeroFinal)
        {
          numeroSP1 =  numeroFinal + 1;
          numeroFinalAnterior = numeroFinal;
        }

        break;
      }
  }
}

//*********************************************************
//Vector interrupcion Timer2
//********************************************************
ISR(TIMER2_OVF_vect)
{
  TCNT2 = 5;                              // contador para parpadeo de led
  cont1++;
  cont2++;
  cont3++;
  if (cont1 == TOSC)
  {
    cont1 = 0;
    flag = 1;
  }
  if (cont2 == TDISP)                     // contador para tiempo de intercalado de transistores
  {
    cont2 = 0;
    tiempoMultDisp = 1;
  }
  if (cont3 == TPARP)   // contardor para parpadeo de pantallas de 7seg
  {
    cont3 = 0;
    flag3 = 1;
  }
}
