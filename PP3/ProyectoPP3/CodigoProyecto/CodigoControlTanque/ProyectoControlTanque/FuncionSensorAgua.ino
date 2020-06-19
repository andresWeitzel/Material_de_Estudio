void sensorAgua(){
  //--Leemos los valores del sensor de agua--
  limiteAgua=analogRead(A2);
  //Serial.println(limiteAgua);
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print("Medicion sensor de agua:");
  Serial.println(limiteAgua);
  
  //delay(200);
  
 
}
