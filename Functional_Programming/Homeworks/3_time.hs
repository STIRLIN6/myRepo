-- Idoeltolodas
shift :: (Int, Int) -> Int -> (Int, Int)
shift (a, b) c = (mod (a + div (b+c) 60) 24, mod (b+c) 60)

-- Korabbi idopont
isEarlier :: (Int, Int) -> (Int, Int) -> Bool
isEarlier (a, b) (c, d) = checkHour || checkMin
    where
        checkHour = a < c
        checkMin = a == c && d > b

-- Esemeny letrehozasa
createEvent :: (Int, Int) -> Int -> String -> ((Int, Int), (Int, Int), String)
createEvent (a, b) c d = ((a, b), (shift (a, b) c), d)