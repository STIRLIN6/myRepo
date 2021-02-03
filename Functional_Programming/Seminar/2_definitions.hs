n :: Int
n = 2

s :: String
s = "hello"

even' :: Int -> Bool
even' n = mod n 2 == 0
odd' :: Int -> Bool
odd' m = even' m == not True
-- odd' m = not (even' m)
-- odd' m = mod m 2 /= 0

divides :: Int -> Int -> Bool
divides b a  = mod a b == 0

area :: Int -> Int -> Int
area x y = x * y

triangleSides :: Int -> Int -> Int -> Bool
triangleSides a b c = aCheck && bCheck && cCheck
    where
        aCheck = a < b + c
        bCheck = b < a + c
        cCheck = c < b + a

pythagoreanTriple :: Int -> Int -> Int -> Bool
pythagoreanTriple a b c = aLong || bLong || cLong
    where
        aLong = a^2 == b^2 + c^2
        bLong = b^2 == a^2 + c^2
        cLong = c^2 == b^2 + a^2