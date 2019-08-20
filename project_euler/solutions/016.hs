--https://projecteuler.net/problem=16
--Solution: 1366

sum_d :: Integer -> Integer
sum_d x
    | x == 0 = 0
    | otherwise = (mod x 10) + sum_d (div x 10)

main = print (sum_d (2^1000))