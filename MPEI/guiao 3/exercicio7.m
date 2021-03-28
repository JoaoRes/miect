%% a

probNoMessages = exp(-15);

disp("Probability of getting no messages in a second: " + probNoMessages);

%% b

i = 0:10;
p = (15.^i).*exp(-15)./factorial(i);
probAtLeast10Messages = 1 - sum(p);

disp("Probability of getting ten or more messages in a second: " + probAtLeast10Messages);