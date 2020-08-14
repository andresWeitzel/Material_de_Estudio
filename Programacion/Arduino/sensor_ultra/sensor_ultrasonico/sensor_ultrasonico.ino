#include<NewPing.h>
#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 150//cm

const byte ALARMA=10;
const byte ALARMA2=9;

const float C = 261.63; // Do (Octava 0)
const float D = 293.66; // Re (Octava 0)
const float E = 329.63; // Mi (Octava 0)

int distancia=0;

//Constructor
NewPing mySensor(TRIGGER_PIN,ECHO_PIN,MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  pinMode (ALARMA,OUTPUT);
}

void loop() {
  delay(100);//Minimo 29 ms
  Serial.print("Distancia al objeto: ");
  Serial.print(mySensor.ping_cm());//Nos devuelve la distancia en cm
  Serial.println("cm");

  distancia=mySensor.ping_cm();//Obtenemos la distancia en cm

   tono(C, 250);  

   tono(D, 500);  

   tono(E, 350); 
}

void tono(int frecuencia, int duracion)

  {

    // Suena el tono en el zumbador

  tone(ALARMA, frecuencia, duracion);
  
  if(distancia<=10 && distancia >0){
    digitalWrite(ALARMA,HIGH);//encendemos el buzzer
    Serial.println("<<<PRECAUCION>>>");

    if(distancia<=5 && distancia>0){
      digitalWrite(ALARMA2,HIGH);//encendemos el buzzer
      digitalWrite(ALARMA,HIGH);
      Serial.println("<<<a punto de chocar>>>");
      
    }
    
  
  }
  else{
    digitalWrite(ALARMA,LOW);
    digitalWrite(ALARMA2,LOW);
    
}
  
 noTone(ALARMA);

   

    delay(50);
  }
