--https://open.kattis.com/problems/cold

solve :: [Int] -> Int
solve xs = length [x | x <- xs, x < 0]

readInput = (map read) . words

main = interact (show . solve . readInput)