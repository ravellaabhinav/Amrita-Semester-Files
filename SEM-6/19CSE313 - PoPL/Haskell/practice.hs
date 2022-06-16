--4
--a
replace y a [] = []
replace y a (x:xs) | x==y = a : xs
                   | otherwise = x : replace y a xs
--b
replaceAll y a [] = []
replaceAll y a (x:xs) | x==y = a : replaceAll y a xs
                      | otherwise = x : replaceAll y a xs

--5
replaceEitherOr y a b [] = []
replaceEitherOr y a b (x:xs) | (x==y || x==a) = b : xs
                             | otherwise = x : replaceEitherOr y a b xs