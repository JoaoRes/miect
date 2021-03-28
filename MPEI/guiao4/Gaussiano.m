function [vetor] = Gaussiano(N)
    xaxis = -5 + (5+5) .* rand(N,1);
    distribuicao = makedist('Normal', 'mu', 0, 'sigma', 1);
    massa = pdf(distribuicao,xaxis);
    
    maximo = 1/(sqrt(2*pi));
    y = 0 + (maximo) .* rand(N,1);
    vetor = zeros(1,N);
    count = 1;
    for i=1:N
        if ( y(i) <= massa(i))
            vetor(count) = xaxis(i);
            count = count + 1;
        end
    end
end
