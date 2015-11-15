-- Exercicio 11

linearizar :: [[Int]] -> [Int]
linearizar [] = []
linearizar (a:b) = a ++ linearizar b