grammar Hello;

choose: greetings
    |   bye;

greetings : 'hello' name ;

bye: 'goodbye' name;

name : ID+;

ID: [a-zA-Z]+;
WS: [ \t\r\n]+ -> skip;