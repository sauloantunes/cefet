-- Exercicio 8

contem :: Int -> [Int] -> Bool
contem _ [] = False
contem a (b:c)
	| a == b = True
	| otherwise = contem a c

disjuntas :: [Int] -> [Int] -> Bool
disjuntas [] _ = True
disjuntas (a:b) c
	| contem a c = False
	| otherwise  = disjuntas b c