-- Exercicio 7

-- tem n em [v]
compara :: Int -> [Int] -> Bool
compara n [] = False
compara n (a:x)
	| n == a = True
	| otherwise = compara n x

distintos :: [Int] -> Bool
distintos [] = True
distintos (a:x)
	| compara a x == True = False
	| otherwise = distintos x