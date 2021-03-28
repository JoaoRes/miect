function [prob] = probabibi(p ,k, n, N)  
lancamentos = rand(n,N)>p;
sucessos= sum(lancamentos)==k;
prob= sum(sucessos)/N;
end

