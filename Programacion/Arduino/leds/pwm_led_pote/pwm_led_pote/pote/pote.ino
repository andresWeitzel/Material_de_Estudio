int led=3;
int brillo;
int pot=0;

void setup() {
pinMode(led,OUTPUT);
//pinMode(pot,INPUT);//LAS ENTRADAS ANALOGICAS NO REQUIEREN INICIALIZACION

}

void loop() {

  brillo=analogRead(pot)/4;//analogRead solo requiere el parametro su num del pin, se divide por cuatro,explicado mas abajo
  analogWrite(led,brillo);/*con analogWrite escribiremos el valor medido del led
  ---OJO EL RANGO DEL VALOR MEDIDO DE UNA ENTRADA ANALOGICA ES DE 0 A 1023(MAYOR RESOLUCION DE VALORES)
  ,ESTAS ENTRADAS SOLO SE UTILIZAN COMO ENTRADAS NO SCOMO EL RESTO DE LAS ENTRADAS/SALIDAS DE ARDUINO*/
  //analogWrite-->0-255   analogRead-->0-1024(1024%4=255(EL MAXIMO VALOR DE analogWrite(5 volts)))
  
                       
}
