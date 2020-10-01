// Ugly numbers are numbers whose only prime factors are 2, 3 or 5.

package main

import(
    "fmt"
    "strconv"
)

// Function to check if a number is ugly or not 
func isUgly(num int) bool { 
    var x = true
    for (num != 1) {
        // To check if number is divisible by 5 or not
        if num % 5 == 0 { 
            num = num / 5  
        } else if num % 3 == 0 {  // To check if number is divisible by 3 or not
            num = num / 3  
        } else if num % 2 == 0 {  // To check if number is divisible by 2 or not
            num = num / 2  
        } else {
            x = false  
            break
        }
    }
    return x
}

// Function to get the nth ugly number
func NthUglyNumber(n int) int {
    var i = 1 
    var count = 1   // ugly number count  
    // Check for all integers untill ugly count  becomes n 
    for (n > count) {
        i = i + 1
        if ( isUgly(i) ) {
            count = count + 1 
        }
    }
    return i
}

func main() {
    var number = 100
    var no = NthUglyNumber(number) 
    var number_str = strconv.Itoa(number)
    var no_str = strconv.Itoa(no)
    fmt.Print("The Ugly no. at position " + number_str + " is " + no_str )
}

/*
Input: number : 100
Output : The Ugly no. at position 100 is 1536
*/
