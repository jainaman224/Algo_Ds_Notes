/*Perfect Square String is a string in which sum of ASCII value of all characters is a perfect square.*/ 

package main

import (
    "fmt"
    "math"
)

func perfectSquareString(str string) float64 { 
    var sum float64 = 0 
      
    // Length of the string 
    var length int = len(str)
          
    // Calculating sum of the string by converting it in its ASCII value
    for i := 0; i < length; i++ {
        sum = sum + float64(str[i])
    }    
      
    // Calculating square root 
    var squareRoot float64 = math.Sqrt(sum)
      
    // Checking if square root is an integer 
    return squareRoot - math.Floor(squareRoot)
} 

func main() { 
    var str string
    fmt.Scanf("%s", &str)
      
    if (perfectSquareString(str) == 0) {
        fmt.Printf("YES") 
    } else {
        fmt.Printf("NO")
    }
}

/*
INPUT :
Q
OUTPUT :
YES
Becasue ASCII value of Q is 81 which is a perfect square
*/
