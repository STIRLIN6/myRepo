table :: [(Char, Char)]
table = zip (' ':['a'..'z']) (' ':['d'..'z']++['a'..'c'])

shift :: [(Char, Char)]-> Char -> Char
shift t b  = [snd x | x <- t, fst x == b] !! 0

encrypt :: [(Char, Char)] -> [Char] -> [Char]
encrypt t a = [shift t b | b <- a]