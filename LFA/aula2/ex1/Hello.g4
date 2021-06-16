grammar Hello;
top : greetings | bye;
greetings : 'hello ' ID ;
bye: 'goodbye' ID;
name: ID+;

ID : [A-Za-z]+ ;
WS : [ \t\r\n]+ -> skip ;