# Exercício 7

gerar(X, X, [X]).
gerar(X, Y, [X|L])
	:- gerar(X1,Y,L), X is X1 - 1.