# Exercício 6

adjacente(X, Y, [X,Y|Z]).
adjacente(X, Y, [Y,X|Z]).
adjacente(X, Y, [_,Z|W]) 
	:- adjacente(X, Y, [Z|W]).
