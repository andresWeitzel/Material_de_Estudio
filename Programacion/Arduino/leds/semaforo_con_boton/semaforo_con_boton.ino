
int boton1=2;
int ledrojo=3;
int ledamarillo=4;
int ledverde=5;


int estado_semaforo;//declaro para los diferentes estados del semaforo

void setup() {
  
  pinMode(boton1,INPUT);
  pinMode(ledrojo,OUTPUT);
  pinMode(ledamarillo,OUTPUT);
  pinMode(ledverde,OUTPUT);
  
  int estado_semaforo=1;//Primer estado del sem

 
  
}

void loop() {
  

  
  estadoboton1=digitalRead(boton1);//Lee el estado del boton1(Normal abierto o cerrado)

  if(estadoboton1==HIGH){//si el boton esta apretado y el estado del semaforo es menor a 4, el estado del semaforo se incrementa uno, por ende cambia de color, de verde a amarillo y luego a rojo
    
    if(estado_semaforo<3){
      
      estado_semaforo =estado_semaforo + 1;
    }
      else{
        estado_semaforo=1;
      }
      
  }

  if(estado_semaforo==1){
    digitalWrite(ledverde,HIGH);
    digitalWrite(ledamarillo,LOW);
    digitalWrite(ledrojo,LOW);
  }


  if(estado_semaforo==2){
    digitalWrite(ledverde,LOW);
    digitalWrite(ledamarillo,HIGH);
    digitalWrite(ledrojo,LOW);
  }


  if(estado_semaforo==3){
    digitalWrite(ledverde,LOW);
    digitalWrite(ledamarillo,LOW);
    digitalWrite(ledrojo,HIGH);
  } 
  

  }
