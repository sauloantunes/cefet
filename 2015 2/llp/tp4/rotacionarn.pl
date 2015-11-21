# Exercício 14

concatenar([],L,L).
concatenar([X|Y],L1,[X|L2])
	:- concatenar(Y,L1,L2).

rotacionarn(0,L,L).
rotacionarn(1,[X|Y],L)
	:- concatenar(Y,[X],L).
rotacionarn(N1,L,L2)
	:- rotacionarn(1,L,L1), rotacionarn(N,L1,L2), N1 is N+1.
