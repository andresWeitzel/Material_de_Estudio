import numpy as np
from matplotlib import pyplot as plt
import pandas as pd
import datetime as dt

i=0  #contador choras,ctemp


class Fechas: #listas
    cFechas=[] # las fechas .strptime
    cHoras=[] #almacena temporalmente las horas de un dia para buscar min y max
    cTemp=[] #almacena las temperaturas temporalmente por dia
    cTempDiferencia=[] # guarda la diferencia dehoras 
 
tabla = pd.read_csv('datoejercicio12.csv')
#separa en columnas
tablatimestamp=tabla['timestamp']
temperatureTabla=tabla['Basilea Temperature [2 m elevation corrected]']
precipiteTabla=tabla['Basilea Precipitation Total']
windTabla=tabla['Basilea Wind Speed [10 m]']


#strptime fechas en Fechas.cFechas
for n in tablatimestamp:
    fecha=n
    tfecha=dt.datetime.strptime(fecha, '%Y%m%dT%H%M')
    Fechas.cFechas.append(tfecha)

a=Fechas.cFechas[0] #inicializa a
dia=a.day #valor inicio dia
for n in Fechas.cFechas: #buscar max y min 
    
    auxdia=dia #valor auxiliar para comparar dia 
    dia=n.day 
    
    hora=n.hour
    if dia==auxdia:
        Fechas.cHoras.append(hora)
        Fechas.cTemp.append(temperatureTabla[i])
        Fechas.cHoras.append(temperatureTabla[i])
        min0=min(Fechas.cTemp)
        max0=max(Fechas.cTemp)
        
    else:
        hMax= Fechas.cTemp.index(max0)
        hMin= Fechas.cTemp.index(min0)
        hDiferencia0=hMax-hMin
        hDiferencia=np.absolute(hDiferencia0)
        Fechas.cTempDiferencia.append(hDiferencia)
        print("dia: ",dia)
        print("min: ",min0," hora: ", hMin)
        print("max: ",max0," hora: ", hMax)
        print("Diferencia de horas: ", hDiferencia)
        Fechas.cHoras.clear()
        Fechas.cTemp.clear()
        print("_____________")     
    i=i+1
#imprime  temperatura max y min del periodo   
min1=min(temperatureTabla)
max1=max(temperatureTabla)
print("maxPeriodo: ",max1)
print("minPeriodo: ",min1)

#graficos
plt.subplot(2, 2, 1)
plt.plot(Fechas.cTempDiferencia)
plt.title("Diferencias de horas min y max")

plt.subplot(2, 2, 2)
plt.plot(temperatureTabla,'r',label="temperatureTabla")
plt.title("temperatureTabla")

plt.subplot(2, 2, 3)
plt.plot(precipiteTabla,'g')
plt.title("precipiteTabla")

plt.subplot(2, 2, 4)
plt.plot(windTabla,'y')
plt.title("windTabla")


plt.show()

input("FIN")
