-- Exercicio 8





compara :: [Int] -> [Int] -> Bool
compara  [] _ = True
compara (b:z) a
	| b == estaEm a  = False
	| otherwise = compara z a

disjuntas :: [Int] -> [Int] -> Bool


substituir :: Int -> Int -> [Int] -> [Int]
substituir _ _ [] = []
substituir a b (c:d)
	| a == c     = [b] ++ substituir a b d
	| otherwise  = [c] ++ substituir a b d