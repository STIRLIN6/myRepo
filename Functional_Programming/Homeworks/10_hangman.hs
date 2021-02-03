import Data.Char

abc :: [Char]
abc = ['A'..'Z']

isValidLetter :: Char -> [Char] -> Bool
isValidLetter c ls = ((toUpper c) `elem` ls) || ((toLower c) `elem` ls)

startState :: [Char] -> [Char] -> ([Char],[Char],[Char])
startState ls a
  | ([ x | x <- a, not (isValidLetter x ls) && not (x == ' ')] == []) = ([ toUpper b | b <- a ], [], [])
  | otherwise = error "startState: the riddle contains invalid letters"  --maga a trú

guessLetter :: [Char] -> Char -> ([Char],[Char],[Char]) -> ([Char],[Char],[Char])
guessLetter ls a (x, y, z)
  | not ((toUpper a) `elem` ls || (toLower a) `elem` ls) = error "Invalid letter"
  | (toUpper a) `elem` (y++z) = (x, y, z)
  | (toUpper a) `elem` x = (x, (toUpper a):y, z)
  | not ((toUpper a) `elem` x) = (x, y, (toUpper a):z)