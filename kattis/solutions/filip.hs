--https://open.kattis.com/problems/filip

flip_int :: Int -> Int
flip_int n
    | n < 10 = n
    | otherwise = read ((show n') ++ (show . flip_int $ n''))
    where
        n' = n `mod` 10
        n'' = n `div` 10

main = do
    input <- getLine
    let l = map read (words input)
    let a = l!!0
    let b = l!!1
    print(max (flip_int a) (flip_int b))