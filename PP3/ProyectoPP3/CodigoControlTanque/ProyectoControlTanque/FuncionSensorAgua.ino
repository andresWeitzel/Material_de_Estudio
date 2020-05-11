void sensorAgua(){
  //--Leemos los valores del sensor de agua--
  limiteAgua=analogRead(A2);
  //Serial.println(limiteAgua);
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print("Medicion sensor de agua:");
  Serial.println(limiteAgua);
  
  //delay(200);
  
 
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
