--https://open.kattis.com/problems/planina

edge_points :: Int -> Int
edge_points n
    | n == 0 = 2
    | otherwise = r + r - 1
    where
        r = edge_points (n - 1)

main = do
    n <- readLn
    print((edge_points n) ^ 2)