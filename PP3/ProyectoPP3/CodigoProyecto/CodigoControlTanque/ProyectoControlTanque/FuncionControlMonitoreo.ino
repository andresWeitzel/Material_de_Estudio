
//Logica de control es nuestra variable creada en archivo Principal

//Funcion para la logica de Control
void controlMonitoreo(){

 if( limiteAgua <= 300){
  //--Invocamos a la funcion del ledNormal para destello
   ledDestello(); 
  //--invocamos a la funcion que nos muestra los valores en la pantalla lcd
   outputLcd();

   
  }else if(limiteAgua >= 301 && limiteAgua <= 400){
    ledAdvertenciaLow();
    buzzerAdvertenciaLow();
    outputLcdAdvertenciaLow();
    outputLcd(); 
    
    
  }else if(limiteAgua >=401 && limiteAgua <= 469){ 
    ledAdvertenciaMedium();
    buzzerAdvertenciaMedium();
    outputLcdAdvertenciaMedium();
    outputLcd();
    
    
  }else if( limiteAgua >=470){
    ledAdvertenciaHigh();
    buzzerAdvertenciaHigh();
    outputLcdAdvertenciaHigh();
    outputLcd();
   
  } 

  /*
  El sensor de agua tiene una tiempo de recuperacion, por ende se le pasan rangos de medidas y no medidas exactas, dentro de esos rangos
  corresponden ciertas señales de advertencia, la medida mas alta de cada rango refiere al primer contacto con el agua, luego el sensado se
  estabiliza*/
 
}
  

  
  
  
  
