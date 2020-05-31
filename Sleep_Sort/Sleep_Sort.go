package main

import "fmt"
import "time"

func sleepNumber(number int, results chan<- int) {
    time.Sleep(time.Duration(number) * time.Second)
    results <- number
}

func sleepSort(data []int) {
    results := make(chan int, len(data))
    for _, v := range data {
        go sleepNumber(v, results)
    }

    for i, _ := range data {
        data[i] = <-results
    }
    close(results)
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
    data := a    // A copy of the array 'a' is assigned to 'data' 
    sleepSort(data)
    fmt.Println("After sorting", data)
}

/*

Sample Input :
    Enter the size of the array : 5                                                                                               
    Enter the elements of the array : 34 23 1 78 6   
	
Sample Output :
    After sorting [1 6 23 34 78]
	
*/

