
  
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
