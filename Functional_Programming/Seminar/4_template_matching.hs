not' :: Bool -> Bool
not' True  = False
not' False = True


f :: Int -> Int
f 0 = 1
f 1 = 3
--f n = n

isFruit :: String -> Bool
isFruit "apple" = True
isFruit "grape" = True
isFruit _       = False

and' :: Bool -> Bool -> Bool
and' True True = True
and' _    _    = False

or' :: Bool -> Bool -> Bool
or' False False = False
or' _     _     = True

xor :: Bool -> Bool -> Bool
xor a b
   | a == b = False
   | otherwise = True -- AZ ÁDERVÁJZ MAGA A TRÚ!

add2 :: Int -> Int -> (Int, Int)
add2 0 0 = (0,0)
add2 0 1 = (1,0)
add2 1 0 = (1,0)
add2 1 1 = (0,1)

paren :: Char -> Char -> Bool
paren '(' ')' = True
paren '[' ']' = True
paren '{' '}' = True
paren a b = False