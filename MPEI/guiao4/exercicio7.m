N=30;
m=14;
var=2;

[X,Y]=BoxMuller(N);
a=(X.*var)+m;

hist(a,0:20)

ax=axis;
ax(1)=0;
ax(2)=20;
axis(ax);