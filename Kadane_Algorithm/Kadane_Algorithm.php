<?php 
// PHP implementation of Kadane's Algorithm 
// Prints largest sum for a subarray 

function max_sumSubArray($a) 
{ 
	// max_ending_here is used to represent the sum of current subarray
	$max_ending_here = 0; 
	
	// max_so_far is used to represent the maximum sum, 
	// out of all the subarrays considered so far
	$max_so_far = PHP_INT_MIN; 

	for ($i = 0; $i < count($a); $i++) 
	{ 
		// Adding a new element to max_ending_here and 
		// increasing size of the subarray under consideration
		$max_ending_here = $max_ending_here + $a[$i]; 
		
		// Upon adding the new element, if max_ending_here > max_so_far 
		// then update max_so_far to max_ending_here
		if ($max_so_far < $max_ending_here) 
			$max_so_far = $max_ending_here; 
		
		// If max_ending_here becomes negative, then update it to 0
		if ($max_ending_here < 0) 
			$max_ending_here = 0; 
	} 
	return $max_so_far; 
} 

// Sample example
$a = array(4, -3, -2, 2, 3, 1, -2, -3, 4, 2, -6, -3, -1, 3, 1, 2); 
$max_sum = max_sumSubArray($a); 
echo "Maximum sum of subarray is: ", $max_sum; 

/*
Input as specified in the code:
4, -3, -2, 2, 3, 1, -2, -3, 4, 2, -6, -3, -1, 3, 1, 2

Output: 
Maximum sum of subarray is: 7
*/
?> 

