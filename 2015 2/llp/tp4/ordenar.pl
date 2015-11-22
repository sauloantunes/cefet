# Exercício 15 (bubble sort)

tamanho([], 0).
tamanho([X|Y], N1)
	:- tamanho(Y,N), N1 is N + 1.

concatena([],L,L).
concatena([X|Y],L,[X|L1])
	:- concatena(Y,L,L1).

troca([X],[X]).
troca([X,Y|Z],W)
	:- X =< Y, troca([Y|Z],W1), concatena([X], W1, W).
troca([X,Y|Z],W)
	:- X > Y, troca([X|Z],W1), concatena([Y], W1, W).

trocan(0,L,L).
trocan(N1,L,L1)
	:- troca(L, L2), trocan(N,L2,L1), N1 is N+1.

ordenar(L,L1)
	:- tamanho(L,N), trocan(N,L,L1).