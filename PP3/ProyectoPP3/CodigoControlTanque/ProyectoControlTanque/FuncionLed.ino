//--Funcion Destello Normal--
void ledDestello(){
  digitalWrite(pinLedNormal,HIGH);//Encendemos el ledNormal
  delay(1000);
  digitalWrite(pinLedNormal,LOW);
  delay(1000);
}

//--Funcion destello advertencia--
void ledAdvertencia(){
  digitalWrite(pinLedAdvertencia,HIGH);//Encendemos el led de Advertencia
  delay(200);
  digitalWrite(pinLedAdvertencia,LOW);
  delay(200); 
 
}
