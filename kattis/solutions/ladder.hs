--https://open.kattis.com/problems/ladder

--h / sin(v) in radians 
solve :: Int -> Int -> Int
solve h v = ceiling ((fromIntegral h) / (sin ((fromIntegral v) * pi / 180)))

main = do
    input <- getLine
    let hv = map read (words input)
    print (solve (hv!!0) (hv!!1)) 