function vectorY = Ejercicio3 (x,y)
 n=length(x); 
 
 xm=sum(x)/n; %xmedio
 ym=sum(y)/n; %ymedio
 prodxy=x.*y; 
 xym=sum(prodxy)/n; %xy medio
 x2=x.*x;
 x2m=sum(x2)/n; %x^2 medio
 vectorY=(ym)+(((xym-(xm.*ym))./(x2-(xm.*xm))).*(x-xm));
 

end