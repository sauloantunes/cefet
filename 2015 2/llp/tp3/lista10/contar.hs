soma :: [Int] -> Int
soma [] = 0
soma (a:b) = 1 + soma b

contar :: [Int] -> Int
contar l = soma [1 | i <- l, i < 0 ]