--https://open.kattis.com/problems/bijele

correct = [1, 1, 2, 2, 2, 8] ++ repeat 0

minus :: [Int] -> [Int] -> [Int]
minus [] xs = []
minus xs [] = []
minus (a:as) (b:bs) = (a - b):minus as bs

solve :: [Int] -> [Int]
solve xs = minus correct xs

readInput = (map read) . words
writeOutput = unlines . (map show)

main = interact (writeOutput . solve . readInput)