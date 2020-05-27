/*    Implementation of LinearSearch algorithm to find value 5 in a given array of numbers    */

function LinearSearch(arr:number[], n:number,  val:number) :number
{     
    for (let i = 0; i < n; i++) 
    {
        if (val == arr[i])
            return i;
    }
    return -1;
}  
   
       
var result = 0  
var n = 0	 
var val = 5  //input value 
console.log(" value to be found: ", val);
var n: number = 10 //no. of elements in the array
var arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]; //input array
console.log(" Array of numbers is: ", arr);
result = LinearSearch(arr, n, val)  
if (result != -1) 
{
     console.log(" value ", val," found at index no. ", result," in the array ");
} 
else 
{
    console.log(" value ", val," not found ");
}


/*  OUTPUT:
    value to be found:  5
    Array of numbers is:  [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 ]
    value  5  found at index no.  4  in the array
*/
