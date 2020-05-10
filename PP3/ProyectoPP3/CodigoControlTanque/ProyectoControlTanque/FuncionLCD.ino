//Funcion valores LCD
void outputLcd(){
   //**TANQUE DE AGUA**
   
  //--Imprimimos  las lecturas del sensor dht11
  lcd.setCursor(0, 0);//Primera fila
  lcd.print("-TANQUE DE AGUA-");
  lcd.setCursor(0, 1);//segunda fila
  lcd.print("V");lcd.print(volumen);lcd.print("L"); 
  lcd.setCursor(7, 1);
  lcd.print("T");lcd.print(temp);lcd.print((char)223);//Lo ultimo es para grados centigrados
  lcd.setCursor(12,1);
  lcd.print("H");lcd.print(hum);lcd.print("%");

  delay(2000);//Cada 2 seg se actualizan las mediciones

  /*//--Imprimimos la lectura del sensor de agua--
  lcd.setCursor(0,0);
  lcd.print("CAPACIDAD LIMITE:");
  lcd.setCursor(7,1);//columna 8 fila 1
  lcd.print(limiteAgua);lcd.print("%"); 
  delay(200);
 */

  //**SALA DE CONTROL**
  //PROXIMAMENTE............
  
  
}


/*
//-----------------Variables-------------------------
//--Calculo de volumen--
float volumenMin=0.00;
float volumenMax=1.50;
float alturaMax=9.80;
float alturaMin=18.79;
float volumen=0.00;
float tiempo,altura;//variables para el HC-SR04 


*/
