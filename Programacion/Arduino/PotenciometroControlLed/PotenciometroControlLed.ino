/*Programa para manejar la intensidad de varios 3 leds con 1 potenciometro sin PWM*/

//Definimos un array para los leds y una constante para el pote
int leds[]={2,3,4};
#define pot A0

int valor;
  
void setup() {
  // put your setup code here, to run once:
  
//Usamos un for para la declaracion de los pines de los leds por ser un array
for(int i=0; i<3; i++){
 pinMode(leds[i],OUTPUT); 
}

pinMode(pot,INPUT);
}

//Creamos una funcion encender, indicara cual led se va a encender
void encender(int x){
  int i;
  for(i=0; i<x; i++ ){
    digitalWrite(leds[i],HIGH);
    
  }
  for(i=x; i<4; i++){
    digitalWrite(leds[i],LOW);
  }
  
}

void loop() {
  
  // put your main code here, to run repeatedly:
 /*//Analogico=0 a 1023 y PWM=0 a 255

 //Funcion de escritura de la lectura del valor del led y del potenciometro
 analogWrite(led, analogRead(pot)/4);

 //Funcion map(lectura, minimo_valor_entrada, maximo_valor_entrada, minimo_valor_salida, maximo_valor_salida);
//Funcion de escritura de la lectura del valor del led y del potenciometro con map()
 analogWrite(led, map(analogRead(pot), 0, 1023, 0, 255));
*/

 //La variable valor recibe la lectura del potenciometro
 valor=analogRead(pot);

 //En esta funcion map en  los parametros de salida se utilizaran los leds junto con la funcion creada 
 encender(map(valor, 0, 1023, 0, 4));
 
}
