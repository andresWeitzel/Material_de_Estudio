
  

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



/*
//-----------------Variables-------------------------
//--Calculo de volumen--
float volumenMin=0.00;
float volumenMax=1.50;
float alturaMax=9.80;
float alturaMin=18.79;
float volumen=0.00;
float tiempo,altura;//variables para el HC-SR04 


*/
