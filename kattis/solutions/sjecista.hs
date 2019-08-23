--https://open.kattis.com/problems/sjecista

factorial :: Integer -> Integer
factorial n
    | n <= 0 = 1
    | otherwise = n * factorial (n - 1)

choose :: Integer -> Integer -> Integer
choose n k = (factorial n) `div` (factorial k * factorial (n-k))

-- Each intersection is connected to 4 points
-- How many ways are there to choose 4 points from n
main = do
    n <- readLn
    print (choose n 4)