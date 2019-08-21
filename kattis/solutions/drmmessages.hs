--https://open.kattis.com/problems/drmmessages

import Data.Char

--For rotate
let2int :: Char -> Int
let2int c = ord c - ord 'A'

int2let :: Int -> Char
int2let i = chr (ord 'A' + i)

shift :: Int -> Char -> Char
shift by c = int2let (mod (let2int c + by) 26)

caesar :: Int -> String -> String
caesar by xs = [shift by x | x <- xs]

--For merge
shift2 :: String -> String -> String
shift2 [] [] = []
shift2 (a:as) (b:bs) = [shift (let2int b) a] ++ (shift2 as bs)

--DRM
divide :: Int -> String -> [String]
divide at xs = [(take at xs), (drop at xs)]

rotate :: String -> String
rotate xs = caesar by xs where
    by = sum (map let2int xs)

merge :: [String] -> String
merge [as, bs] = shift2 as bs


solve :: String -> String
solve xs = merge (map rotate (divide (div len 2) xs )) where
    len = length xs

main = do
    message <- getLine
    (putStrLn . solve) message