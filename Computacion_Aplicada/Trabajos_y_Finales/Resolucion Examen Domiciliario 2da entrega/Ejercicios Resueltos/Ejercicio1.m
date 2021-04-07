function salida = Ejercicio1 (x, Tol,max)
n=1;
sumaFinal=1;
ultTermino=x;
while (Tol<ultTermino && n<max)
  total=x/n;
  for k=1:1:n-1
    total=total*(x/k);
  end
  ultTermino=total;
  n=n+1;
  sumaFinal= sumaFinal+total;
end
salida=sumaFinal;
end
