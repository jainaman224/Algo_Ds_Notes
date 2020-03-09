/* A Palindromic Sequence is a sequence of numbers which is 
the same when read both forward and backward.
Example: 1, 2, 3, 2, 1 */

package main
import "fmt"

func isPalindromic(arr[] int, N int) bool {
    for i := 0; i <= (N / 2); i++ {
        if arr[i] != arr[N - i - 1] {
            return false
        }
    }
    return true
} 

func main() {
    fmt.Printf("Enter number of elements in array\n")
    var N int
    fmt.Scanf("%d", &N)
    fmt.Printf("Enter elements of array\n")
    arr := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &arr[i])
    }
    if isPalindromic(arr, N) {
        fmt.Printf("The array is palindromic")
    } else {
        fmt.Printf("The array is not palindromic")
    }
}

/*
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not palindromic

Input:
N = 6
arr = {0, 2, 4, 4, 2, 0}

Output:
The array is palindromic
*/
