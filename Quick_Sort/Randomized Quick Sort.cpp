#include<bits/stdc++.h>
using    namespace    std;

/*Partitioning    function    that    takes    last    element    as    pivot, places 
  the    pivot    element    at    its    correct    position    in    sorted 
  array, and    places    all    smaller(smaller    than    pivot) 
  to    left    of    pivot    and    all    greater    elements    to    right 
  of    pivot*/

int    partition_index(int    array[], int    low, int    high){
    int    pivot = array[high];
    int    i = low - 1;
    for(int    j = low;j < high; j++){
	//If    current    element    is    smaller    than    or 
	//equal    to    pivot    then    increment    smaller    index    and    swap
        if(array[j] <= pivot){                  
            i++;                               
            swap(array[i], array[j]);
        }
    }
    swap(array[i+1], array[high]);
    return    i+1;
} 

//This    function    generates    a    random_index    in    the    range    [low, high]    and 
//swaps    array[high]    with    array[random_index]
int    random_partition(int    array[], int    low, int    high){
    // To    create    a    random    number    every    time    the    program    is    executed
    srand(time(NULL));    
    int    random_index = low + rand() % (high - low);   
    swap(array[random_index], array[high]);
    return    partition_index(array,low,high);
}

/*Recursive    function    that    implements    QuickSort 
array[] - Array    to    be    sorted, 
low - Starting    index, 
high - Ending    index */
void    quick_sort(int    array[], int    low, int    high){
    if(low < high){
        int    partition = random_partition(array, low, high);
        //Separately    sort    elements    before 
        //partition    and    after    partition 
        quick_sort(array, low, partition - 1);
        quick_sort(array, partition + 1, high);
    }
}

//Function    to    print    an    array 
void    print_array(int    array[], int    n){
    for(int    i = 0; i < n; i++)
        cout << array[i] << "    ";
    cout << endl;
}

//Main    function
int    main(){
    cout << "Enter    the    number    of    elements    of    array:    ";
    int    n;
    cin >> n;
    
    int    array[n];
    cout << "\nEnter    the    array    elements:    ";
    for(int    i = 0;    i < n;    i++)
        cin >> array[i];
        
    cout << "\nOriginal    array:    ";
    print_array(array, n);
    
    quick_sort(array, 0, n - 1);
    cout << "Sorted array:    ";
    print_array(array, n);
}

/*Sample    Input    -    Output
Enter    the    number    of    elements    of    array:    8                                                                                      
                                                                                                                              
Enter the array elements:    45    23    78    23    1    78    34    0                                                                               
                                                                                                                              
Original array:    45    23    78    23    1    78    34    0                                                                                         
Sorted array:    0    1    23    23    34    45    78    78    */
