lexer grammar hello;

IF : 'if';
ID : ('a'..'z')('a'..'z'| '0'..'9'|'_')*;
WS : [ \r\n\t]+ -> skip;