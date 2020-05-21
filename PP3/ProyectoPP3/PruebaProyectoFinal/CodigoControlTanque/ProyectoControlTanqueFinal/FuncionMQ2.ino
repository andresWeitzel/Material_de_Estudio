

void detectorHumoMQ2(){
  
  deteccionHumo = analogRead(A5); 
  
/*  
  if(deteccionHumo > 500)
  {
    Serial.print("Se ha detectado humo!");Serial.println(deteccionHumo);
  }else{
    Serial.print("Valores del sensor MQ2:");Serial.println(deteccionHumo);
  
  }*/

  /*
  El sensor de gas MQ2 funciona con 5 VCC y consume alrededor de 800 mW. Puede detectar concentraciones 
  de GLP, humo, alcohol, propano, hidrógeno, metano y monóxido de carbono en cualquier lugar de 200 a 10000ppm.

  --CO Los niveles y los efectos --
Concentración  y Síntoma 

35 ppm (0.0035%) Dolor de cabeza y mareos en el plazo de seis a ocho horas de exposición constant. 
100 ppm (0.01%) Cefalea leve en dos o tres horas. 
200 ppm (0.02%) Cefalea leve en el plazo de dos a tres horas; pérdida de razonamiento. 
400 ppm (0.04%) Cefalea Frontal dentro del plazo de una a dos horas. 
800 ppm (0.08%) Mareos, náuseas y convulsiones dentro de los 45 min; insensible durante 2 horas. 
1,600 ppm (0.16%) Cefalea, taquicardia, mareos y náuseas dentro de los 20 minutos; la muerte en menos de 2 horas. 
3,200 ppm (0.32%) Cefaleas, mareos y náuseas en cinco o diez minutos. Muerte dentro de los 30 minutos. 
6,400 ppm (0.64%) Dolor de cabeza y mareos en uno o dos minutos. Convulsiones, paro respiratorio y muerte en menos de 20 minutos. 
12,800 ppm (1.28%) La Inconsciencia después de 2 ó 3 respiraciones. Muerte en menos de tres minutos. 

  */
  
  
}
