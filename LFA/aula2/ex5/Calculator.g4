grammar Calculator;
program :
    stat* EOF
    ;
stat :
            expr? NEWLINE           #Expression
        |   assignment? NEWLINE     #Variable
    ;
assignment: ID '=' expr;

expr:   op=('-'| '+') expr          #ExprIntegerSignal
    |   expr op=('*'|'/'|'%') expr  #ExprMultDivMod
    |   expr op=('+'|'-') expr      #ExprAddSub
    |   Integer                     #ExprInteger
    |   ID                          #ExprID
    |   '(' expr ')'                #ExprParent
    ;

Integer: [0-9]+; //implement with long integers
ID: [a-zA-Z]+;
NEWLINE: 'r'? '\n';
WS: [ \t]+ -> skip;
COMMENT: '#' .*? '\n' -> skip;