intercalar :: [Int] -> [Int] -> [Int]
intercalar [] a = a
intercalar a [] = a
intercalar (a:b) (c:d)
	| a < c     = [a] ++ intercalar b ([c] ++ d)
	| otherwise = [c] ++ intercalar ([a] ++ b) d