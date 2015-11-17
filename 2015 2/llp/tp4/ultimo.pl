# Exercício 5

ultimo([X], X).
ultimo([X|L1], Y)
	:- ultimo(L1, Y).