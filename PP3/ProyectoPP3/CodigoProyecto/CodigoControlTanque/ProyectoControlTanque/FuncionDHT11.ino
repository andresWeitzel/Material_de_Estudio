
void sensorDHT11(){
  //--Leemos la temperatura y humedad del dht11--
  temp=dht.readTemperature();
  hum=dht.readHumidity();

}
