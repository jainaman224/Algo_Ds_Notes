/*
    A decagonal number is a figurate number that extends the concept of 
    triangular and square numbers to the decagon (a ten-sided polygon).
    
    The n-th decagonal number is given by the formula:
    Dn = 4n^2 - 3n.
*/

package main

import "fmt"

func decagonalnumber (num int) int {
    // Using formula 
    return 4 * num * num - 3 * num
}

func main() {
    var num int
    fmt.Scanf("%d", &num)
    
    fmt.Printf("%d decagonal number : %d", num, decagonalnumber(num))
}

/*
Input:
6
output:
6 decagonal number : 126
*/
