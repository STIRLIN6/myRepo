-- [fst x ^ snd x | x <- zip [1..5] [1..3]]

isPrime :: Int -> Bool
isPrime 0 = False
isPrime 1 = False
isPrime a = [x | x <- [2..a-1], mod a x == 0] == []

primes = [x | x <- [2..], isPrime x == True]

allPositive :: [Int] -> Bool
allPositive a = null [x | x <- a, x <= 0]

dominoes = [(x,y) | x <- [0..6], y <- [x..6]]

--5* szunet

alphabet = [n | n <- zip [0..] ['a'..'z']]

everyThird = [a | a <- ['c','f'..'z']]