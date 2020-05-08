
//Logica de control es nuestra variable creada en archivo Principal

//Funcion para la logica de Control
void logicaDeControl(){

  //--Invocamos a la funcion del ledNormal para destello
  if(temp <= 26 && limiteAgua <= 380){
   ledDestello();
  }else if((temp >= 27 && temp <= 28) || (limiteAgua >= 381 && limiteAgua <= 590 )){
    ledAdvertenciaLow();
    buzzerAdvertenciaLow();
  }else if((temp >= 29 && temp <= 30) || (limiteAgua >= 491 && limiteAgua <= 540 )){
    ledAdvertenciaMedium();
    buzzerAdvertenciaMedium();
  }else if(temp >= 31 || limiteAgua >= 541){
    ledAdvertenciaHigh();
    buzzerAdvertenciaHigh();
  } 

  /*
  El sensor de agua tiene una tiempo de recuperacion, por ende se le pasan rangos de medidas y no medidas exactas, dentro de esos rangos
  corresponden ciertas señales de advertencia, la medida mas alta de cada rango refiere al primer contacto con el agua, luego el sensado se
  estabiliza*/
 
}
  
  
  
  
  
  
  
  


  
  
  
  
  /*
  //Variables para la logica de Control--
int estadoActual=0;

switch(estadoActual){
 
  case 1:   
   //--Invocamos a la funcion del ledNormal para destello
   if(temp <= 26 && limiteAgua <= 500){
    ledDestello();
    estadoActual++;
    
  }break;

  case 2:
  //--Invocamos a la funcion del ledAdvertencia junto con la funcion buzzerAdvertencia
    if((temp >= 27 && temp <= 28) || limiteAgua >= 390){
      ledAdvertenciaLow();
      buzzerAdvertenciaLow();
      estadoActual++;
  }break;

  case 3:
    if((temp >= 29 && temp <= 30) || limiteAgua >= 450){
      ledAdvertenciaMedium();
      buzzerAdvertenciaMedium();
      estadoActual++;
  }break;

  case 4:
   if(temp >= 31 || limiteAgua >= 550){
    ledAdvertenciaHigh();
    buzzerAdvertenciaHigh();
    estadoActual++;
  }break;
  
  
}*/





/*int day = 4;
switch (day) {
  case 1:
    cout << "Monday";
    break;
  case 2:
    cout << "Tuesday";
    break;
  case 3:
    cout << "Wednesday";
    break;
  case 4:
    cout << "Thursday";
    break;
  case 5:
    cout << "Friday";
    break;
  case 6:
    cout << "Saturday";
    break;
  case 7:
    cout << "Sunday";
    break;
}*/
