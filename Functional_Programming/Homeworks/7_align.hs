align' :: Int -> String -> String
align' 0 a = a
align' x a = ' ':(align' (x-1) a)

align :: Int -> String -> String
align x a
  | x < (length a) = a
  | otherwise = align' (x-(length a)) a