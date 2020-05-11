
//Logica de control es nuestra variable creada en archivo Principal

//Funcion para la logica de Control
void controlMonitoreo(){

 if(temp <= 26 && limiteAgua <= 300){
  //--Invocamos a la funcion del ledNormal para destello
   ledDestello(); 
  //--invocamos a la funcion que nos muestra los valores en la pantalla lcd
   outputLcd();

   
  }else if((temp >= 27 && temp <= 28) || (limiteAgua >= 301 && limiteAgua <= 400 )){
    ledAdvertenciaLow();
    buzzerAdvertenciaLow();
    outputLcdAdvertenciaLow();
    outputLcd(); 
    
    
  }else if((temp >= 29 && temp <= 30) || (limiteAgua >=401 && limiteAgua <= 469 )){ 
    ledAdvertenciaMedium();
    buzzerAdvertenciaMedium();
    outputLcdAdvertenciaMedium();
    outputLcd();
    
    
  }else if(temp >= 31 || limiteAgua >=470){
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
  
  
  
  
  
  
