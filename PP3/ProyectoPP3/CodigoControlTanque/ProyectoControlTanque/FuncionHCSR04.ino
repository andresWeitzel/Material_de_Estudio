//FUNCION LECTURA SENSOR ULTRASONICO
void sensorHCSR04(){
  
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
  
  //distancia = tiempo / 58;//original

  altura=tiempo / 58;//modificado
 
  // ENVIAR EL RESULTADO AL MONITOR SERIAL
  Serial.print(altura);
  Serial.println(" cm");
  //delay(200);

  }
/*
 *MODELO MATEMATICO PARA EL TIEMPO QUE TARDA EL SENSOR EN DETECTAR UN OBJETO 
 *
  Tiempo= 2 * (Dist:Velocidad)
  Distancia= (Velocidad*Tiempo) : 2

*/





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
