--https://open.kattis.com/problems/simon

--Similar to https://open.kattis.com/problems/simonsays

solve :: String -> String
solve ('s':'i':'m':'o':'n':' ':'s':'a':'y':'s':' ':xs) = xs
solve _ = ""

main = interact (unlines . map solve . lines)