import numpy as np
from matplotlib import pyplot as plt
k1=0;
k2=0;
flag=1
archivo=input("Ingrese Nombre de archivo(datoejercicio10_1.txt):  ")
f=open(archivo)
encabezado=f.read(56)
texto=f.read()
texto2=texto.replace("\t", "\n")
splitTexto=texto2.split("\n")
size=int(len(splitTexto))
size=int((size/2))
tension=np.empty(size)
corriente=np.empty(size)
potencia=np.empty(size)
for i in splitTexto:
    if len(i):
        if flag==1:
            tension[k1]=float(i)
            k1=k1+1
        elif flag==-1:
            corriente[k2]=float(i)
            k2=k2+1
        flag=-flag
potencia=tension*corriente
plt.plot(potencia)
plt.show()
input("FIN")
