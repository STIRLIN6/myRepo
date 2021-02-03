-- data Maybe a = Just a | Nothing
safeDiv :: Int -> Int -> Maybe Int
safeDiv a 0 = Nothing
safeDiv a b = Just (a `div` b)

showMaybeInt :: Maybe Int -> String
showMaybeInt Nothing = "There is nothing here."
showMaybeInt (Just n) = "The result: " ++ show n

safeHead :: [a] -> Maybe a
safeHead (x:_) = Just x
safeHead []    = Nothing

data Privilege = Unprivileged | Admin
  deriving (Show, Eq)

data Cookie = LoggedOut | LoggedIn String Privilege
  deriving (Show, Eq)

type Database = [(String, String, Privilege)]
type Username = String
type Password = String

db = [("dumbledore","abracadabra",Unprivileged)
     , ("root", "secret", Admin)
     , ("bela", "alma", Unprivileged)
     ]

register :: Username -> Password -> Database -> Database
register user passw db_ = (user, passw, Unprivileged) : db_

getUser :: Username -> Database -> Maybe (Password, Privilege)
getUser user [] = Nothing
getUser user ((un,pw,pr):xs)
  | user == un = Just (pw, pr)
  | otherwise = getUser user xs

login :: Username -> Password -> Database -> Cookie
login user passw db_ = doLogin (getUser user db_)
  where
    doLogin :: Maybe (Password, Privilege) -> Cookie
    doLogin Nothing = LoggedOut
    doLogin (Just (p, priv)) | p == passw = LoggedIn user priv
                             | True = LoggedOut