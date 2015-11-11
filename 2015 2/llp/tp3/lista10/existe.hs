existe :: Int -> [Int] -> Bool
existe _ [] = False
existe a (b:c)
	| a == b    = True
	| otherwise = existe a c