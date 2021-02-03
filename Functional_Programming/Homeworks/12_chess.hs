import Data.List

rook :: (Int, Int) -> [(Int, Int)]
rook (a, b) = [ (y, b) | y <- [0..7], not (y == a) ] ++ [ (a, x) | x <- [0..7], not (x == b) ]

oneTwo :: [Int]
oneTwo = [1,2,(-1),(-2)]

knight :: (Int, Int) -> [(Int, Int)]
knight (a, b) = [ (a+x, b+y) | x <- oneTwo, y <- oneTwo, (abs x)+(abs y) == 3, a+x < 8, a+x >= 0, b+y < 8, b+y >=0]

attacks :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> Bool
attacks f (a, b) [] = False
attacks f (a, b) x = not ([ y | y <- x, z <- (f (a, b)), z == y] == [])

--moves :: ((Int, Int) -> [(Int, Int)]) -> (Int, Int) -> [(Int, Int)] -> [[(Int, Int)]]
--moves f (a, b) (x:xs) = [ [ n | n <- (a, b) ++ xs] | ]