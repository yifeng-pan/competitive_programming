--https://projecteuler.net/problem=20
--Solution: 648

factorial :: Integer -> Integer
factorial x
    | x == 0 = 1
    | otherwise = x * factorial (x - 1)

sum_d :: Integer -> Integer
sum_d x
    | x == 0 = 0
    | otherwise = (mod x 10) + sum_d (div x 10)

main = print (sum_d (factorial 100))