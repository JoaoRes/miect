function [prob] = probAnalitica(p, k, n)
prob = factorial(n)/(factorial(n-k)*factorial(k))*p^k*(1-p)^(n-k);
end