

//--Variables para la Frecuencia--
  const int f1=540;
  const int f2=560;
  //--Variables para los delays--
  const int d4=100;
  const int d5=50;
  const int d6=30;

  
//Funcion buzzer advertencia
void buzzerAdvertenciaLow(){ 

  for(int i=0; i < 4; i++){//Repite 3 veces
    tone(pinBuzzer,f1);//Prendemos buzzer
    delay(d4);
    noTone(pinBuzzer);//Apagamos buzzer
    delay(d4);
  }
 
}

void buzzerAdvertenciaMedium(){ 

   for(int i=0; i < 5; i++){//Repite 5 veces
    tone(pinBuzzer,f1);//Prendemos buzzer
    delay(d5);
    noTone(pinBuzzer);//Apagamos buzzer
    delay(d5);
  }

}

void buzzerAdvertenciaHigh(){ 

  for(int i=0; i < 11; i++){//Repite 11 veces
    tone(pinBuzzer,f2);//Prendemos buzzer
  delay(d6);
  noTone(pinBuzzer);//Apagamos buzzer
  delay(d6);
  }

  
}
