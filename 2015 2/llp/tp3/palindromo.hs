-- Exercicio 9
{-
ultimo :: [Int] -> Int
ultimo [] = error "Lista vazia"
ultimo [x] = x
ultimo (a:b)
	| b == [] = a
	| otherwise = ultimo b

menosUlimo :: [Int] -> [Int]
menosUlimo [_] = []
menosUlimo (a:	b) = [a] ++ menosUlimo b

palindromo :: [Int] -> Bool
palindromo [] = True
palindromo [_] = True

palindromo (a:b)
	| a == ultimo b = palindromo(menosUlimo b)
	| otherwise  = False
-}

-- Segunda forma

rev :: [Int] -> [Int]
rev [] = []
rev (a:b) = rev b ++ [a]

palindromo :: [Int] -> Bool
palindromo a = a == rev a