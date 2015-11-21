# Exercício 7

incrementar([], []).
incrementar([X], [X1])
	:- X1 is X + 1.

incrementar([X|L], [X1|L1])
	:- X1 is X + 1, incrementar(L, L1).