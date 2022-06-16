{-
Write and execute a haskell program to print at least three addition tables using threads.
Demonstrate Max, Min and Norm thread priorities in your code.
-}

import Control.Concurrent
import Control.Monad
import System.IO
import System.Environment
import System.Random

-- | The main function.
main = do
  args <- getArgs
  case args of
    [n] -> do
      let n' = read n :: Int
      putStrLn $ "Generating " ++ show n' ++ " tables."
      tables <- mapM (\_ -> getAddTable) [1..n']
      let tables' = map (\x -> "  " ++ x) tables
      mapM_ putStrLn tables'
      mapM_ (\x -> putStrLn $ "  " ++ x) $ map (\x -> "  " ++ x) $ concat tables'
    _   -> do
      putStrLn "Usage: ./addtables <n>"
      exitFailure

-- | Generate an addition table.
getAddTable :: IO String
getAddTable = do
  (a, b) <- genPair
  let c = a + b
  return $ show a ++ " + " ++ show b ++ " = " ++ show c

-- | Generate a pair of random numbers.
genPair :: IO (Int, Int)
genPair = do
  a <- randomRIO (1, 9)
  b <- randomRIO (1, 9)
  return (a, b)