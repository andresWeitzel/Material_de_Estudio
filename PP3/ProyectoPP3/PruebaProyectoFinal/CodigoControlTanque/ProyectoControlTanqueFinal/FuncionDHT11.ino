
void sensorDHT11Tanque(){
  //--Leemos la temperatura y humedad del dht11--
  tempTanque=dhtTanque.readTemperature();
  humTanque=dhtTanque.readHumidity();

}

void sensorDHT11SalaControl(){
  tempSalaControl=dhtSalaControl.readTemperature();
  humSalaControl=dhtSalaControl.readHumidity();
}


/*
///-----------------Variables-------------------------
//--Calculo de volumen--
float volumenMin=0.00;
float volumenMax=1.50;
float alturaMax=9.80;
float alturaMin=18.79;
float volumen=0.00;
float tiempo,altura;//variables para el HC-SR04 

*/
