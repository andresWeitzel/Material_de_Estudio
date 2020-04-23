
//Funcion buzzer advertencia
void buzzerAdvertencia(){ 
  tone(pinBuzzer,440);//Prendemos buzzer
  delay(100);
  noTone(pinBuzzer);//Apagamos buzzer
  delay(100);
  tone(pinBuzzer,440);
  delay(100);
  noTone(pinBuzzer);
  delay(100);
   tone(pinBuzzer,440);
  delay(100);
  noTone(pinBuzzer);
  delay(100);
  
}
