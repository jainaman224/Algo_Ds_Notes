/*
                    Counting Sort
           ------------------------------------		
    Counting sort is a sorting technique based on keys between a specific range.
    It works by counting the number of objects having distinct key values (kind of hashing).
    Then doing some arithmetic to calculate the position of each object in the output sequence.
*/		   

package main
import "fmt"

const MaxUint = ^uint(0)
const MaxInt = int(MaxUint >> 1)
const MinInt = - MaxInt - 1

func countingSort(list []int) {
    maxNumber := MinInt
    minNumber := MaxInt
    for _, v := range list {
        if v > maxNumber {
            maxNumber = v
        }
        if v < minNumber {
            minNumber = v
        }
    }

    count := make([]int, maxNumber - minNumber + 1)

    for _, x := range list {
        count[x - minNumber]++
    }
    index := 0
    for i, c := range count {
        for ; c > 0; c-- {
            list[index] = i + minNumber
            index++
        }
    }
}

func main() {
    var x int
    fmt.Printf("Enter the size of the array : ")
    fmt.Scan(&x)
    fmt.Printf("Enter the elements of the array : ")
    a := make([]int, x)
    for i := 0; i < x; i++ {
        fmt.Scan(&a[i])
    }
    list := a    // A copy of the array 'a' is assigned to 'list' 
    fmt.Println("before sorting", list)
    countingSort(list)
    fmt.Println("after sorting", list)
}

/*
Sample Input :
    Enter the size of the array : 4                                                                                              
    Enter the elements of the array : 12 29 10 78

Sample Output :
    After sorting [10 12 29 78]	
*/

