
function salida = Ejercicio1 (x0)
  
  cota=1;
  TOL=0.5*10^-6;
 while (cota>TOL) 
  x1=cos( x0) ;
  cota=abs(x1-x0);
  x0=x1;
 end
 salida=x0;
end
