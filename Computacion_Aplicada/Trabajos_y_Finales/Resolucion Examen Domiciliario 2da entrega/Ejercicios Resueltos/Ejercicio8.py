num = input("Ingrese numero:")
numInt=int(num)
flag=1
for n in range(2, numInt):
    if numInt%n == 0:
        flag=0
    
if flag==0:
    print("No es primo")
else:
    print("Es primo")
input("FIN")
