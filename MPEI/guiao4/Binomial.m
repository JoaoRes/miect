function x = Binomial(n,p,N)
Bern=rand(n,N)<=p;
x=sum(Bern);
end

