#include "Servo.h"
Servo chino;


void setup() {
  chino.attach(4);

}

void loop() {
 
  for(int i=50;i<120;i++){
    
    chino.write(i);
    delay(10);
  }
  for(int i=120;i>50;i--){
    
    chino.write(i);
    delay(10);  
   
  }
}
