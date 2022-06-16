import Control.Concurrent
import Control.Monad
import System.IO

main = do
    m <- newEmptyMVar
    forkIO $ putMVar m 'x'
    r <- takeMVar m
    print r
