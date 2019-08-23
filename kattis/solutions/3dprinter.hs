--https://open.kattis.com/problems/3dprinter

toDouble :: Int -> Double
toDouble x = (fromInteger . toInteger) x :: Double

solve :: Int -> Int
solve x = (ceiling (logBase 2 (toDouble x))) + 1

main = do
    n <- readLn
    (print . solve) n