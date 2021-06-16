grammar Maingrammar;

@parser:: header {
    import java.util.*;
}

@parser:: members {
    private HashMap<String, String> MapaStrings = new HashMap<>();
}

program: (stat*) EOF;

stat: declaration
    | expression
    | print;


declaration: var = ID ':' expression;

expression: 
            '(' expression ')'                                                  #ParentExpr
            |  String                                                           #StringExpr 
            | 'input' '(' expression ')'                                        #InputExpr
            | e1= expression '+' e2=expression                                  #SumExpr
            | e1= expression '/'  '"' sub= String '"' '/' '"' subpos=String '"' #SubExpr
            ;

print: 'print' expression ;


String : [a-zA-Z0-9]+;
ID: [a-zA-Z0-9]+;
WS: [ \t\n\r]+ -> skip;
Error: .;
Comment: '//'.*? ('\n' | EOF) -> skip;