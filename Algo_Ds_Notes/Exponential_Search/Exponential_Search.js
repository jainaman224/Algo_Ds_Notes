
// A recursive binary search function. 
function binSearch(arr, left, right, x) 
{ 
    if (right >= left) 
    { 
        let mid = left + (right - left)/2; 
  
        // If the element is present at the middle 
        if (arr[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then it can only be present n left subarray 
        if (arr[mid] > x) 
            return binSearch(arr, left, mid-1, x); 
  
        // Else the element can only be present in right subarray 
        return binSearch(arr, mid+1, right, x); 
    } 
  
    return -1; 
} 
  
 
function exponentialSearch(arr, size, x) 
{ 
 
    if (arr[0] == x) 
        return 0; 
  
    // Find range for binary search by repeated doubling 
    let i = 1; 
    while (i < size && arr[i] <= x) 
        i = i*2; 
  
    //  Call binary search for the found range. 
    return binSearch(arr, i/2, min(i, size), x); 
} 
  
// Sample Input 
a = [2, 3, 14, 20, 40]; 
x = 10;

// Driver Code
n = sizeof(arr)/ sizeof(arr[0]); 
result = exponentialSearch(arr, n, x); (result == -1)? printf("Element is not present in array") : printf("index %d", result); 



/* Sample Output :
   index 3
*/

