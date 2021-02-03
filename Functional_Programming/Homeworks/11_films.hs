type Movie = (String, Double, String)
movies :: [Movie]
movies = [ ("Green Book", 8.3, "Peter Farrelly"),
           ("Inception", 8.8, "Christopher Nolan"),
           ("Incredibles 2", 7.7, "Brad Bird"),
           ("The Dark Knight", 9.0, "Christopher Nolan") ]

imdbAtLeast :: Double -> (String, Double, String) -> Bool
imdbAtLeast n (a, b, c) = n <= b

director :: String -> (String, Double, String) -> Bool
director d (a, b, c) = d == c

and_ :: ((String, Double, String) -> Bool) -> ((String, Double, String) -> Bool) -> (String, Double, String) -> Bool
and_ f1 f2 (a, b, c) = f1 (a, b, c) && f2 (a, b, c)

or_ :: ((String, Double, String) -> Bool) -> ((String, Double, String) -> Bool) -> (String, Double, String) -> Bool
or_ f1 f2 (a, b, c) = f1 (a, b, c) || f2 (a, b, c)

search :: ((String, Double, String) -> Bool) -> [(String, Double, String)] -> [(String, Double, String)]
search f xs = [a | a <- xs, f a]