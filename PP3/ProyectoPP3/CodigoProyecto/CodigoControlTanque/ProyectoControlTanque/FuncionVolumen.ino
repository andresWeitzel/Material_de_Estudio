

void volumenTanque(){

if(altura >= 19.00){
  volumen=0.00;
}else if(altura < 19.00 && altura >=18.90){//Los siguientes 2 else if se colocan para que no sea tan espaciados los volumenes
    volumen=0.05;  
}else if(altura < 18.90 && altura >=18.00){
    volumen=0.10;
//*A PARTIR DEL SIGUIENTE ELSE IF A LA ALTURA QUE CORRESPONDE A CADA VOLUMEN SE LE SACA 0.70
//CM PARA COMPENSAR LOS VALORES QUE NO SE MUESTRAN EN PANTALLA(0.151,0.152,ETC).CON ESTO LOGRAMOS UN APROXIMACION AL VALOR MEDIDO.
}else if(altura < 18.00 && altura >= 17.20){
  volumen=0.15;
  
}else if(altura < 17.20 && altura >= 16.70){
  volumen=0.30;
  
}else if(altura < 16.70 && altura >= 15.00){
  volumen=0.45;
  
}else if(altura < 15.00 && altura >= 14.20){
  volumen=0.60;

}else if(altura < 14.20 && altura >= 13.50){
  volumen=0.75;

}else if(altura < 13.50 && altura >= 12.70){
  volumen=0.90;

}else if(altura < 12.70 && altura >= 12.00){
  volumen=1.05;
  
}else if(altura < 12.00 && altura >= 11.20){
  volumen=1.20;  
  
}else if(altura < 11.20 && altura >= 10.50){
  volumen=1.35;
}else if(altura < 10.50 && altura >= 9.80){
  volumen=1.50;    
}else{
  volumen;
  
}

}



 
