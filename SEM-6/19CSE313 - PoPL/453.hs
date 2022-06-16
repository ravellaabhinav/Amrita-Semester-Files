-- Lab Evaluation -1
-- =================

-- Q1

deepreverse :: [[a]] -> [[a]]
deepreverse [] = []
deepreverse (x : xs) = deepreverse xs ++ [reverse x]

main = do
  print (deepreverse [[1, 2], [3, 4]])

-- Q2

function :: (a -> Bool) -> [a] -> [a]
function _ [] = []
function p (x : xs)
  | p x = x : function p xs
  | otherwise = function p xs

main = do
  print (function (> 3) [1, 2, 3, 4, 5, 6, 7])