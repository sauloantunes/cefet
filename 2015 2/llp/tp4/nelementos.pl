# Exercicio 1

nelementos([], 0).
nelementos([X|L1], Y1)
	:- nelementos(L1, Y), Y1 is Y+1.
