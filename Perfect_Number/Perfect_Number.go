// Perfect number is a positive integer that is equal to the sum of its proper divisors.

package main

import (
    "fmt"
)

func main() {
    var num int
    fmt.Scan(&num)    
    var sum = 0
    
    // Calculating the sum of divisors
    for i := 1; i < num; i++ {
        if (num % i == 0) {
            sum = sum + i
        }
    }
    if (sum == num) {
        fmt.Print("It is a perfect number")
    } else {
        fmt.Print("It is not a perfect number") 
    }
}

// INPUT: 28 
// OUTPUT: It is a perfect number
