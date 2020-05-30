package main
import (
    "fmt"
)

func PigeonholeSort(a []int) {
    arrayLength := len(a)
    if arrayLength == 0 {    // this is used to handle for the edge case when there is nothing to sort
        return
    }
    min := a[0]
    max := a[0]
    for _, value := range a {    // get the min and max values of the array
        if value < min {
            min = value
        }
        if value > max {
            max = value
        }
    }
    size := max - min + 1
    holes := make(map[int][]int, size)    // create the pigeon holes with the initial values
    for i := 0; i < size; i++ {
        holes[i] = []int{}
    }
    for _, value := range a {    // for every value in the array, put it in the corresponding pigeonhole
        holes[value - min] = append(holes[value-min], value)
    }

    // finally, replace the values in the array with the values from each pigeonhole in order
    j := 0
    for i := 0; i < size; i++ {
        for _, value := range holes[i] {
            a[j] = value
            j++
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
    randomSlice := a    // A copy of the array 'a' is assigned to 'randomSlice' 
    PigeonholeSort(randomSlice)
    fmt.Println("Sorted Slice: ", randomSlice)
}


/*

Sample Input :
    Enter the size of the array : 5                                                                                               
    Enter the elements of the array : 67 23 90 12 7   

Sample Output :	
    The sorted array is :  [7 12 23 67 90]

*/

