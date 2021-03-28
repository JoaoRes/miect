n = 1000;
loadFactor = 0.8;
m= round(n/loadFactor);
counter = zeros(1, m);

alpha = ['a':'z' , 'A':'Z', 'Ã' , 'Õ', 'Á','É', 'Í', 'Ó', 'Ú', 'Â', 'À', 'Ç', 'ã' , 'õ', 'á','é', 'í', 'ó', 'ú', 'â', 'à', 'ç']; 

%  ficheiros a serem processados (do projecto Gutemberg)
ficheiros={'pg21209.txt','pg26017.txt'};

% obter função massa de probabilidade (pmf em Inglês)
pmfPT=pmfLetrasPT(ficheiros, alpha);

%  visualizar função massa de probabilidade
stem(pmfPT)

atr = cumsum(pmfPT);

for i = 1: 1000
    k = Stringen(10,5, pmfPT);
    hash = rem(string2hash(k), m) + 1; 
    counter(hash)  = counter(hash) + 1;
    
    if rem (i, 100) == 0
        subplot(1,2,1)
        bar(counter)
        title('Strings da hash');
        
        subplot(1,2,2)
        hist(counter, 0:8)
        title('Hist da hash');
    
    end
 
end

figure
subplot(1,2,1)
successos = histc(counter, 0:9);
pm = successos / m;
stem(0:9, pm);
title('x aleatorio');
axis([-0.5, 9.5, 0, 0.5]);

X = [0:9];
E_X = sum(X .* pm);
E_X2 = sum(pm .* X.^2);
variancia = E_X2 - (E_X)^2;
fprintf("Valor medio = %d\nVariancia = %d\n", E_X, variancia);