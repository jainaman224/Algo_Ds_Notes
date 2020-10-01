package main

import (
    "fmt"
)

// Function to print nth fibonacci number
func FibonacciNumber (num int) int { 
    if num <= 1 {
        return num
    }    
    return FibonacciNumber(num - 1) + FibonacciNumber(num - 2)
} 

// Function to print fibonacci series  
func FibonacciSeries (num int) int { 
    var a int = 0
    var b int = 1  
    if num <= 1 {
        return 0
    }    

    for i := 1; i <= num; i++ {  
        fmt.Print(b, " ")
        var c int = a + b 
        a = b 
        b = c       
    } 
    return 0
} 

func main() { 
    var num int
    fmt.Scan(&num)
    fmt.Print("The fibonacci number at position ", num, "is ", FibonacciNumber(num))
    fmt.Print("\nFibonacci series:\n")
    FibonacciSeries(num)
}

/*
Input :
6
Output :
The fibonacci number at position 6 is 8
Fibonacci series:
1 1 2 3 5 8
*/
