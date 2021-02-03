import Data.Char

-- Eq: Int, Char, Bool, Double
-- Ord: >, <, >=, <=
-- Show: show

takeWhile' :: (a -> Bool) -> [a] -> [a]
takeWhile' f [] = []
takeWhile' f (a:as)
  | f a = a : takeWhile' f as
  | otherwise = []

dropWhile' :: (a -> Bool) -> [a] -> [a]
dropWhile' f [] = []
dropWhile' f (a:as)
  | f a       = dropWhile' f as
  | otherwise = (a:as)

dropSpaces :: [Char] -> [Char]
dropSpaces (' ':as) = dropSpaces as
dropSpaces a = a

dropBack :: [Char] -> [Char]
dropBack a
  | last a == ' ' = dropBack(init a)
  | otherwise = a

trim :: [Char] -> [Char]
trim = dropSpaces . dropBack

monogram :: [Char] -> [Char]
monogram a = trim (concat(map ((++". ") . (\a -> [a])) (map (toUpper . head) (words a))))