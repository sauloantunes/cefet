# Exercicio 2

maior([X], X).
maior([X,Y], X)
	:- X > Y.
maior([X,Y], Y)
	:- X < Y.
maior([X,Y|L1], Z)
	:- X > Y, maior([X|L1], Z).
maior([X,Y|L1], Z)
	:- X < Y, maior([Y|L1], Z).