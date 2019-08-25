--https://open.kattis.com/problems/ladder

--h / sin(v) in radians 
solve :: Int -> Int -> Int
solve h v = ceiling ((fromIntegral h) / (sin ((fromIntegral v) * pi / 180)))

main = do
    h <- readLn
    v <- readLn
    print (solve h v)