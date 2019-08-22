--Generates a list of exact number of digits.
--The nth index of the list contains the number of digits n! has

factorial :: Integer -> Integer
factorial n 
    | n <= 0 = 1
    | otherwise = n * factorial (n - 1)

--More efficient way of generating a list of factorials from n to 1
gen_factorial :: Integer -> [Integer]
gen_factorial n 
    | n <= 0 = [1]
    | otherwise = [n * ns!!0] ++ ns
        where ns = gen_factorial (n - 1)

--Positive Integers only
--Counts number of digits
digits :: Integer -> Int
digits n = (length . show) n

--This is much slower
-- digits n 
--     | n >= 1000000000 = 9 + digits (div n 1000000000)
--     | n >= 1000000 = 6 + digits (div n 1000000)
--     | n >= 1000 = 3 + digits (div n 1000)
--     | n >= 10 = 1 + digits (div n 10)
--     | otherwise = 1

-- For testing
-- Shows some samples of n! from 1 to n
sample :: Int -> IO ()
sample n = do 
    if n > 0
        then sample (n - 1)
        else return ()
    putStr (show n ++ ": ")
    putStr ("Length = " ++ ((show . digits . factorial . toInteger) n))
    --putStr (", Change in Length = " ++ (show dif)) 
    putStr (", n! = " ++ ((show . factorial . toInteger) n))
    --putStr (", " ++ ((show . factorial . toInteger) n))
    putStrLn ""
        where dif = ((digits . factorial . toInteger) n) - ((digits . factorial . toInteger) (n - 1))

main = do
    --First 1000 is good enough.
    --For n > 1000, the log approach is sufficient
    let size = 1000

    --To test algorithm efficiency
    --let size = 100 * 1000

    let facts = (reverse . gen_factorial) size
    --print facts
    --print (facts!!201000)

    let dfacts = map digits facts
    --print dfacts

    writeFile "dfacts.txt" (show dfacts)
    putStr "Done"

    --sample 1000