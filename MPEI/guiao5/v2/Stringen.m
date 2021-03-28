function str = Stringen (media, var, pmfPT)

    simbolos = ['a':'z' , 'A':'Z', 'Ã' , 'Õ', 'Á','É', 'Í', 'Ó', 'Ú', 'Â', 'À', 'Ç', 'ã' , 'õ', 'á','é', 'í', 'ó', 'ú', 'â', 'à', 'ç']; 
    length = round( media + (sqrt(var)* randn())); 
    f = cumsum(pmfPT);
    
    for j = 1 : length
        
        i = find(f > rand());
        str(j) = simbolos(i(1));
        
    end
   