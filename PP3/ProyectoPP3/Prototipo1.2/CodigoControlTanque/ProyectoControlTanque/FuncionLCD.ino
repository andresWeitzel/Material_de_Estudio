//Funcion valores LCD
void outputLcd(){
   //Borramos el contenido antes de imprimir la lectura del sensor dht11
  lcd.clear();
  //--Imprimimos  las lecturas del sensor dht11
  lcd.setCursor(0, 0);//Primera fila
  lcd.print("TEMPERATURA:");lcd.print(temp);lcd.print((char)223);//Lo ultimo es para grados centigrados
  lcd.setCursor(0, 1);//segunda fila
  lcd.print("HUMEDAD:");lcd.print(hum);lcd.print("%");
  delay(2000);//Para poder visualizar el contenido y no se borre rapido

  lcd.clear();
  //--Imprimimos la lectura del sensor de agua--
  lcd.setCursor(0,0);
  lcd.print("NIVEL DEL AGUA:");
  lcd.setCursor(7,1);//columna 8 fila 1
  lcd.print(nivelAgua);lcd.print("%"); 
  delay(200);
 
}
