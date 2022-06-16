package main
 
import (
    "fmt"
    "strings"
)
 
func main() {
    str := "Amrita Vishwa Vidyapeetham"
    replace := "Vidyapeetham"
    newValue := "University"
    n := 2
    result := strings.Replace(str, replace, newValue, n)
    fmt.Println("Original String : ", str)
    fmt.Println("Result   String : ", result)
}