p = linspace(0,1);

twoEnginesCrashProb = nchoosek(2,2) * p.^2;

fourEnginesCrashProb = 0;
for i=3:4 
    fourEnginesCrashProb = fourEnginesCrashProb + nchoosek(4,i) * p.^i .* (1-p).^(4-i);
end

figure(1);
subplot(1, 2, 1);
plot(p,twoEnginesCrashProb, p, fourEnginesCrashProb);
legend('Plane with two engines', 'Plane with four engines');
title('Two and Four Engine Plane Crash Probability');
xlabel('Engine Failure Probability (p)');
ylabel('Plane Crash Probability');

subplot(1, 2, 2);
loglog(p,twoEnginesCrashProb, p,fourEnginesCrashProb);
legend('Plane with two engines', 'Plane with four engines');
title('(Logarithmic) Two and Four Engine Plane Crash Probability');
xlabel('Engine Failure Probability (p)');
ylabel('Plane Crash Probability');