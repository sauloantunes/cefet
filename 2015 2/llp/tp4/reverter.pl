# Exercício 8

concatenar([], L, L).
concatenar([X], L, [X|L]).
concatenar([X|Y], L1, [X|L2])
	:- concatenar(Y, L1, L2).

reverter([],[]).
reverter([X],[X]).
reverter([X|Y], L)
	:- reverter(Y, YR), concatenar(YR,[X], L).