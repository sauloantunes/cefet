smartphone(iphone4).
smartphone(iphone4s).
smartphone(iphone5s).
smartphone(galaxyS3).
smartphone(galaxyS4).
smartphone(bbZ10).
smartphone(lumia).

acessorio(capaIphone5s).

compra(1, iphone4s, 1300).
compra(1, galaxyS3, 1400).
compra(2, iphone5s, 2400).
compra(2, capaIphone5s, 80).
compra(3, iphone5s, 2500).
compra(3, galaxyS4, 2300).
compra(4, bbZ10, 1800).
compra(5, iphone4s, 1300).
compra(5, iphone4, 1000).
compra(6, lumia, 1700).

cliente(1, gabriel, 21, estudante).
cliente(2, bruna, 30, medico).
cliente(3, rafaela, 25, arquiteto).
cliente(4, victor, 39, advogado).
cliente(5, beatriz, 18, estudante).
cliente(6, joao, 28, engenheiro).

listar_clientes(L)
	:- findall(X, cliente(_, X, _, _), L).

listar_dados_cliente(C, [N, I, P, L])
	:- cliente(C, N, I, P), findall([S, V], compra(C, S, V), L).

listar_smartphones(L)
	:- setof(S, smartphone(S), L). 

contar([], 0).
contar([X|Y], N1)
	:- contar(Y, N), N1 is N + 1.

contar_smartphones(N)
	:- listar_smartphones(L), contar(L, N).

soma([], 0).
soma([X|Y], S1)
	:- soma(Y, S), S1 is S + X.

somar_smartphones(S)
	:- findall(V, (compra(_, S, V), smartphone(S)), L), soma(L, S).

listar_estudantes(L)
	:- findall(C, cliente(_, C, _, estudante), L).

preco_medio(X)
	:- contar_smartphones(N), somar_smartphones(S), X is S/N.