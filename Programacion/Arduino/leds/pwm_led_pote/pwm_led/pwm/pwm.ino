int led=3;
int brillo=0;

void setup() {
pinMode(led,OUTPUT);

}

void loop() {
  //analogWrite(led,0-255);//El segundo parametro le indicamos el rango e voltaje que va a utilizar(255=5 volts,su maximo)
                        //esta funciuon se encarga de dar el brillo del led y modular el ancho de pulso.
                        
  //-----Con este bucle incrementaremos el brillo del led uno en uno----------                      
  for(brillo=0;brillo<256;brillo++){
    analogWrite(led,brillo);//recordar que el segundo parametro toma un valor de 0 a 255(0volts a 5 volts)
    delay(15);  
  }
  for(brillo=255;brillo>=0;brillo--){
    analogWrite(led,brillo);//recordar que el segundo parametro toma un valor de 0 a 255(0volts a 5 volts)
    delay(15);  
  }
}
