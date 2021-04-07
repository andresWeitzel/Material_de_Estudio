archivo=input("Ingresar Nombre de Archivo (""datoejercicio4_1.txt""): ");
FID=fopen(archivo,'r');%abrir archivo
encabezado=fscanf(FID,'%s',6);%lectura encabezado
i=1;
j=1;
while (feof(FID)==0)
  strTension=fscanf(FID,'%s',1);
  if length(strTension)
    cTension(i)=str2num (strTension);
    num=cTension(i);
    i=i+1;
  end
  strCorriente=fscanf(FID,'%s',1);
  if length(strTension)
    cCorriente(j)=str2num (strCorriente);
    num=cCorriente(j);
    j=j+1;
  end
end
Y=Ejercicio3(cTension,cCorriente);
plot(cTension,cCorriente,'ro',cTension,Y)
grid on;
title("Ejercicio4");
xlabel("Tension");
ylabel("Corriente");
legend("(x,y)","(x,Y)")
fclose(FID)

