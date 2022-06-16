--1
--a
rember y [] = []
rember y (x:xs) | x==y = xs
               | otherwise = x : rember y xs
--b
remberall y [] = []
remberall y (x:xs) | x==y = remberall y xs
               | otherwise = x : remberall y xs


--2
--a
firsts x = [head xs | xs<-x]
--b
seconds x = [head (tail xs) | xs<-x]


--3

--insertRight

insertRight y a [] = []
insertRight y a (x:xs) | x==y = x : a : xs
                       | otherwise = x : insertRight y a xs

--insertRightall

insertRightall y a [] = []
insertRightall y a (x:xs) | x==y = x : a : insertRightall y a xs
                          | otherwise = x : insertRightall y a xs

--insertLeft
insertLeft y a [] = []
insertLeft y a (x:xs) | x==y = a : x : xs
                      | otherwise = x : insertLeft y a xs

--insertLeftall
insertLeftall y a [] = []
insertLeftall y a (x:xs) | x==y = a : x : insertLeftall y a xs
                         | otherwise = x : insertLeftall y a xs

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


--6
element x []=False
element x (y:ys) | elem x y = True
               | otherwise = (element x ys)