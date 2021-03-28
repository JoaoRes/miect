function [key] = Keygen(min, max)   
    symbols= ['a':'z' 'A':'Z'];
    length= randi([min, max]);
    nums = randi(numel(symbols),[1,length]);
    key = symbols (nums);
end

