# Exercício 13

concatenar([],L,L).
concatenar([X|Y],L,[X|L1])
	:- concatenar(Y,L,L1).

rotacionar([],[]).
rotacionar([X],[X]).
rotacionar([X|Y],W)
	:- concatenar(Y,[X],W).