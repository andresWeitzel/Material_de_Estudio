#include <LiquidCrystal.h>

LiquidCrystal lcd(2,3,4,6,7,8,9,10,11,12,13);





void setup() {
  lcd.begin(16,2);//iniciala comunicacion con el display

  lcd.print("SE S A B E E..");
  lcd.setCursor(0,1);//para usar en otra linea
  //lcd.clear();Nos limpia lo digitado en la linea anterior
  lcd.print("#Scoobydopapa");
}

void loop() {
  // put your main code here, to run repeatedly:

}
