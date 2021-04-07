import numpy as np
signo = np.array(["capricornio", "acuario", "piscis", "aries", "tauro", "géminis", "cáncer", "leo", "virgo", "libra", "escorpio", "sagitario"])
fechas = np.array([[20], [19], [20], [20], [21], [21], [22], [22], [22], [22], [22], [21]])
dia=int(input("dia :"))
mes=int(input("mes :"))
mes=mes-1
if dia>fechas[mes]:
    mes=mes+1
if mes==12:
    mes=0
print ( signo[mes])
input("FIN")
