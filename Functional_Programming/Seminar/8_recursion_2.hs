sum' :: [Int] -> Int
sum' [] = 0
sum' (x:[]) = x
sum' (x:xs) = x + sum' xs


last' :: [a] -> a
last' (x:[]) = x
last' (x:xs) = last' xs

and' :: [Bool] -> Bool
and' [] = True
and' (x:[]) = x
and' (x:xs) = x && and' xs

or' :: [Bool] -> Bool
or' [] = True
or' (x:[]) = x
or' (x:xs) = x || or' xs

replicate' :: Int -> Char -> [Char]
replicate' 1 a = [a]
replicate' n a = a:(replicate' (n-1) a)

format' :: Int -> [Char] -> [Char]
format' n a
  | n <= (length a) = a
  | otherwise = ' ':(format' (n-1) a)

insert' :: Int -> [Int] -> [Int]
insert' x [] = [x]
insert' x (a:as)
  | x <= a = [x,a]++as
  |otherwise = [a] ++ insert' x as

sort :: [Int] -> [Int]
sort [] = []
sort (a:as) = insert' a (sort as)

merge :: [Int] -> [Int] -> [Int]
merge [] a = a
merge a [] = a
merge (a:as) (b:bs)
  | a < b = a:(merge as (b:bs))
  | True  = b:(merge (a:as) bs)

--mergeSort :: [Int] -> [Int]
--mergeSort [] = []
--splitAt
--(5 `div` 2)