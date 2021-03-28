
xi = 1:6; 
aux=ones(1,6)/6;

for c=1 :6
   p= cumsum(xi,p);
end
stem(xi,p), xlabel('x'), ylabel('px(x)');