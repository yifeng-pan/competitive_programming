--https://open.kattis.com/problems/3dprinter

solve :: Int -> Int
solve x = (ceiling (logBase 2 (fromIntegral x))) + 1

main = do
    n <- readLn
    (print . solve) n