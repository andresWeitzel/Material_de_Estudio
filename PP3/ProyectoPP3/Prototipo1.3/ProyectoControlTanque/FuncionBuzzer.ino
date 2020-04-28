//--Variables para la Frecuencia--
const int f1=540;
const int f2=560;
//--Variables para los delays--
const int d1=100;
const int d2=50;
const int d3=30;


//Funcion buzzer advertencia
void buzzerAdvertenciaLow(){ 
  tone(pinBuzzer,f1);//Prendemos buzzer
  delay(d1);
  noTone(pinBuzzer);//Apagamos buzzer
  delay(d1);
  tone(pinBuzzer,f1);
  delay(d1);
  noTone(pinBuzzer);
  delay(d1);
   tone(pinBuzzer,f1);
  delay(d1);
  noTone(pinBuzzer);
  delay(d1);
  
}

void buzzerAdvertenciaMedium(){ 
 tone(pinBuzzer,f1);//Prendemos buzzer
  delay(d2);
  noTone(pinBuzzer);//Apagamos buzzer
  delay(d2);
  tone(pinBuzzer,f1);
  delay(d2);
  noTone(pinBuzzer);
  delay(d2);
   tone(pinBuzzer,f1);
  delay(d2);
  noTone(pinBuzzer);
  delay(d2);
   tone(pinBuzzer,f1);
  delay(d2);
  noTone(pinBuzzer);
   tone(pinBuzzer,f1);
  delay(d2);
   noTone(pinBuzzer);  
}

void buzzerAdvertenciaHigh(){ 
 tone(pinBuzzer,f2);//Prendemos buzzer
  delay(d3);
  noTone(pinBuzzer);//Apagamos buzzer
  delay(d3);
  tone(pinBuzzer,f2);
  delay(d3);
  noTone(pinBuzzer);
  delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
  noTone(pinBuzzer);
  delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
  noTone(pinBuzzer);
  delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
   noTone(pinBuzzer);
   delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
  noTone(pinBuzzer);
  delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
   noTone(pinBuzzer);
   delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
  noTone(pinBuzzer);
  delay(d3);
   tone(pinBuzzer,f2);
  delay(d3);
   noTone(pinBuzzer);
   delay(d3);
    tone(pinBuzzer,f2);
  delay(d3);
   noTone(pinBuzzer);
   delay(d3);
    tone(pinBuzzer,f2);
  delay(d3);
   noTone(pinBuzzer);
  
 
  
}
