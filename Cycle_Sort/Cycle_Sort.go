package main
import (
    "fmt"
)

func main() {
    var x int
    fmt.Printf("Enter the size of the array : ")
    fmt.Scan(&x)
    fmt.Printf("Enter the elements of the array : ")
    a := make([]int, x)
    for i := 0; i < x; i++ {
        fmt.Scan(&a[i])
    }
    arr := a    // A copy of the array 'a' is assigned to 'randomSlice' 
    CycleSort(&arr)
    fmt.Printf("After sort: %v\n", arr)
}

func CycleSort(arr *[]int) int {
    writes := 0
    for cycleStart, item := range *arr {    // Loop through the array to find cycles to rotate.
        pos := cycleStart    // Find where to put the item.
        for i := cycleStart + 1; i < len(*arr); i++ {
            if (*arr)[i] < item {
                pos++
            }
        }
        
        if pos != cycleStart {    // If the item is already there, this is not a cycle.
            for item == (*arr)[pos] {    // Put the item there or right after any duplicates.
                pos++
            }
            
            (*arr)[pos], item = item, (*arr)[pos]
            writes++
            for pos != cycleStart {    // Rotate the rest of the cycle
                pos = cycleStart    // Find where to put the item
                for i := cycleStart + 1; i < len(*arr); i++ {
                    if (*arr)[i] < item {
                        pos++
                    }
                }
                
                for item == (*arr)[pos] {    // Put the item there or right after any duplicates.
                    pos++
                }
                (*arr)[pos], item = item, (*arr)[pos]
                writes++
            }
        }
    }
    return writes
}


/*

Sample Input :
    Enter the size of the array : 4                                                                                               
    Enter the elements of the array : 23  78 56 9                                                                                 
    
Sample Output :	
	After sort: [9 23 56 78]  
	
*/

