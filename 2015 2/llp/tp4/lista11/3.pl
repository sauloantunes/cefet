velocidade(gol, 100).
velocidade(palio, 110).

tempo(gol, 10).
tempo(palio, 15).

distancia(Carro, Dist)
	:- velocidade(Carro, V),tempo(Carro, T), Dist is V*T.