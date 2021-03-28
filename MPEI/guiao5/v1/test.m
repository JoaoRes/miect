str = Keygen(4,16)

hash=string2hash(str)

n = 1000;
loadFactor = 0.8;
m = n/loadFactor;

count = zeros(1, m);

for i = 1: 1000
    chave = Keygen (3,20);
    hash = rem(string2hash(chave), m) + 1; 
    count(hash)  = count(hash) + 1;
    
    if rem (i, 100) == 0
        subplot(1,2,1)
        bar(count)
        title('Strings da hash');
        
        subplot(1,2,2)
        hist(count, 0:8)
        title('Hist de Strings da hash');
    end
 
end

figure
subplot(1,2,1)
successos = histc(count, 0:9);
pm = successos / m;
stem(0:9, pm);
title('x aleatorio');
axis([-0.5, 9.5, 0, 0.5]);

X = [0:9];
E_X = sum(X .* pm);
E_X2 = sum(pm .* X.^2);
variancia = E_X2 - (E_X)^2;
fprintf("Valor medio = %d\nVariancia = %d\n", E_X, variancia);

