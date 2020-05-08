/**--VOLUMEN DE UN CILINDRO--**
 * --VOLUMEN HASTA EL LIMITE MAXIMMO DEL SENSOR DE AGUA--
 * Sabemos que para obtener el volumen deun cilindro es pi*radio^2*altura, y a su vez el radio^2 es el diametro del ciliindro.
 * Nuestro cilindro tiene un diametro aproximado de 14 cm(el radio es la mitad:7 cm), y la altura sera hasta la del sensor de agua(por que si pasa esta
 * se quema el sensor y tambien el dht11).
 * 
 * Ecuacion de Volumen-->V=pi*r^2*h-->V=3,14*7cm^2*11cm-->V=1692cm^3 
 * 
 *   1  cm^3 =   1   ml
 * 1692 cm^3 =(1692  ml)-->1692 ml=((1,69L))(COMPROBADO EXPERIMENTALMENTE, TIENE UN MARGEN DE ERROR DESPRECIABLE)
 * 
 * --VOLUMEN HASTA EL SENSOR HC ULTRASONICO--
 * Mismo analisis, difiere la altura(h).La h la tomamos del ultrasonico aprox
 * V=3,14*7^2*18.95-->V=2915cm^3 = ((2,92L))
 * 
 *
 * --ASOCIAMOS LA ALTURA DEL CILINDRO CON EL VOLUMEN DEL CILINDRO--
 * altura maxima recipiente=18.95cm aprox
 * volumen maximo recipiente=2.92L
 * 
 * altura maxima sensor agua=11.00cm
 * volumen maximo sensor de agua=1.69L
 * 
 *--Mediciones para cada 150ml de agua aproximadamente
 *0ml-->18.79cm aprox
 *0ml-150ml-->17.95cm
 *150ml-300ml-->16.76cm
 *300ml-450ml-->16.22cm;//a esta h esta la canilla, se pierde volumen en el cilindro, se va para la canilla 
 *450-600ml-->15.40cm;
 *600ml-750ml-->14.47cm
 *750ml-900ml-->13.93cm
 *900ml-1050ml-->13.03cm//Se llega al sensor de agua
 *1050ml-1200ml-->11.72cm//Alarma Baja
 *1200ml-1350ml-->10.50cm//Alarma Media
 *1350-1500ml-->9.80cm//Alarma alta--Hasta aca debe llegar el Nivel de Agua(altura maxima hasta el sensor de agua)
 *
 * 
 * --FUNCION VOLUMEN--
 * 18.95cm(altura)--0.00L
 * 3.21cm(altura)--2.92L//Minima h de sensado por el ultrasonico, por ciertas razones no llega a los 0cm
 * 
 * --Variables--
float volumenMin=0.00;
float volumenMax=2.92;
float alturaMax=18.80;
float alturaMin=3.21;
float volumen;
float tiempo,altura;//variables para el HC-SR04 


 */
void volumenTanque(){

if(altura > 18.20){
  volumen=0.00;
//*A PARTIR DEL SIGUIENTE ELSE IF A LA ALTURA QUE CORRESPONDE A CADA VOLUMEN SE LE SACA 0.70
//CM PARA COMPENSAR LOS VALORES QUE NO SE MUESTRAN EN PANTALLA(0.151,0.152,ETC).CON ESTO LOGRAMOS UN APROXIMACION AL VALOR MEDIDO.
}else if(altura < 18.20 && altura > 17.20){
  volumen=0.15;
  
}else if(altura < 17.20 && altura > 16.70){
  volumen=0.30;
  
}else if(altura < 16.70 && altura > 15.00){
  volumen=0.45;
  
}else if(altura < 15.00 && altura > 14.20){
  volumen=0.60;

}else if(altura < 14.20 && altura > 13.50){
  volumen=0.75;

}else if(altura < 13.50 && altura > 12.70){
  volumen=0.90;

}else if(altura < 12.70 && altura > 12.00){
  volumen=1.50;
}else{
  volumen;  
}
/*
 *0ml-->18.79cm
 *0ml-150ml-->17.95cm
 *150ml-300ml-->16.76cm
 *300ml-450ml-->16.22cm;//a esta h esta la canilla, se pierde volumen en el cilindro, se va para la canilla 
 *450-600ml-->15.40cm;
 *600ml-750ml-->14.47cm
 *750ml-900ml-->13.93cm
 *900ml-1050ml-->13.03cm//Se llega al sensor de agua
 *1050ml-1200ml-->11.72cm//Alarma Baja
 *1200ml-1350ml-->10.50cm//Alarma Media
 *1350-1500ml-->9.80cm//Alarma alta--Hasta aca debe llegar el Nivel de Agua(altura maxima hasta el sensor de agua)
 */
}


 /*
  //Bucle que aumente 0.50L en .50L el volumen
  for(volumen; volumen < 0.150; volumen=volumen + 0.050){
    delay(100);//para que sean legibles las lecturas
  }*/


  

/*
 if((altura < alturaMax) && (volumen < volumenMax)){
    volumen=volumen + 0.50;
    altura--;         
  }else{
    volumen=volumen;
    altura=altura;*/
 
