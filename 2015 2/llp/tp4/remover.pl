# Exercício 12

remover(X,[],[]).
remover(X,[X],[]).
remover(X,[X|Y],W)
	:- remover(X,Y,W).
remover(X,[Z|Y],[Z|W])
	:- remover(X,Y,W).