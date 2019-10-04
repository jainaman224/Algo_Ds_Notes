/*
FIBONACCI WORDS

It is a series of words where each word is formed by concatenation
of last two words.
where :
T(1) = 0
T(2) = 01

T(n) = T(n-1) + T(n-2)
*/

package main

import "fmt"

func fibonacci(n int) string{
    if n == 1 {
        return "0"
    }
    if n == 2 {
        return "01"
    }
    return (fibonacci(n - 1) + fibonacci(n - 2))
}

func main() {
    var n int
    fmt.Print("Enter N: ")
    fmt.Scan(&n)
    fmt.Print("The fibonacci word at position ", n, " is: ", fibonacci(n))

}

/*
INPUT : n = 5
OUTPUT: The fibonacci word at position 5 is: 01001010
*/
