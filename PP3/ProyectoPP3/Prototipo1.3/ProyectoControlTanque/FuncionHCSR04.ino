//FUNCION LECTURA SENSOR ULTRASONICO
void funcionHCSR04(){
  
// ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);

  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  
  //distancia = tiempo / 58;

  capacidad=tiempo / 58;
  
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(capacidad);
  Serial.println(" %");
  //delay(200);

  }
/*
 *MODELO MATEMATICO PARA EL TIEMPO QUE TARDA EL SENSOR EN DETECTAR UN OBJETO 
 *
  Tiempo= 2 * (Dist:Velocidad)
  Distancia= (Velocidad*Tiempo) : 2

*/
