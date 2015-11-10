-- Exercicio 4

fatores :: Int -> [Int]
fatores 0 = []
fatores n = [ i | i <- [2.. n`div`2 ], n `mod` i == 0 ]

primo :: Int -> Bool
primo x = fatores x == []
