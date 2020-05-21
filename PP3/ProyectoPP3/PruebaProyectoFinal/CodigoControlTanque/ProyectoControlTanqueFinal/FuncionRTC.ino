
void horarioRTC(){
  
   // Ponemos en hora, solo la primera vez, luego comentar y volver a cargar.
 // Ponemos en hora con los valores de la fecha y la hora en que el sketch ha sido compilado.
 // January 21, 2014 at 3am you would call:
// rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
 //rtc.adjust(DateTime(2020,05,15,21,07,0));
  
 DateTime now = rtc.now();

 dia=now.day();
 mes=now.month();
 anio=now.year();
 hora=now.hour();
 minuto=now.minute();
 segundo=now.second();
 
 Serial.print(dia);
 Serial.print('/');
 Serial.print(mes);
 Serial.print('/');
 Serial.print(anio);
 Serial.print(" ");
 Serial.print(hora);
 Serial.print(':');
 Serial.print(minuto);
 Serial.print(':');
 Serial.print(segundo);
 Serial.println();
 delay(3000);
}
