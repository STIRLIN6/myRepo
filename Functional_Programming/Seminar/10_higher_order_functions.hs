import Data.Char

map' :: (a -> b) -> [a] -> [b]
map' f []     = []
map' f (a:as) = (f a) : (map' f as)

square :: Int -> Int
square x = x * x

filter' :: (a -> Bool) -> [a] -> [a]
filter' _ []     = []
filter' f (a:as)
  | f a = a : (filter' f as)
  | otherwise = (filter' f as)

upperToLower :: [Char] -> [Char]
upperToLower "" = ""
upperToLower a = map' toLower (filter' isUpper a)

all' :: (a -> Bool) -> [a] -> Bool
all' _ [] = True
all' f (a:as)
  | f a = all' f as
  | True = False

any' :: (a -> Bool) -> [a] -> Bool
any' _ [] = False
any' f (a:as)
  | f a = True
  | True = any' f as