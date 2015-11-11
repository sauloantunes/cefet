maior :: [Int] -> Int
maior []  = 0
maior [a] = a
maior (a:b)
	| a > (maior b) = a
	| otherwise 	= maior b
