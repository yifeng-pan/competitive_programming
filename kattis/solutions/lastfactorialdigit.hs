--https://open.kattis.com/problems/lastfactorialdigit

factorial :: Integer -> Integer
factorial x
    | x == 0 = 1
    | otherwise = x * factorial (x - 1)

solve :: [Integer] -> [Integer]
solve [] = []
solve (x:xs) = mod (factorial x) 10 : solve xs

readInput = (map read) . words
writeOutput = unlines . (map show)

main = do
    _ <- getLine
    interact (writeOutput . solve . readInput)