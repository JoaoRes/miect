function x = Fmp(X, p, N)
r=rand(1,N);
cs=cumsum(p);
x=zeros(1,length(N));
    for i=1:length(X)
        x = x + ((x == 0)&(r < cs(i))) * X(i); 
    end
end

