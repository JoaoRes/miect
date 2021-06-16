grammar StrLangMain;

@parser :: header { 
    import java.util.*;
}

@parser :: members{ 
    HashMap<String, String> variables = new HashMap<>();
}

program : stat* EOF;

stat: 
        assignment
    |   expression
    |   print
    ;

assignment: ID ':' expression;

expression:
            'input' '(' STRING ')'                              #ExprInput
        |    '(' expression ')' *                               #ExprParent
        |   'add' expression 'to' expression 'at' expression    #ExprAdd
        |   'render' expression                                 #ExprRender
        |   expression '+' expression                           #ExprConcat
        |   expression '/' expression '/' expression            #ExprReplace
        |   STRING                                              #ExprString
        |   ID                                                  #ExprID
        ;

print: 'print' expression;

STRING : '"' .*? '"';
ID : [a-z] ([a-zA-Z0-9])?;
WS : [ \t\r\n] -> skip;
COMMENT: '//' .*? ('\n' | EOF) -> skip;
ERROR: .;