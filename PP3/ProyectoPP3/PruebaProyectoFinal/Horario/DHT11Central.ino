void dht11Central(){
  //--Lectura de Temperatura y humedad
  float temp=dht.readTemperature();
  float hum=dht.readHumidity();

  //--Imprimimos en el serial--
  Serial.print("Temperatura: ");Serial.print(temp); Serial.println("°C");
  Serial.print("Humedad: ");Serial.print(hum); Serial.println("%");
  delay(1000);
}
