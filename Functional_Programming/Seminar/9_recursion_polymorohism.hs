take' :: Int -> [a] -> [a]
take' _ [] = []
take' 0 a = []
take' n (x:xs) = x:(take' (n-1) xs)

drop' :: Int -> [a] -> [a]
drop' _ [] = []
drop' 0 a = a
drop' n (x:xs) = drop (n-1) xs

langAndRegion :: [Char] -> ([Char],[Char])
langAndRegion h = (take' 2 h, drop' 3 h)

zip' :: [a] -> [b] -> [(a,b)]
zip' _ [] = []
zip' [] _ = []
zip' (a:as) (b:bs) = (a,b):(zip' as bs)

unzip' :: [(a,b)] -> ([a], [b])
unzip' [a] = ([fst a], [snd a])
unzip' ((a,b):xs) = (a:(fst (unzip' xs)), b:(snd (unzip' xs)))

--empty :: [a] -> [Int]
