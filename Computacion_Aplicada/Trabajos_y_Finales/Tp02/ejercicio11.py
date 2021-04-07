#!/usr/bin/env python
# coding: utf-8

# In[8]:


import numpy as np
from matplotlib import pyplot as plt
i=0
class Estaciones:
    indice=[]
    nombre=[]
class Temp:
    fecha=[]
    tMin=[]
    Tmax=[]
    nombre2=[]
class TempMaxMin:
    tempMax=[]
    tempMin=[]
   
archivo=input("Ruta de archivo: ")
index=int(input("Ingrese numero de la estacion: "))-1
f=open(archivo)
texto=f.read()
texto1 = texto.strip()
texto2=texto1.replace("   ","")
splitTexto=texto2.split("\n")
for x in splitTexto:
    dato=x.split()
    Estaciones.indice.append(dato[0])
    Estaciones.nombre.append(dato[1:])
f.close()
archivo2=input("Ruta de archivo: ")
f=open(archivo2)
encabezado=f.read(202)
texto=f.read()
texto1 = texto.strip()
splitTexto=texto1.split("\n")
for x in splitTexto:
    dato=x.strip()
    dato=x.split()
    if len(dato)>3:
        Temp.fecha.append(dato[0])
        Temp.Tmax.append(dato[1])
        Temp.tMin.append(dato[2])
        Temp.nombre2.append(dato[3:])
f.close()
D=Estaciones.nombre[index]
print(D)
for x in Temp.nombre2:
    i=i+1
    if x==D:
        tM=float(Temp.Tmax[i])
        TempMaxMin.tempMax.append(tM)
        tm=float(Temp.tMin[i])
        TempMaxMin.tempMin.append(tm)
        ran=len(TempMaxMin.tempMin)
min1=min(TempMaxMin.tempMin)
max1=max(TempMaxMin.tempMax)
print(min1)
print(max1)


plt.plot(TempMaxMin.tempMin,'b')
plt.plot(TempMaxMin.tempMax,'r')

##plt.plot(1,min1,'o''b')
##plt.plot(1,max1,'o''r')
plt.show()


# In[ ]:





# In[ ]:


C:/Users/andre/OneDrive/Escritorio/TPInformaticaAplicada/Tp02/estaciones_metereologicas.txt


# In[ ]:


C:/Users/andre/OneDrive/Escritorio/TPInformaticaAplicada/Tp02/estacionmetereologica_smn.txt

