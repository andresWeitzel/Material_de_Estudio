cant=input("Ingresar Cantidad de imagenes que desea procesar: ");
for k=1:1:cant
  Ejercicio5
  xVec(k)=x;
  yVec(k)=y; 
endfor
Y=Ejercicio3(xVec,yVec);
plot(xVec,yVec,'ro',xVec,Y)
grid on;
title("Ejercicio6");
xlabel("X");
ylabel("Y");
legend("(x,y)","(x,Y)")