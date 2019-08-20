--https://open.kattis.com/problems/isithalloween

solve :: String -> String
solve str
    | str == "OCT 31" = "yup"
    | str == "DEC 25" = "yup"
    | otherwise = "nope"

main = do
    input <- getLine
    putStr (solve input)