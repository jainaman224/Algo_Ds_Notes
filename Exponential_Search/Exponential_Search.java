
import java.util.*; 

class Exponential_Search 
{ 
    // Returns position of first occurrence of x in array 
    static int expoSearch(int input[], int n, int x) 
    { 
        // If x is present at firt location itself 
	if (input[0] == x) 
	    return 0; 
	
	// Find range for binary search by repeated doubling 
	int i = 1; 
	while (i < n && input[i] <= x) 
	    i = i*2; 
	
	// Call binary search for the found range. 
	return Arrays.binSearch(input, i/2, Math.min(i, n), x); 
    } 
	
    // Driver code 
    public static void main(String args[]) 
    { 
	// Sample Input
        int arr[] = {2, 3, 14, 20, 40}; 
	int x = 20; 
	int result = expoSearch(arr, arr.length, x); 
		
	System.out.println((result < 0) ? "Element is not present in array" : "index " + result); 
     } 
} 

/* Sample Output : 
    index 3
*/

