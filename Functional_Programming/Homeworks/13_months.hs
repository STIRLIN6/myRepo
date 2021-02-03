data Month = Jan | Feb | Mar |
             Apr | May | Jun |
             Jul | Aug | Sep |
             Oct | Nov | Dec
  deriving (Show, Eq)

type Year = Int

isLeap :: Year -> Bool
isLeap y
  | y `mod` 400 == 0 = True
  | y `mod` 100 == 0 = False
  | y `mod` 4   == 0 = True
  | otherwise    = False

numberOfDays :: Year -> Month -> Int
numberOfDays y m
  | m == Jan = 31
  | m == Feb && isLeap y = 29
  | m == Feb && not (isLeap y) = 28
  | m == Mar = 31
  | m == Apr = 30
  | m == May = 31
  | m == Jun = 30
  | m == Jul = 31
  | m == Aug = 31
  | m == Sep = 30
  | m == Oct = 31
  | m == Nov = 30
  | m == Dec = 31