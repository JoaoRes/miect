grammar StrLangMain;

program : stat* EOF;

stat: 
        assignment
    |   expression
    |   print
    ;

assignment: ID ':' expression;

expression:
           'input' '(' STRING ')'                      #ExprInput
        |   '(' expression ')'                          #ExprParent
        |   expression '+' expression                   #ExprConcat
        |   expression '/' expression '/' expression    #ExprSubs
        |   STRING                                      #ExprString
        |   ID                                          #ExprID
        ;

print: 'print' expression;

ID: [a-zA-Z0-9]+;
STRING: '"' .*? '"';
WS: [ \t\r\n]+ ->skip;
COMMENT: '//' .*? ('\n' | EOF) ->skip;
ERROR: .;