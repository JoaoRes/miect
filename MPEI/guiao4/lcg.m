function x = lcg(X0,a,c,m,N)
    x=zeros(1,N);
    x(1)=X0;
    for i=2:N
    x(i)=mod((a*x(i-1)+c),m) ;
    end
end

