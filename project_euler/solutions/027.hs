--https://projecteuler.net/problem=27
--Solution: -59231

--very bad
--and very slow
--takes a minute

import Data.List

divisors :: Integer -> [Integer]
divisors x = [a | a <- [1 .. x], mod x a == 0]

primality :: Integer -> Bool
primality x
    | x <= 1 = False
    | otherwise = divisors x == [1, x]

quadratic_test :: Integer -> Integer -> Integer -> Bool
quadratic_test a b x = primality (x^2 + a*x + b)

max_n_helper :: Integer -> Integer -> Integer -> Integer
max_n_helper a b n
    | quadratic_test a b n = max_n_helper a b (n + 1)
    | otherwise = n - 1

max_n :: (Int, Int) -> Integer
max_n (a, b) = max_n_helper (toInteger a) (toInteger b) 1

alow = -1000
ahigh = 1000
bhigh = 1000

check = [(a, b) | b <- [0 .. bhigh], a <- [alow .. ahigh], mod a 2 == 1, primality (toInteger b)]
solutions = zip (map max_n check) check
solution = maximum solutions

ab = solutions!!((findIndices (== solution) solutions)!!0)

p = ((snd . snd) ab) * ((fst . snd) ab)

main = print p

--Idea for faster algorithm:
--Generate a list of prime numbers.
--use polynomial interpolation on each index and check for the longest second degree polynomial
--relative to the element on the index
--Altho this is overkill