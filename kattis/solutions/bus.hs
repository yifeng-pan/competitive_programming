--https://open.kattis.com/problems/bus

an :: Int -> Int
an x
    | x <= 1 = 1
    | otherwise = 2 * an (x - 1) + 1

solve :: [Int] -> [Int]
solve xs = map an xs

readInput = (map read) . words
writeOutput = unlines . (map show)

main = do
    _ <- getLine
    interact (writeOutput . solve . readInput)