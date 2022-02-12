//++++++++++Utility++++++++++++++++++++++

//function to swap two values
function swap(arr, index1, index2)
{
    var temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}
//function to implement heapsort
function HeapSort(input)
{
    var n=input.length;
    //Build heap
    for(var i = Math.floor(n/2) - 1; i >= 0; i-- )
    {
        heapify( arr, n, i);
    }

    for( var i = n - 1; i >= 0; i-- )
    {
        swap( arr, 0 , i);
        heapify ( arr ,i, 0);
    }
}
//This function maintain property of max heap
function heapify( arr , n, i)
{
    var greatest = i;
    var idx_left_child = 2*i + 1;
    var idx_right_child = 2*i + 2;
    //If left child child is greater then its parent
    if ( ( idx_left_child  <  n )   &&   ( arr[idx_left_child]  >  arr[greatest] ) )
    {
        greatest = idx_left_child;
    }
    //If right child is greater then its parent
    if ( ( idx_right_child  <  n )   &&   ( arr[idx_right_child]  >  arr[greatest] ) )
    {
        greatest = idx_right_child;
    }
    //One of the above condition was true then heap property is not being satisfied 
    //Hence we heapify the sub-tree whose root is at ith index of array
    if(greatest != i)
    {
        swap(arr, i, greatest);
        heapify( arr, n, greatest);
    }
}
//Function that performs Insertion Sort
function InsertionSort( nums, begin, end)
{
    for (var i = 1; i < nums.length; i++)
    {
        let j = i - 1;
        let temp = nums[i];
        while (j >= 0 && nums[j] > temp) 
        {
          nums[j + 1] = nums[j];
          j--;
        }
        nums[j+1] = temp;
    }
}
//Function that finds middle of the numbers a, b, c 
function MedianofThree(a, b, c)
{
    if(a < b && b < c)
        return b;
    if( a < c && c <= b)
        return c;
    if(b <= a && a < c)
        return a;
    if( b < c && c <= a)
        return c;
    if( c <= a && a < b)
        return a;
    if( c <= b && b <= a)
        return b;
}
//Function to create partition for Quick Sort
function Part(arr, begin,end)
{
    var pivot=arr[Math.floor((begin + end) / 2)];
    var i = begin;
    var j = end;
    while (i <= j)
    {
        while( arr[i] < pivot)
        {
            i++;
        }
        while( arr[j] > pivot)
        {
            j--;
        }
        if( i<= j)
        {
            swap(arr, i, j);
            i++;
            j--;
        }
    }
    return i;
}

//+++++++++++++++End of Utilities++++++++++++++++++++++++++++++

function IntroSort( arr )
{
    var depth = 2 * Math.floor(  Math.log( arr.length )  );
    IntroSortHelper( arr, 0, arr.length-1, depth );
    return ;
}
//Function that Implement IntroSort
function IntroSortHelper( arr, begin, end, depth)
{
    var size = end - begin;
    //If depth is zero then heap sort is used
    if ( depth === 0 )
    {
        //Below commented statement can be used to check the working of the inputs provided
        //console.log('Depth is zero hence using Heap Sort:\n');
        HeapSort(arr);
        return ;
    }
    //If number of elements is less then 16 Insertion Sort is used
    else if (size < 16)
    {
        //Below commented statement can be used to check the working of the inputs provided
        //console.log('Number of elements less then 16 hence using Insertion Sort:\n');
        InsertionSort (arr, begin, end);
        return ;
    }
    else
    {
        //Below commented statement can be used to check the working of the inputs provided
        //console.log('Number of elements greater then 16 hence using Quick Sort: ')
        var pivot = MedianofThree( begin, Math.floor(begin+size/2), end);
        swap(arr, pivot, end);
        var partition = Part(arr, begin , end);
        IntroSortHelper(arr, begin, partition-1, depth-1);
        IntroSortHelper(arr, partition+1, end , depth-1);
        return ;
    }
}
//++++++++++++++++++++++++++Input+++++++++++++++++++++++++++++++++++++++++
var readlineSync = require('readline-sync');
var n = readlineSync.question('Enter the number of elements: ')
var arr = [n];
for( var i = 0; i < n ; i++ )  
{
    console.log(`Enter the `, i ,`th element of array: `);
    var a = readlineSync.question();
    arr[i] = a;
}
IntroSort(arr);
console.log(arr);

/*
1. When initially Quick Sort is used

Input1: [2, 4, 7, 89, 0, 73, 3, 4, -2, -8, 22, 28, 19, 100, -3333, -89, 200098, -10]
Output1: [-3333, -89, -10, -8, -2, 0, 2,  3, 4, 4,   7, 19, 22, 28,  73, 89, 100, 200098]


2.When Insertion Sort is used

Input2: [3, 7, 2, 9, 1]
Output2: [3, 7, 2, 9, 1]


3. When Heap Sort is used

Input3: [9,8]
Output3: [8,9]
*/
