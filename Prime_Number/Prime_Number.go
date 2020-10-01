package main

import (
    "fmt"
    "math"
)

func prime(num int, i int) int {
    
    if (num == 1) {
        return 0
    }
    // Base cases 
    if (i <= 1) {
        return 1 
    }    
    // Checking if i is a divisor or not
    if (num % i == 0) {
        return 0
    }
      
    // Calling recursive function
    return prime(num, i - 2)
}   

func main() {    
    var num int
    fmt.Scan(&num)
    
    if (num == 2) {
        fmt.Print("It is a prime number") 
    }
    if (num % 2 == 0) {
        fmt.Print("It is not a prime number")
    }
    
    var ans = prime(num, math.Sqrt(num))
    if (ans == 1) {
        fmt.Print("It is a prime number")
    } else {
        fmt.Print("It is not a prime number")
    }
}


// Input: 29
// Output: It is a prime number 
