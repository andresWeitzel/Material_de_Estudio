#include <Keypad.h>

const int ledRed=12;
const int ledGreen=13;

const byte ROWS=4;//Cuatro filas
const byte COLS=4;//Cuatro Columnas

bool ACCESS_GRANTED=false;//Para el estado

int ledRedState=false;
int ledGreenState=false;

//MAPA DE TECLAS
char keys[ROWS][COLS]={
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'},

}

//DECLARACION DE LOS PINES DE LAS FILAS Y DE LAS COLUMNAS
byte rowPins[ROWS]={11,10,9,8};
byte colPins[COLS]={7,6,5,4};


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
