-- Exercicio 12

shift :: Int -> [Int] -> [Int]
shift _ [] = []
shift 0 a  = a
shift n (a:b) = shift (n-1) (b ++ [a])