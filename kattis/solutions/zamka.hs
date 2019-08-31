--https://open.kattis.com/problems/zamka

--unoptimized

sum_d :: Int -> Int
sum_d n
    | n < 10 = n
    | otherwise = n `mod` 10 + sum_d (n `div` 10)

find_n :: Int -> Int -> Int
find_n l x
    | sum_d l == x = l
    | otherwise = find_n (l + 1) x

find_m :: Int -> Int -> Int
find_m d x
    | sum_d d == x = d
    | otherwise = find_m (d - 1) x

main = do
    l <- readLn
    d <- readLn
    x <- readLn
    print(find_n l x)
    print(find_m d x)