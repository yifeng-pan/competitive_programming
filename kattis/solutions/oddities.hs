--https://open.kattis.com/problems/oddities

solve :: [Int] -> [String]
solve [] = []
solve (x:xs) 
    | even x = (show x ++ " is even"):(solve xs)
    | odd x = (show x ++ " is odd"):(solve xs)

readInput = (map read) . words
writeOutput = unlines

main = do
    _ <- getLine
    interact (writeOutput . solve . readInput)