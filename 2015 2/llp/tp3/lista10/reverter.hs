reverter :: [Int] -> [Int]
reverter [] = []
reverter (a:b) = reverter b ++ [a]