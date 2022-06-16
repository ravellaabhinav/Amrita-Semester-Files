database = [["Abhinav", "19", "2500"], ["Karthik", "20", "2000"]]

-- Format: [["name","age","salary"]]

-- Read all tweets
readEmpDets :: [[String]]
readEmpDets = database

-- Create a New Tweet into the list of all tweets
createEmp :: [String] -> [[String]]
createEmp newEmpArr = database ++ [newEmpArr]

-- Delete an em from the list of all tweets based on ID
deleteEmp :: String -> [[String]] -> [[String]]
deleteEmp empName [] = []
deleteEmp empName (x : xs)
  | x !! 0 == empName = xs
  | otherwise = x : (deleteEmp empName xs)

-- Update a emp on the list of all employees based on ID
updateEmp :: String -> [String] -> [[String]] -> [[String]]
updateEmp empName changeEmp [] = []
updateEmp empName changeEmp (x : xs)
  | x !! 0 == empName = changeEmp : xs
  | otherwise = x : (updateEmp empName changeEmp xs)

main = do
  putStrLn "==========Menu==========="
  putStrLn "1.  Read Employee"
  putStrLn "2.  Create Employee"
  putStrLn "3.  Delete Employee"
  putStrLn "4.  Update Employee"
  putStrLn "5.  Exit"
  putStrLn "========================="
  putStrLn "Enter your choice: "
  choice <- getLine
  case choice of
    "1" -> do
      putStrLn "Employee Details:"
      putStrLn $ show $ readEmpDets
      main
    "2" -> do
      putStrLn "Enter the Employee Details: "
      empDetails <- getLine
      let empArr = words empDetails
      putStrLn "Employee Details:"
      putStrLn $ show $ createEmp empArr
      main
    "3" -> do
      putStrLn "Enter the Employee name: "
      empName <- getLine
      putStrLn "Employee Details:"
      putStrLn $ show $ deleteEmp empName readEmpDets
      main
    "4" -> do
      putStrLn "Enter the Employee name: "
      empName <- getLine
      putStrLn "Enter the Employee Details: "
      empDetails <- getLine
      let empArr = words empDetails
      putStrLn "Employee Details:"
      putStrLn $ show $ updateEmp empName empArr readEmpDets
      main
    "5" -> putStrLn "Exiting..."
    _ -> do
      putStrLn "Invalid Choice"
      main
      