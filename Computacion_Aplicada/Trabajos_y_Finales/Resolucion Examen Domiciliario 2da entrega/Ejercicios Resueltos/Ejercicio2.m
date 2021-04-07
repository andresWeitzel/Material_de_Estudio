function salida = Ejercicio2 (mt,i, j)
m1=mt(1:3,1:3);
m2=mt((1:3),(1:3)+3);
m3=mt((1:3),(1:3)+6);
m4=mt((1:3)+3,1:3);
m5=mt((1:3)+3,(1:3)+3);
m6=mt((1:3)+3,(1:3)+6);
m7=mt((1:3)+6,1:3);
m8=mt((1:3)+6,(1:3)+3);
m9=mt((1:3)+6,(1:3)+6);
if ((0<i) && (i<4) )
  if((0<j) && (j<4) )
  indice=1;
  end
  if((3<j) && (j<7) )
  indice=2;
  end
  if((6<j) && (j<10) )
  indice=3;
  end
end
if ((3<i) && (i<7) )
  if((0<j) && (j<4) )
  indice=4;
  end
  if((3<j) && (j<7) )
  indice=5;
  end
  if((6<j) && (j<10) )
  indice=6;
  end
end
if ((6<i) && (i<10) )
  if((0<j) && (j<4) )
  indice=7;
  end
  if((3<j) && (j<7) )
  indice=8;
  end
  if((6<j) && (j<10) )
  indice=9;
  end
end
 switch (indice)
            case {1}
              v3 = m1;
            case {2}
              v3 = m2;
              case {3}
              v3 = m3;
              case {4}
              v3 = m4;
              case {5}
              v3 = m5;
              case {6}
              v3 = m6;
              case {7}
              v3 = m7;
              case {8}
              v3 = m8;
              case {9}
              v3 = m9;
            otherwise
              error ("invalid value");
          end
v1=[v3(1,:) v3(2,:) v3(3,:)] ;
v2=mt(i,:);
v4=mt(:,j);
 salida=[v1;v2;v4'];
 end
