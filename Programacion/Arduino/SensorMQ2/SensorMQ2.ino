#include <Arduino.h>
#include <TM1637Display.h>

#define BUZZER 2
#define CLK 3
#define DIO 4

//Inicializa o display
TM1637Display display(CLK, DIO);

int lectura_MQ2;


void setup() {
  
Serial.begin(9600);


}

void loop() {
  //Define o brilho do display
  display.setBrightness(0x0f);
  
lectura_MQ2=analogRead(A0);

 //Mostra o valor no display
  display.showNumberDec(lectura_MQ2, false);
  
Serial.println(lectura_MQ2);
delay(500);

if(lectura_MQ2 > 400){
  alarmaON();
 }else{
  alarmaOFF();
 }


}

//funcion para zumbador
void alarmaON(){
  tone(BUZZER, 200);
   delay(500);
   tone(BUZZER, 100);
    delay(500);
   tone(BUZZER, 200);
   delay(500);
   tone(BUZZER, 100);
    
   
}
void alarmaOFF(){
  noTone(BUZZER); 
   delay(500);
}
