data Dir = West | North | East | South
  deriving (Show, Eq)

type Position = (Int, Int)

type Snake = (Dir, [Position], Int)

data Instruction = Turn Dir | Move

isOppositeDir :: Dir -> Dir -> Bool
isOppositeDir East  West  = True
isOppositeDir West  East  = True
isOppositeDir North South = True
isOppositeDir South North = True
isOppositeDir _     _     = False

nextPos :: Dir -> (Int, Int) -> (Int, Int)
nextPos West  (x, y) = (x-1, y)
nextPos East  (x, y) = (x+1, y)
nextPos North (x, y) = (x, y+1)
nextPos South (x, y) = (x, y-1)

doInstruction :: Instruction -> Snake -> Snake
doInstruction (Turn East) (d, pos, x)
  | isOppositeDir East  d = (d,    pos, x)
  | otherwise             = (East, pos, x)

doInstruction (Turn West)  (d, pos, x)
  | isOppositeDir West  d = (d,    pos, x)
  | otherwise             = (West, pos, x)

doInstruction (Turn North) (d, pos, x)
  | isOppositeDir North d = (d,     pos, x)
  | otherwise             = (North, pos, x)

doInstruction (Turn South) (d, pos, x)
  | isOppositeDir South d = (d,     pos, x)
  | otherwise             = (South, pos, x)

doInstruction Move         (d, pos, x) = (d, (nextPos d (head pos)):[ a | a <- pos, not (a == last pos)], x)