import Data.Maybe

--enum(eation)
data Day = Mon | Tue | Wed | Thu | Fri | Sat | Sun
--         ^^^   ^^^   ^^^   ^^^   ^^^   ^^^   ^^^
--         adatkonstruktorok
--   ^
--   nagy
  deriving Show

showDay :: Day -> String
showDay Mon = "Mon"
showDay Tue = "Tue"
---
showDay Sun = "Sun"

isWeekend :: Day -> Bool
isWeekend Sat = True
isWeekend Sun = True
isWeekend _   = False

nextDay :: Day -> Day
nextDay Mon = Tue
nextDay Tue = Wed
nextDay Wed = Thu
nextDay Thu = Fri
nextDay Fri = Sat
nextDay Sat = Sun
nextDay Sun = Mon

type Hour = Int
type Minute = Int 

--          T :: T -> Int -> Int -> Time
data Time = T Hour Minute
--          ^ adatkonstruktor
  deriving Show

data USTime = AM Hour Minute | PM Hour Minute
  deriving Show

showTime :: Time -> String
showTime (T h m) = show h ++ ":" ++ show m
--nem kell: showTime _ = "???"


-- Feladatok 6, 7, 10, 11

eqTime :: Time -> Time -> Bool
eqTime (T h m) (T g n) = h == g && m == n

isEarlier :: Time -> Time -> Bool
isEarlier (T h m) (T g n) = h < g || (h == g && m < n)

showUSTime :: USTime -> String
showUSTime (AM h m) = show h ++ "." ++ show m ++ " am"
showUSTime (PM h m) = show h ++ "." ++ show m ++ " pm"