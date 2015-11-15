-- Exercicio 10

somaPrimeiro :: Int -> [Int] -> [Int]
somaPrimeiro a [b]  = [a+b]
somaPrimeiro a (b:c) = [a+b] ++ somaPrimeiro (a+b) c

somaParciais :: [Int] -> [Int]
somaParciais [] = []
somaParciais [a] = [a]
somaParciais (a:b) = [a] ++ somaPrimeiro a b