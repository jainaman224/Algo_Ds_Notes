// JavaScript program to implement Jump Search 
function jumpSearch(arr,x,n) 
{ 
	// Finding block size to be jumped 
	var step = Math.sqrt(n); 

	// Finding the block where element is 
	// present (if it is present) 
	var prev = 0; 
	while (arr[Math.min(step, n)-1] < x) 
	{ 
		prev = step; 
		step += Math.sqrt(n); 
		if (prev >= n) 
			return -1; 
	} 

	// Doing a linear search for x in block 
	// beginning with prev. 
	while (arr[prev] < x) 
	{ 
		prev++; 

		// If we reached next block or end of 
		// array, element is not present. 
		if (prev == Math.min(step, n)) 
			return -1; 
	} 
	// If element is found 
	if (arr[prev] == x) 
		return prev; 

	return -1; 
} 

//The main function
function main() 
{ 
	var arr = [ 0, 1, 1, 2, 3, 5, 8, 13, 21, 
				34, 55, 89, 144 ]; 
	var x = 55; 
	var n= arr.length;
	
	// Find the index of 'x' using Jump Search 
	var index = jumpSearch(arr, x, n); 

	// Print the index where 'x' is located 
	console.log("Number " + x +" is at index " + index);
} 
main();

//OUTPUT => Number 55 is at index 10
//Time Complexity : O(√n)

