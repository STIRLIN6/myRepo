isIdentifierStart :: Char -> Bool
isIdentifierStart a = elem a ('_':['a'..'z'])

isIdentifierPart :: Char -> Bool
isIdentifierPart a = elem a ('_':['a'..'z'] ++ ['A'..'Z'] ++ ['0'..'9'])

isReserved :: String -> Bool
isReserved i = elem i ["if", "then", "else", "module", "import"]

isValid :: String -> Bool
isValid "" = False
isValid (x:xs) = (isIdentifierStart x) && ((length [t | t <- xs, isIdentifierPart t]) == (length xs)) && not (isReserved (x:xs))
