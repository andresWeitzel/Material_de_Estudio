int calc;
float varlm35=0;


void setup() {
  
  Serial.begin(9600);
  
  
}

void loop() {
  calc=analogRead(A0);
  varlm35=calc*((5/1024)/0,01);

  
  Serial.print(varlm35);
  Serial.print("\n");
  delay(2);
  
  


}
