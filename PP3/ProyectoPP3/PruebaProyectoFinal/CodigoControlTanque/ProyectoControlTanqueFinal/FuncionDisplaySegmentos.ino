

void displaySegmentosTM1637(){
/*
  digitosDisplaySegmentos[0] =hora;
 // digitosDisplaySegmentos[1] = ;
  digitosDisplaySegmentos[2] = minuto; 
  //digitosDisplaySegmentos[3] = ;
  delay(1000); 
  displaySegmentos.display(digitosDisplaySegmentos); // la función para escribir en el display,  cada dígito diferenciado
  */

  displaySegmentos.point(POINT_OFF);//Puntos de separacion de hora minutos apagado
  displaySegmentos.display(0,hora/10);//Posicion 0, hora dividido 10
  displaySegmentos.display(1,hora%10);
  displaySegmentos.display(2,minuto/10);//Posicion 2, minutos dividido 10
  displaySegmentos.display(3,minuto%10);
  delay(500);

  displaySegmentos.point(POINT_ON);//Puntos  de separacion de hroa minutos prenido
  displaySegmentos.display(0,hora/10);//Posicion 0, hora dividido 10
  displaySegmentos.display(1,hora%10);
  displaySegmentos.display(2,minuto/10);//Posicion 2, minutos dividido 10
  displaySegmentos.display(3,minuto%10);
  delay(500);

    

  // un contador de 0 a 999 
 /*for (int i=0 ; i < 1000 ; i++){
  digitosDisplaySegmentos[0] =0;
  digitosDisplaySegmentos[1] = floor(i/100);
  digitosDisplaySegmentos[2] = floor((i%100)/10); 
  digitosDisplaySegmentos[3] = floor(i%10);
  delay(1000); 
  displaySegmentos.display(digitosDisplaySegmentos); // la función para escribir en el display,  cada dígito diferenciado
  }
*/
  
}
