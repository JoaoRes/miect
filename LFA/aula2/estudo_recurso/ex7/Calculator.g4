grammar Calculator;

@parser :: header {
    import java.util.*;
}

@parser :: members {
    HashMap<String, Double> variables = new HashMap<>();
}

program: stat* EOF;

stat:
        assignment
    |   expr;

assignment: ID '=' expr;

expr: 
        unaryOp=('+'|'-') expr              #ExprUnary
    |   expr op=('*' | '/' | '%') expr      #ExprMultDivMod
    |   expr op=('+' | '-') expr            #ExprAddSub
    |   INTEGER                             #ExprInteger
    |   ID                                  #ExprID
    |  '(' expr ')'                         #ExprParent
    ;

INTEGER: [0-9]+;
ID: [a-zA-Z]+;
WS: [ \t\r\n]+ -> skip;
COMMENT: '#'.*? '\n'->skip;