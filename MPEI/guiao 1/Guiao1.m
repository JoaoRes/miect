%codigo 1

p = 0.5; %probablidade de sair cara
k > 5; %numero de caras
n = 15; %numero de lançamentos 
prob= factorial(n)/(factorial(n-k)*factorial(k))*p^k*(1-p)^(n-k)

%codigo 2

m=0;
for c =0 : 5
m= m+probabibi(0.5, c , 20 ,1e5);
end

prob= 1-m
stem(prob)