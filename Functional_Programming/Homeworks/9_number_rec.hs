import Data.Char

d8  = ['0'..'7']
d10 = ['0'..'9']
d16 = ['0'..'9'] ++ ['a'..'f'] ++ ['A'..'F']
isDigitOfBase :: Char -> Int -> Bool
isDigitOfBase n d
  | d == 8  = elem n d8
  | d == 10 = elem n d10
  | d == 16 = elem n d16
  | otherwise = error "isDigitOfBase: Invalid base."

parseInteger :: Int -> [Char] -> Int
parseInteger _ "" = 0
parseInteger d (a:as)
  | not (isDigitOfBase a d) = error "parseInteger: Invalid digit."
  | otherwise = (digitToInt (a)) * (d^(length as)) + (parseInteger d as)

parseLiteral :: [Char] -> Int
parseLiteral "" = 0
parseLiteral (x:[]) = digitToInt x
parseLiteral (x:y:xs)
  | (x:y:xs) == ('0':'x':xs) = parseInteger 16 xs
  | (x:y:xs) == ('0':'X':xs) = parseInteger 16 xs
  | (x:y:xs) == ('0':'o':xs) = parseInteger 8  xs
  | (x:y:xs) == ('0':'O':xs) = parseInteger 8  xs
  | otherwise = parseInteger 10 (x:y:xs)