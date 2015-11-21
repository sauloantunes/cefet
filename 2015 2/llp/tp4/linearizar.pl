# Exercício 10

concatenar([],L,L).
concatenar([X|Y],L1,[X|L2])
	:- concatenar(Y,L1,L2).

linearizar([],[]).
linearizar([X|Y],L)
	:- linearizar(Y, L2), concatenar(X, L2, L).
