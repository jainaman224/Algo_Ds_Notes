/*
        DIVISIBLE PAIRS IN AN ARRAY

        The problem is to find all pairs of numbers in an array, such that
        one of those numbers divides the other.
*/

package main

import (
    "fmt"
)

func main() {
    var num int
    fmt.Print("Enter the size of array : ")
    fmt.Scan(&num)
    var a = []int{}
    fmt.Print("Enter array elements")
    for i := 0; i < num; i++ {
        var x int
        fmt.Scan(&x)
        a = append(a, x)
    }
    fmt.Println("The following are the divisible pairs :")
    for i := 0; i < num; i++ {
        for j := i + 1; j < num; j++ {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                fmt.Println(a[i], a[j])
            }
        }
    }
}

/*
Input :
num = 4
Array = [1, 4, 5, 20]

Output : 

The following are the divisible pairs :
1 4
1 5
1 20
4 20
5 20
*/
