# Exercicio 3

soma([], 0).
soma([X], X).
soma([X|L], Z1) 
	:- soma(L, Z), Z1 is Z+X.

nelementos([], 0).
nelementos([X|L1], Y1)
	:- nelementos(L1, Y), Y1 is Y+1.

medio(L, X) :- soma(L, S), nelementos(L, Q), X is S/Q.