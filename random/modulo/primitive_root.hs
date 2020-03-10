-- Returns the binary reprensation of n.
binary :: Int -> [Bool]
binary n
    | n <= 0 = []
    | otherwise = [n `mod` 2 == 1] ++ binary (n `div` 2)

-- Generates r for the modulo algorithm.
r_next :: Int -> Int -> Bool -> Int -> Int
r_next r a b n 
    | b = (r * r * a) `mod` n
    | otherwise = (r * r) `mod` n


-- Generates [r] for the modulo algorithm.
gen_rs :: Int -> Int -> [Bool] -> Int -> [Int]
gen_rs r a bs n 
    | bs == [] = []
    | otherwise = [r] ++ gen_rs r' a bs' n
        where 
            bs' = drop 1 bs
            r' = r_next r a (head bs') n

-- Compute $a^m (mod n)$, where $a$ in an integer, and $n,m$ are naturals.
e_mod :: Int -> Int -> Int -> Int
e_mod a m n = last (gen_rs a a bs n)
    where 
        bs = reverse (binary m)

-- If a list contains duplicate elements
unique :: Eq a => [a] -> Bool
unique as = dupes == []
    where
        l = length as - 1
        dupes = [x | x <- [0..l], y <- [x+1..l], as!!x == as!!y]

-- Test if g is a primitive root of n, assuming n is prime
p_root :: Int -> Int -> Bool
p_root g n = unique [e_mod g i n | i <- [1..n-1]]

-- Returns the primitive roots of n, assuming n is prime
p_roots :: Int -> [Int]
p_roots n = [g | g <- [1..n-1], p_root g n]