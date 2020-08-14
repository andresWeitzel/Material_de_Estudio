#include "Servo.h"
Servo chino1;
Servo chino2;


const int rele = 8;

void setup() {
  chino1.attach(4);
  chino2.attach(7);
  pinMode(rele,OUTPUT);

}

void loop() {
  digitalWrite(rele, HIGH);
 
  for(int i=50;i<120;i++){
    
    chino1.write(i);
    delay(10);
  }
  digitalWrite(rele,LOW);
  
  
  
  for(int i=120;i>50;i--){

    chino1.write(i);
    delay(10);  
  }



    
digitalWrite(rele, HIGH);
 
  for(int O=50;O<120;O++){
    
    chino2.write(O);
    delay(10);
  }
  digitalWrite(rele,LOW);
  for(int O=120;O>50;O--){
    
    chino2.write(O);
    delay(10);  
   
  }
  
   }
