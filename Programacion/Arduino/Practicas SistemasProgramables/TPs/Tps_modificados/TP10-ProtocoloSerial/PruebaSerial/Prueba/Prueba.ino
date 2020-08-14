void setup() {
  Serial.begin(9600);

}

void loop() {
char receive=Serial.read();
   if(Serial.available()){//si hay algo en el puerto serie luego leemos con la otra funcion serial.read
    
      Serial.println(receive);//imprimimos lo que guardamos en la variable receive
   }
}
