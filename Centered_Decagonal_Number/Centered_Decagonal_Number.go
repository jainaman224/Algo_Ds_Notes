/*
    A centered decagonal number is a centered figurate number that represents
    a decagon with a dot in the center and all other dots surrounding the center
    dot in successive decagonal layers. 
    
    The centered decagonal number for n is given by the formula
    5n^2+5n+1 
*/

package main

import "fmt"

func centeredDecagonal (num int) int {
    // Using formula 
    return 5 * num * num + 5 * num + 1
}

func main() {
    var num int
    fmt.Scanf("%d", &num)
    
    fmt.Printf("%d centered decagonal number : %d", num, centeredDecagonal(num))
}

/*
Input:
6
output:
6 centered decagonal number : 211
*/
