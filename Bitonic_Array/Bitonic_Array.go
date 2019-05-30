/* A Bitonic Sequence is a sequence of numbers which is first
strictly increasing then after a point strictly decreasing.
Example: -10, 0, 3, 5, 15, 13, 7, 2 */

package main
import "fmt"

func isBitonic(arr[] int, N int) int {
    if arr[0] > arr[1] {
        return -1
    }

    var i int
    var j int
    for i = 2; i < N; i++ { 
        if arr[i - 1] >= arr[i] {
            break
        }
    } 

    if i == N - 1 {
        return 1 
    }
 
    for j = i + 1; j < N; j++ {
        if arr[j - 1] <= arr[j] {
            break
        }
    } 
    
    if j != N {
        return -1
    }
  
    return 1 
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
    ans := isBitonic(arr, N)
    if ans == -1 {
        fmt.Printf("The array is not bitonic")
    } else {
        fmt.Printf("The array is bitonic")
    }
}

/*
Input:
N = 5
arr = {0, 1, 2, 3, 4}

Output:
The array is not bitonic

Input:
N = 5
arr = {0, 2, 4, 3, 1}

Output:
The array is bitonic

Input:
N = 5
arr = {4, 3, 2, 1, 0}

Output:
The array is not bitonic
*/
