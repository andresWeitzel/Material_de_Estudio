

//--Variables para los delays--
  const int d1=1000;
  const int d2=200;
  const int d3=100;
  
//--Funcion Destello Normal--
void ledDestello(){
  
  
  for(int i=0; i < 1; i++){//Ejecuta 1 vez
    digitalWrite(pinLedNormal,HIGH);//Encendemos el ledNormal
    delay(d1);
    digitalWrite(pinLedNormal,LOW);//Apagamos el led
    delay(d1);
  }
}

//--Funcion destello advertencia--
void ledAdvertenciaLow(){
  
  for(int i=0; i < 1; i++){//Ejecuta 1 vez
    digitalWrite(pinLedAdvertencia,HIGH);//Encendemos el ledNormal
    delay(d2);
    digitalWrite(pinLedAdvertencia,LOW);//Apagamos el led
    delay(d2);
  }
}

void ledAdvertenciaMedium(){

  for(int i=0; i < 2; i++){//Ejecuta 2 vez
    digitalWrite(pinLedAdvertencia,HIGH);//Encendemos el ledNormal
    delay(d2);
    digitalWrite(pinLedAdvertencia,LOW);//Apagamos el led
    delay(d2);
  }
}

void ledAdvertenciaHigh(){

   for(int i=0; i < 3; i++){//Ejecuta 3 vez
    digitalWrite(pinLedAdvertencia,HIGH);//Encendemos el ledNormal
    delay(d3);
    digitalWrite(pinLedAdvertencia,LOW);//Apagamos el led
    delay(d3);
  }
}
