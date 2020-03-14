package main

import "fmt"

func cocktail_sort(arr[] int,n int){
	end := n - 1
  var i int
  for {
        swapped := false
        i=0
        
        //comparison of elements from the front
        
        for i < end {
            if arr[i] > arr[i+1] {
                arr[i], arr[i+1] = arr[i+1], arr[i]
                swapped = true
            }
            i = i + 1 
        }
        if !swapped {
            return
        }
        swapped = false
        end = end - 1
        i = end -1
        
        //comparison of elements from backward
        
        for i >= 0 {
            if arr[i] > arr[i+1] {
                arr[i], arr[i+1] = arr[i+1], arr[i]
                swapped = true
            }
            i = i - 1
        }
        if !swapped {
            return
        }
    }
}

func main(){
	var n int
	fmt.Print("Enter the number of elements:")
	fmt.Scan(&n)
	arr:=make([]int, n)
	i:=0
	for(i<n){
		fmt.Print("Enter element ",i+1,":")
		fmt.Scan(&arr[i])
		i = i + 1
	}
	cocktail_sort(arr,n)
	fmt.Print("Sorted Arry is: ",arr)
	
	/* Sample Input arr[]={89,23,1,65,4,7,9,100}
	output arr[]={1,4,7,9,23,65,89,100}
	*/
}
