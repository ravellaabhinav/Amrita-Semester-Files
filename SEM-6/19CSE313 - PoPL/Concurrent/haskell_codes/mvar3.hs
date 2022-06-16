import Control.Concurrent
import Control.Monad
import System.IO

main = do
    m <- newEmptyMVar
    takeMVar m
    
