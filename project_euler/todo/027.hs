--https://projecteuler.net/problem=27
--Solution: 

--very bad
--and too slow aswell

divisors :: Integer -> [Integer]
divisors x = [a | a <- [1 .. x], mod x a == 0]

primality :: Integer -> Bool
primality x
    | x <= 1 = False
    | otherwise = divisors x == [1, x]

quadratic_test :: Integer -> Integer -> Integer -> Bool
quadratic_test a b n = primality (n^2 + a*n + b)

max_n_helper :: Integer -> Integer -> Integer -> Integer
max_n_helper a b n
    | quadratic_test a b n = max_n_helper a b (n + 1)
    | otherwise = n - 1

max_n :: (Int, Int) -> Integer
max_n (a, b) = max_n_helper (toInteger a) (toInteger b) 0

low = -100
high = 100

check = [(a, b) | a <- [low .. high], b <- [0 .. high], primality (toInteger b)]
solutions = zip check (map max_n check)
solution = maximum (map max_n check)

main = print (solution)