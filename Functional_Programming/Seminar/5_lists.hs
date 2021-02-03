import Data.Char -- toUpper


headInt :: [Int] -> Int
headInt (x:xs) = x

tailInt :: [Int] -> [Int]
tailInt (x:xs) = xs

isSingleton :: [Int] -> Bool
isSingleton []     = False
isSingleton (x:[]) = True
isSingleton _      = False

hasTwoElements :: [Int] -> Bool
hasTwoElements []       = False
hasTwoElements (x:[])   = False
hasTwoElements (x:y:[]) = True
hasTwoElements _        = False

nullInt :: [Int] -> Bool
nullInt [] = True
nullInt _  = False

toUpperFirst :: [Char] -> [Char]
toUpperFirst [] = []
toUpperFirst (x:xs) = (toUpper x) : xs

isLetter' :: Char -> Bool
isLetter' a = elem a (['a'..'z'] ++ ['A'..'Z'])

isDigit' :: Char -> Bool
isDigit' i = elem i (['0'..'9'])

mountain :: Int -> [Int]
mountain n = [1..n] ++ [(n-1),(n-2)..1]

divisors :: Int -> [Int]
divisors n = [x | x <- [1..n], n `mod` x == 0]

powersOfTwo = [2^x | x <- [0..]]

time = [(o,p) | o <- [0..23], p <- [0..59]]