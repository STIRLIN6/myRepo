book :: (String, String, Int, Bool)
book = ("Emberi jatszmak", "Eric Berne", 1972, True)

getAuthor :: (String, String, Int, Bool) -> String
getAuthor (title, author, year, available) = author
--        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
--                     minta

getTitle :: (String, String, Int, Bool) -> String
getTitle (title, author, year, available) = title

-----------------

add :: (Int, Int) -> (Int, Int) -> (Int, Int)
add (nev1, szaml1) (nev2, szaml2) = (nev1 * szaml2 + nev2 * szaml1, szaml1 * szaml2)


mul :: (Int, Int) -> (Int, Int) -> (Int, Int)
mul (nev1, szaml1) (nev2, szaml2) = (nev1 * nev2, szaml1 * szaml2)


modDiv :: Int -> Int -> (Int, Int)
modDiv a b = (mod a b, div a b)


quadratic :: Double -> Double -> Double -> (Double, Double)
quadratic a b c = (((-b)+(b*b-4*a*c)**0.5)/(2*a), ((-b)-(b*b-4*a*c)**0.5)/(2*a))


matches :: (Int, Int) -> (Int, Int) -> Bool
matches (a, b) (c, d) = check1 || check2 || check3 || check4
    where
        check1 = a == c
        check2 = a == d
        check3 = b == c
        check4 = b == d


len :: (Double, Double) -> Double
len (a, b) = (a^2 + b^2)**0.5


stretch :: (Int, Int) -> Int -> (Int, Int)
stretch (a, b) c = (a*c, b*c)


distance :: (Double, Double) -> (Double, Double) -> Double
distance (a, b) (c, d) = ((a-c)^2 + (b-d)^2)**0.5