grammar Calculator;

@parser :: header { import java.util.*; }
@parser :: members {HashMap<String, Integer> variables = new HashMap<>();}

program: stat* EOF;

stat: 
        assignment
    |   expression
    ;

assignment: ID '=' expression;

expression: 
            '(' expression ')'                      #ExprParent
        |   unaryOp=('-'|'+') expression            #ExprUnary
        |   expression op=('*' | '/') expression    #ExprMultDiv
        |   expression op=('+' | '-') expression    #ExprAddSub
        |   ID                                      #ExprID
        |   INT                                     #ExprInt
        ;

INT: [1-9] ([0-9]+)?;
ID: [a-zA-Z]+;
WS: [ \t\r\n] -> skip;
COMMENT: '//' .*? ('\n' | EOF) ->skip;