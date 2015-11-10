-- Exercicio 5

fatores :: Int -> [Int]
fatores 0 = []
fatores n = [ i | i <- [1.. n`div`2 ], n `mod` i == 0 ]

soma :: [Int] -> Int
soma [] = 0
soma (a:x) = a + soma x

perfeito :: Int -> Bool
perfeito n 
	| n == (soma (fatores n) ) = True
	| otherwise 		  = False