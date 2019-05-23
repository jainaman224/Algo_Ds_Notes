/*
A majority element in an array arr of size n is an
element that appears more than n/2 times.
Example: 
N = 9, arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}
Majority Element = 2 as count[2] = 5 which is greater
than n/2 i.e 4
*/

package main
import "fmt"

func checkMajorityElement(arr[] int, N int) int {
    mp := make(map[int] int)
    // Computing frequency of each element
    for i := 0; i < N; i++ {
        mp[arr[i]]++
    }

    for key, value := range mp {
        if value > (N / 2) {
            return key
        }
    }
    return -1
}

func main() {
    var N int
    fmt.Printf("Enter size of array:\n")
    fmt.Scanf("%d", &N)
    arr := make([]int, N)
    fmt.Printf("Enter elements of array:\n")
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &arr[i])
    }
    ans := checkMajorityElement(arr, N)
    if ans != -1 {
        fmt.Printf("Majority Element is: %d", ans)
    } else {
        fmt.Printf("No majority element in array")
    }
}

/*
Input:
N = 9
arr = {1, 2, 2, 2, 4, 2, 2, 1, 5}

Output:
Majority Element is: 2

Input:
N = 5
arr = {1, 2, 3, 4, 5}

Output:
No majority element in array
*/
