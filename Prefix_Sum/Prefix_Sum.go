/*
    PREFIX SUM

    The task is to find the prefix sum of every element of a given array.
    Prefix sum equals to the sum of all element from start to the current element of the array.

*/
package main
import "fmt"

func prefix_sum(array []int, length int){
    prefix_array := array
    /*
        We maintain a prefix array where prefix_array[i] = prefix_array[i-1] + array[i].
        As, prefix sum of element i = prefix sum of element i-1 + element i.
    */
    for i:=1; i<length; i++ {
        prefix_array[i] = prefix_array[i-1] + array[i]
    }
    fmt.Println("The prefix array is: ")
    for i:=0; i<length; i++ {
        fmt.Print(prefix_array[i]," ")
    }
}

func main() {
    var length = 5
    var array = []int{3,2,4,6,7}
    prefix_sum(array, length)
}
/*
Input : array = {3,2,4,6,7}
Output: The prefix sum array is: 
        3 5 9 15 22 
*/
