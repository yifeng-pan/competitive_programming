--https://open.kattis.com/problems/nastyhacks

-- not the best way
-- solves three inputs at a time
solve :: [Int] -> String
solve rec
    | length rec < 3 = ""
    | w > 0 = "advertise" ++ r
    | w == 0 = "does not matter" ++ r
    | w < 0 = "do not advertise" ++ r
    where
        w = rec!!1 - rec!!0 - rec!!2
        r = "\n" ++ (solve . tail . tail . tail $ rec)

main = do
    _ <- getLine
    interact (solve . (map read) . words)