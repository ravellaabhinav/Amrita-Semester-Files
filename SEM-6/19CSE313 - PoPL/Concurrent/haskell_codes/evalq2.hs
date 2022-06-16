import Control.Concurrent
import Control.Monad
import System.IO



main = do
hSetBuffering stdout NoBuffering
forkIO (replicateM_ 100000 (putChar 'A'))
hSetBuffering stdout NoBuffering
forkIO (replicateM_ 1 (putChar 'B'))