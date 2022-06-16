{-
Write a haskell concurrent program that accepts numbers from the user and prints a userdefined multiplication table in the same order. For example, the following shall be
an example session.
-}

import Control.Concurrent
import Control.Concurrent.STM
import Control.Monad(forever)
import Control.Monad.IO.Class

main :: IO ()
main = do
  putStrLn "Enter a number: "
  input <- getLine
  let num = read input :: Int
  putStrLn $ "Multiplication table of " ++ show num ++ ":"
  printTable num

printTable :: Int -> IO ()
printTable num = do
  let max = 10 :: Int
  let table = [1..max] :: [Int]
  let result = map (* num) table
  mapM_ print result
  threadDelay 500000  
