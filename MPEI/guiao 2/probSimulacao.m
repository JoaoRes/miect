function [prob] = probSimulacao(p, k, n, N)
nAcontecimentos = rand(n,N) > p;
sucessos = sum(nAcontecimentos) == k;
prob = sum(sucessos)/N;
end

