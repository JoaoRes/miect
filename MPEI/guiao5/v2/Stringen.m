function str = Stringen (media, var, pmfPT)

    simbolos = ['a':'z' , 'A':'Z', '�' , '�', '�','�', '�', '�', '�', '�', '�', '�', '�' , '�', '�','�', '�', '�', '�', '�', '�', '�']; 
    length = round( media + (sqrt(var)* randn())); 
    f = cumsum(pmfPT);
    
    for j = 1 : length
        
        i = find(f > rand());
        str(j) = simbolos(i(1));
        
    end
   