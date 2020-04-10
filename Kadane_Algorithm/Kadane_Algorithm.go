// Go program to print largest contiguous array sum

package main

import "fmt"

func KAlgo(a []int, n int) int {
    var max int
    var check_max int
    max = 0
    check_max = 0
    
    for i := 0; i < n; i++ {
        check_max = check_max + a[i]

        // Minimum sum will be 0
        if check_max < 0 { 
            check_max = 0
        }
        if max < check_max {
            max = check_max
        }
    }
    return max
}

//Main Function
func main() {
    var n int
    fmt.Print("Enter number of Elements ")
    fmt.Scan(&n)
    ope(n)
}

func ope(n int) {
    fmt.Print("\nEnter Elements ")
    a := make([]int, n)
    
    // Array input
    for i := 0; i < n; i++ { 
        fmt.Scan(&a[i])
    }
    
    var output int

    // Function Calling for the Algo
    output = KAlgo(a, n) 
    fmt.Println("\nSum of the sub array: ", output)
}

/*
Enter Number of Elements 6
Enter Elements 2 -4 -5 -6 8 10
Sum of the sub array: 18
*/
