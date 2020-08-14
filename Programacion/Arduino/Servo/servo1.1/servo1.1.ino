#include "Servo.h"
Servo chino;

void setup() {
  
  chino.attach(3);

}

void loop() {
 chino.write(40);
 delay(2000);
/*chino.write(90);
 delay(2000);
chino.write(130);
 delay(3000);

chino.write(130);
 delay(2000);
chino.write(90);
 delay(2000);
chino.write(40);
 delay(2000);

*/}
