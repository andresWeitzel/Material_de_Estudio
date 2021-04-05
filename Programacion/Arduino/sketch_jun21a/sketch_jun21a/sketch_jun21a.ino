int LED = 13; //LED
int pulsador1 = 2; // primer pulsador
int pulsador2 = 10; // segundo pulsador

void setup () { 
  pinMode (LED, OUTPUT); //configurado como salida
  pinMode (pulsador1,INPUT); //configurado de entrada
  pinMode (pulsador2, INPUT);
}

void loop () {
  if (digitalRead(pulsador1) == HIGH){ //si el pulsador1 está en alto
    digitalWrite(LED, HIGH); //encender el LED
  }
  else if (digitalRead(pulsador2) == HIGH){ //si el pulsador2 está en alto
    digitalWrite (LED, LOW); // apagar el LED
  }
}
