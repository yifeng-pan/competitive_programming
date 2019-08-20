--https://open.kattis.com/problems/spavanac

--bad

hm_to_m :: (Int, Int) -> Int
hm_to_m (h, m) = mod (60 * h + m) (60 * 24)

m_to_hm :: Int -> (Int, Int)
m_to_hm m = (mod ((div m 60) + 24) 24, mod m 60)

solve :: (Int, Int) -> (Int, Int)
solve (a, b) = m_to_hm (hm_to_m (a, b) - 45)

tuplify2 :: [Int] -> (Int, Int)
tuplify2 [x,y] = (x,y)

readInput = (map read) . words
writeOutput (a, b) = show a ++ " " ++ show b

main = interact (writeOutput . solve . tuplify2 . readInput)