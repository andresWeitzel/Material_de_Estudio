#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt


# In[26]:


archivo= pd.read_fwf('C:/Users/andre/OneDrive/Escritorio/TPInformaticaAplicada/Tp02/datoejercicio10_1.txt')


# In[ ]:


C:/Users/andre/OneDrive/Escritorio/TPInformaticaAplicada/Tp02/datoejercicio10_1.txt


# In[ ]:





# In[ ]:


posTension=0;
posCorriente=0;
flag=1;
archivo=input("Ingrese Nombre de archivo(datoejercicio10_1.txt):  ")
file=open(archivo)
encabezado=file.read(56)
texto=file.read()
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
            tension[posTension]=float(i)
            posTension=posTension+1
        elif flag==-1:
            corriente[posCorriente]=float(i)
            posCorriente=posCorriente+1
        flag=-flag
potencia=tension*corriente
plt.plot(potencia)
plt.show()
input("FIN")


# In[ ]:





# In[ ]:




