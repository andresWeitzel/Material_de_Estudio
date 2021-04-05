
/*Uso de botones
Al presionar el botón se enciende o se apaga dependiendo
del estado en que se encuentre*/

int estado = 0; //se declara una variable
int estadoAnterior = 0; //Guarda el estado anterior del boton
int salida = 0; //0= LED apagado, 1= LED encendido

void setup() {
  pinMode(8, INPUT); //declaramos el boton como entrada
  pinMode(4, OUTPUT); //declaramos el LED como salida
}

void loop(){
  estado = digitalRead(8);   //Leer el estado del botón

  if((estado==HIGH)&&(estadoAnterior==LOW)) {//Si estado esta en alto
    salida = 1-salida;  //encendemos el LED
    delay(220);
  }
  estadoAnterior=estado; //Guarda el valor actual

  if(salida==1) {   //Si estado esta en alto
    digitalWrite(4, HIGH);  //encendemos el LED
  } 
  else {
    digitalWrite(4, LOW); //Apagamos el LED
  }
}

