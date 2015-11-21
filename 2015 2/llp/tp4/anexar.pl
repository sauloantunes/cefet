# Exercício 11

anexar([],L,L).
anexar([X|Y],L,[X|L1])
	:- anexar(Y,L,L1).