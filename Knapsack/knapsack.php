<?php 
// Girlscript Summer Of Code
// 0-1 Knapsack program in Python

/*
What is 0-1 KnapSack program?
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
[Refered from www.geeksforgeeks.com]
*/

// Knapsack function based on Dynamic Programming 
function knapSack($W, $wt, $val, $n) 
{ 
	
	$K = array(array()); 
	
	for ($i = 0; $i <= $n; $i++) 
	{ 
		for ($w = 0; $w <= $W; $w++) 
		{ 
			if ($i == 0 || $w == 0) 
				$K[$i][$w] = 0; 
			else if ($wt[$i - 1] <= $w) 
					$K[$i][$w] = max($val[$i - 1] + 
									$K[$i - 1][$w - 
									$wt[$i - 1]], 
									$K[$i - 1][$w]); 
			else
					$K[$i][$w] = $K[$i - 1][$w]; 
		} 
	} 
	
	return $K[$n][$W]; 
} 

	// Driver Code 
	// Test case for the program :
	$val = array(30, 20, 60, 80, 10); 
	$wt = array(10, 20, 30, 40, 50); 
	$W = 80; 
	$n = count($val); 
	// Display Result
	echo knapSack($W, $wt, $val, $n); 
	// Result is 170 for the test case given initially.
	
//  Contributed by Jaseem CK
//  Happy Coding!
?> 

