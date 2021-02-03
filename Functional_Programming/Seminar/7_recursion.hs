fact :: Integer -> Integer
fact 0 = 1
fact n = n * fact (n-1)

fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib n = fib (n-2) + fib (n-1)

-- gyors
memoized_fib :: Int -> Integer
memoized_fib = (map fib [0 ..] !!)
   where fib 0 = 0
         fib 1 = 1
         fib n = memoized_fib (n-2) + memoized_fib (n-1)

pow :: Integer -> Integer -> Integer
pow a 0 = 1
pow a 1 = a
pow a n = a * (pow a (n-1))

range :: Int -> Int -> [Int]
range a b | a == b = [b]
range a b | a < b  = a:(range (a+1) b)
range a b | a > b  = a:(range (a-1) b)

length' :: [a] -> Int
length' [] = 0
length' (x:xs) = 1 + length' xs

minimum' :: [Int] -> Int
minimum' [n] = n
minimum' (n:ns)
  | n < minimum' ns = n
  | otherwise       = minimum' ns
