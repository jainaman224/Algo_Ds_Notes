using System; 

class exponentialSearch { 

    static int exponentialSearch(int []arr, int n, int x) 
    { 
        if (arr[0] == x) 
	    return 0; 

	// Find range for binary search by repeated doubling 
	int i = 1; 
	while (i < n && arr[i] <= x) 
            i = i * 2; 

	// Call binary search for the found range. 
	return binSearch(arr, i/2, Math.Min(i, n), x); 
    } 


    static int binSearch(int []arr, int left, int right, int x) 
    { 
         if (right >= left) 
	 { 
	     int mid = left + (right - left) / 2; 

	     // If the element is present at the middle itself 
	     if (arr[mid] == x) 
	         return mid; 

	     if (arr[mid] > x) 
		 return binSearch(arr, left, mid - 1, x); 

	     // Else the element can only be present in right subarray 
	     return binSearch(arr, mid + 1, right, x);  
           } 

           return -1; 
    } 

    // Driver code 
    public static void Main() 
    { 	  
	 // Sample Input
         int []input = {2, 3, 14, 20, 40}; 
         int n = input.Length; 
         int x = 20; 
         int result = exponentialSearch(input, n, x); 
         if (result == -1) 
             Console.Write("Element is not present in array"); 
         else
	     Console.Write("index "+ result); 
    } 
} 


/* Sample Output :
    index 3
*/

