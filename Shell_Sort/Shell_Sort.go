package main

import (
    "fmt"
    "strconv"
)

func main() {
    var n int
    fmt.Scanf("%d", &n)

    // input the size of the array
    var arr = make([]int, n)

    // input the elements of the array
    for i := 0; i < n; i++ {
        if _, err := fmt.Scan(&arr[i]); err != nil {
            panic(err)
        }
    }

    // calling the shellsort function to sort the array
    shellsort(arr)

    // printing the sorted array
    for i := 0; i < n; i++ {
        fmt.Print(strconv.Itoa(arr[i])+" ")
    }
}

func shellsort(items []int) {
    var (
        n = len(items)
        gaps = []int{1}
        k = 1
      
    )
    
    // start with a bigger gap and then gradually reduce the gaps
    for {
        gap := element(2, k) + 1
            if gap > n-1 {
                break
            }
        gaps = append([]int{gap}, gaps...)
        k++
    }

    // shell sort logic
    for _, gap := range gaps {
        for i := gap; i < n; i += gap {
            j := i
            for j > 0 {
                if items[j-gap] > items[j] {
                    items[j-gap], items[j] = items[j], items[j-gap]
                }
                j = j - gap
            }
        }
    }
}

// function to help calculate number of gaps
func element(a, b int) int {
    e := 1
    for b > 0 {
        if b&1 != 0 {
            e *= a
        }
        b >>= 1
        a *= a
    }
    return e
}

/*
  SAMPLE INPUT:   5
                  5 4 1 2 3
  SAMPLE OUTPUT:  1 2 3 4 5
*/