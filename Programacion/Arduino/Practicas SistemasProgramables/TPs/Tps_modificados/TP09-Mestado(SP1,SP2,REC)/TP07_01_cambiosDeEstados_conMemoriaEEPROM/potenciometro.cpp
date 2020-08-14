#include "potenciometro.h"
#include "arduino.h"
#include "sistem.h"

int medicionPote = 0;

int potenciometro() {
  medicionPote = analogRead(POTE);
  int salidaPote = medicionPote * 10 / 102;
  return salidaPote;
}
