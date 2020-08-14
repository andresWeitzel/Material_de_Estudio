#include "pulsadores.h"
#include "arduino.h"
#include "sistem.h"

// variables de funcion deteccionDePulso()
int estadoB = 0; //guarda el estado del boton
int salida = 0; // 0 boton sin presionar ,1 = boton presionado
int estadoanterior = 0; // guardar el estado anterior del boton

int estadoB2 = 0; //guarda el estado del boton
int salida2 = 0; // 0 boton sin presionar ,1 = boton presionado
int estadoanterior2 = 0; // guardar el estado anterior del boton

// variables de funcion antirrebote()


const int tiempoAntirebote = 15;



// deteccion de pulso Pulsador 1

bool deteccionDePulsoP1() {

  estadoB = digitalRead(P1); // leer el estado del boton
  if (( estadoB != estadoanterior) && (antirreboteP1()) ) {
    salida = 1 ;

  }
  else
  {
    salida = 0;
  }

  estadoanterior = estadoB ;    // guardar el valor actual
  return salida;
}

//----------------------------------------------------------------------
// deteccion de pulso Pulsador 2

bool deteccionDePulsoP2() {

  estadoB2 = digitalRead(P2); // leer el estado del boton
  if (( estadoB2 != estadoanterior2) && (antirreboteP2()) ) {
    salida2 = 1 ;

  }
  else
  {
    salida2 = 0;
  }

  estadoanterior2 = estadoB2 ;    // guardar el valor actual
  return salida2;
}

//----------------------------------------------------------------------
//ANTIRREBOTE

bool antirreboteP1() {
  int contador = 0;
  boolean estadoA;                  //guarda el estado del boton
  boolean estadoAnterior;          //guarda el ultimo estado del boton

  do {
    estadoA = digitalRead(P1);
    if (estadoA != estadoAnterior) //comparamos el estado actual con el anterior
    { contador = 0;                //reiniciamos el contador
      estadoAnterior = estadoA;

    }
    else {
      contador = contador + 1;     //aumentamos el contador en 1
    }
    delay(1);
  } while (contador < tiempoAntirebote);
  return estadoA;
}


bool antirreboteP2() {
  int contador2 = 0;
  boolean estadoA2;                  //guarda el estado del boton
  boolean estadoAnterior2;          //guarda el ultimo estado del boton

  do {
    estadoA2 = digitalRead(P2);
    if (estadoA2 != estadoAnterior2) //comparamos el estado actual con el anterior
    { contador2 = 0;                //reiniciamos el contador
      estadoAnterior2 = estadoA2;

    }
    else {
      contador2 = contador2 + 1;     //aumentamos el contador en 1
    }
    delay(1);
  } while (contador2 < tiempoAntirebote);
  return estadoA2;
}
//------------------------------------------------------------------------
int deteccionDePulsosP1yP2 (int numeroP) {
  if (deteccionDePulsoP1() )
  {
    numeroP++;
  }

  if (  deteccionDePulsoP2() )
  {
    numeroP--;
  }
  return (numeroP);
}
