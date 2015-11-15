trocar :: Int -> [Int]
trocar 0 = []
trocar n
	| n >= 100 = trocar (n-100) ++ [100]
	| n >= 50  = trocar (n-50)  ++ [50]
	| n >= 10  = trocar (n-10)  ++ [10]
	| n >= 5   = trocar (n-5)   ++ [5]
	| n >= 1   = trocar (n-1)   ++ [1]