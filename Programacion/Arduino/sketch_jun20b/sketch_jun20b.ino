int pin = 2; // Número del pin digital
int value = 0;

void setup() {
Serial.begin(9600);
pinMode(pin, INPUT); // Definimos el pin como entrada
}

void loop(){
value = digitalRead(pin); // Leemos el pin digital

if (value == HIGH) { // Si el valor es alto:
Serial.println("ON");
} else { // Si el valor es bajo:
Serial.println("OFF");
}

delay(1000); // Esperamos
}
