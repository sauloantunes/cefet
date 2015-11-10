-- Exercicio 3

substituir :: Int -> Int -> [Int] -> [Int]
substituir _ _ [] = []
substituir a b (c:d)
	| a == c     = [b] ++ substituir a b d
	| otherwise  = [c] ++ substituir a b d