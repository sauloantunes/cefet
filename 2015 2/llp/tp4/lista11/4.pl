pai(antonio, teodorico).
pai(cleria, teodorico).
pai(nelcides, joao).
pai(zilma, joao).
pai(samara, ze).
pai(samanta, ze).
pai(danilo, ze).
pai(henrique, nelcides).
pai(rafael, nelcides).
pai(welligton, nelcides).
pai(saulo, antonio).
pai(anderson, antonio).

mae(antonio, santinha).
mae(cleria, santinha).
mae(nelcides, luzia).
mae(zilma, luzia).
mae(samara, cleria).
mae(samanta, cleria).
mae(danilo, cleria).
mae(henrique, rosilene).
mae(rafael, rosilene).
mae(welligton, rosilene).
mae(saulo, zilma).
mae(anderson, zilma).

avo(X, A) :- 
	mae(X, M), mae(M, A);
	mae(X, M), pai(M, A);
	pai(X, P), mae(P, A);
	pai(X, P), pai(P, A).

avos(P, A)
	:- findall(X, avo(P,X), A).

pais(P,Z)
	:- findall(X, pai(P,X); mae(P,X), Z).

irmao(P,I) :-
	pai(P,X), pai(I,X), P \= I;
	mae(P,X), mae(I,X), P \= I.

irmaos(P,I)
	:- setof(X, irmao(P,X), I).

primo(X,Y) :-
	pai(Y,T), pai(X,P), irmao(T,P);
	pai(Y,T), mae(X,M), irmao(T,M);
	mae(Y,T), pai(X,P), irmao(T,P);
	mae(Y,T), mae(X,M), irmao(T,M).

primos(X,Y)
	:- setof(Z, primo(X,Z),Y).

tio(X,T) :-
	primo(X,Y), pai(Y,T);
	primo(X,Y), mae(Y,T).

tios(P,T)
	:- setof(X, tio(P,X), T).