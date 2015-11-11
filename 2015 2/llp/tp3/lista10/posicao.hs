verifica :: Int -> [Int] -> Bool
verifica _ [] = False
verifica n (a:b)
	| n == a 	= True
	| otherwise = verifica n b

position :: Int -> [Int] -> Int
position _ [] = 0
position n (a:b)
	| n == a 	= 1
	| otherwise = 1 + position n b

posicao :: Int -> [Int] -> Int
posicao n l
	| verifica n l = position n l
	| otherwise    = 0