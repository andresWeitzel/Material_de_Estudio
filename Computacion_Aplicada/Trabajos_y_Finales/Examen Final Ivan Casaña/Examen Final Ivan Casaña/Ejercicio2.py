import numpy as np
from matplotlib import pyplot as plt
k=0
archivo="datos1711.txt"
f=open(archivo)
##encabezado=f.read(56)
texto=f.read()
##texto2=texto.replace("\t", "\n")
splitTexto=texto.split("\n")
size=int(len(splitTexto))
size=int((size))
T=np.empty(size)
V=np.empty(size)
I=np.empty(size)
for i in splitTexto:
    a=i.split()
    T[k]=float(a[0])
    V[k]=float(a[1])
    I[k]=float(a[2])
    k=k+1
plt.subplot(2, 2, 1)
plt.plot(T,V)
plt.title("T.V")
plt.xlabel("T")
plt.ylabel("V")

plt.subplot(2, 2, 2)
plt.plot(T,I)
plt.title("T,I")
plt.xlabel("T")
plt.ylabel("I")

plt.subplot(2, 2, 3)
plt.plot(T,V*I)
plt.title("T,V*I")
plt.xlabel("T")
plt.ylabel("V*I")

plt.xlabel("T")
plt.show()
input("FIN")
