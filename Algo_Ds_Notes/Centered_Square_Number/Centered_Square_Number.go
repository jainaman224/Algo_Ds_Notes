/*
Centered Square Number is a centered figurate number that gives the number
of dots in a square with a dot in the center and all other dots surrounding 
the center dot in successive square layers.
    
Nth Centered square number can be calculated by using formula n^2 + (n-1)^2.
*/

package main
import "fmt"

func centeredSquare(num int)int {
    // Using formula 
    return num * num + ((num - 1) * (num - 1))
}

func main() {
    var num int
    fmt.Scanf("%d", &num)    
    fmt.Printf("%d", centeredSquare(num))
}

/*
Input:
6
output:
61
*/
