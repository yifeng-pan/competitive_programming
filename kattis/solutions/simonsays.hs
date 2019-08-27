--https://open.kattis.com/problems/simonsays

--Similar to https://open.kattis.com/problems/simon

import Data.Maybe

solve :: String -> Maybe String
solve ('S':'i':'m':'o':'n':' ':'s':'a':'y':'s':' ':xs) = Just xs
solve _ = Nothing

main = interact (unlines . catMaybes . map solve . lines)