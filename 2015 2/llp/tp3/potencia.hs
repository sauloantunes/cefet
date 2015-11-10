-- Exercicio 1

potencia :: Int -> Int -> Int
potencia base x
	| x == 0    = 1
	| otherwise = base * potencia base (x-1)
