/*
Perfect Sum problem:
Given an array of elements and a sum, print all subsets
which adds upto the given sum.
Example: arr = [1, 7, 3, 5, 6] and sum = 8, the solutions possible 
are [1, 7], [3, 5].
*/

package main
import "fmt"

var flag int

func isSubsetSum(arr[] int, subset[] int, N int, subsetSize int,
                            subsetSum int, index int, sum int) {
    if (subsetSum == sum) {
        flag = 1
        for i := 0; i < subsetSize; i++ {
            fmt.Printf("%d ", subset[i])
        }
        fmt.Printf("\n")
    } else {
        for i := index; i < N; i++ { 
            subset[subsetSize] = arr[i]
            isSubsetSum(arr, subset, N, subsetSize + 1, 
                        subsetSum + arr[i], i + 1, sum)
        }
    }
}

func main() { 
    fmt.Printf("Enter size of array\n")
    var N int
    fmt.Scanf("%d", &N)
    fmt.Printf("Enter elements of array\n")
    arr := make([]int, N)
    for i := 0; i < N; i++ {
        fmt.Scanf("%d", &arr[i])
    }
    fmt.Printf("Enter sum\n")
    var sum int
    fmt.Scanf("%d", &sum)
    subset := make([]int, N)
    isSubsetSum(arr, subset, N, 0, 0, 0, sum);
    if (flag == 0) {
        fmt.Printf("No such subset present\n");
    }
}

/*
INPUT:
N = 5
arr = [1 2 3 4 5]
sum = 7

OUTPUT:
1  2  4
2  5
3  4
*/
