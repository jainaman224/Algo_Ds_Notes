/*    Implenetation of Binary Search algorithm to find value 6 in a given array of numbers    */

function BinarySearch( arr:number[] , n:number ,  val:number ) :number
{
    var start = 0 //starting index of the array
    var end = n-1 //ending index
    var mid = 0	 
    var ind = -1  

    while (start <= end)
    {
        mid = Math.floor((start + end) / 2) 
		
        //checking if value to be found is at the middle 
        if ( val == arr[mid] )
        {
            ind = mid 
            break
        }
		
        /* if value to be found is greater than the middle then the algorithm 
           searches to the right of the middle element in the array */
        else if ( val > arr[mid] )
        {
            start = mid + 1  
        }
        /* if value to be found is less than the middle then the algorithm 
           searches to the left of the middle element in the array */
        else
        {
            end = mid - 1 
        }   
    }
    return ind  //returning the index of the value if found, else returns -1
}
var result = 0  
var n = 0	 
var val = 6  //input value 
console.log(" value to be found: ", val);
var n: number = 6  //no. of elements in the array
var arr = [1, 2, 3, 4, 5, 6]; //input array
console.log(" Array of numbers is: ", arr);
result = BinarySearch(arr, n, val)  
if (result != -1) {
    console.log(" value ", val," found at index no. ", result," in the array ");
}
else {
    console.log(" value ", val," not found ");
}


/*  OUTPUT:

    value to be found:  6
    Array of numbers is:  [ 1, 2, 3, 4, 5, 6 ]
    value  6  found at index no.  5  in the array
*/


