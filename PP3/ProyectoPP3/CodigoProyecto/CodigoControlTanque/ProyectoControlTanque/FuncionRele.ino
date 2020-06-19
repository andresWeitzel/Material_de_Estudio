
void releBombaAgua(){

//--Inicio--

if(inicioSistema==0){//Cada vez que reiniciamos el sistema entra a la fase inicio(experimental)
  
  if(volumen <= 1.50){//seria la altura maxima del sensor de agua,fijarse
   digitalWrite(pinRele,HIGH);
   if(volumen == 1.50){//Nos aseguramos haber pasado por todas las etapas de la señal preventiva
     inicioSistema ++;//aumentamos la variable
     digitalWrite(pinRele,LOW);//Apagamos el rele
    }
  }else{
   digitalWrite(pinRele,LOW);  
  }
}



//--Estabilizacion del sistema--

if(inicioSistema==1){//Nos aseguramos que se halla mostrado el inicio del sistema antes de llegar a la estabilizacion del mismo
 
  if(volumen < 0.60 || volumen < 0.75){//En esa franja estara prendido
     digitalWrite(pinRele,HIGH);
     
  }else if(volumen >= 0.75 && volumen <= 1.50){//En esa franja siempre estara apagado
     
     digitalWrite(pinRele,LOW);  
   
  }else{
     digitalWrite(pinRele,LOW);//En caso de algun problema, apagamos la bomba
  }
 }  
}
