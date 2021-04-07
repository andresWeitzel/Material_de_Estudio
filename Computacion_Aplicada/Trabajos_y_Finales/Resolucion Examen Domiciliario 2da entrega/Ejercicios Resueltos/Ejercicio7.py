ultTerm=3
difUltTerm=1
dif=1*10**(-12)
signo=-1
pi=3
aux=3
i=2
while difUltTerm>dif:
    aux=ultTerm
    ultTerm = 4 /(i*(i+1)*(i+2))
    signo=signo*(-1)
    pi = pi + ultTerm*signo
    absUltTerm=abs(ultTerm)
    difUltTerm=aux-absUltTerm
    i=i+2

print(pi)
input("FIN")

