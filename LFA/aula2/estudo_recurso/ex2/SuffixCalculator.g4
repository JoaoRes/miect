grammar SuffixCalculator;

program: stat* EOF;

stat: expr? NEWLINE;

expr:  
        expr expr op=('*'|'/'|'+'|'-')  #ExprSuffix
    |   NUMBER                          #ExprNumber
    ;

NUMBER: [0-9]+('.'[0-9]+)?;
NEWLINE: '\r'? '\n';
WS: [ \t]+ -> skip;