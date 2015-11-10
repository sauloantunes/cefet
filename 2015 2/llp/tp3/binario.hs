-- Exercicio 6

--inverte :: [Int] -> [Int]
--inverte []    = []
--inverte (a:x) = (inverte x) ++ [a]

--dec2bin :: Int -> [Int]
--dec2bin 0 = []
--dec2bin n = dec2bin (n `div` 2) ++ [n `mod` 2]

binario :: Int -> [Int]
binario 0 = [0]
binario 1 = [1]
binario n = binario (n `div` 2) ++ [n `mod` 2]
