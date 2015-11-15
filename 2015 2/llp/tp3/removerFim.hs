-- Exercicio 13

inverte :: [Int] -> [Int]
inverte []    = []
inverte (a:b) = inverte b ++[a]

removerInicio :: Int -> [Int] -> [Int]
removerInicio 0 a     = a
removerInicio _ []    = []
removerInicio n (a:b) = removerInicio (n-1) b

removerFim :: Int -> [Int] -> [Int]
removerFim n a = inverte (removerInicio n (inverte a))