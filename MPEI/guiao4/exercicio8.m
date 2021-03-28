var = 2;
m = 14;
X = sqrt(var).*randn(1e6,1) + m;
X2 = Gaussiano(1e6);
X2 = sqrt(var).*X2 + m;
subplot(1,2,1);
hist(X,(0:20));
subplot(1,2,2);
hist(X2,(0:20));
