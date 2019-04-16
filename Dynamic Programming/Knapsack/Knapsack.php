<?php 
// Girlscript Summer Of Code
// 0-1 Knapsack program in Python

/*
What is 0-1 KnapSack program?
Given weights and values of n items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack. In other words, given two integer arrays val[0..n-1] and wt[0..n-1] which represent values and weights associated with n items respectively. Also given an integer W which represents knapsack capacity, find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W. You cannot break an item, either pick the complete item, or don’t pick it (0-1 property).
[Refered from www.geeksforgeeks.com]
*/

// Knapsack function based on Dynamic Programming 
/*
Variables:
mw-maximum weight
wt[]-Array of weights
val[]-Array of values
n-number of values 
*/
function knapSack($maxweight, $weights, $values, $n) 
{ 
	
	$subset = array(array()); 
	
	for ($i = 0; $i <= $n; $i++) 
	{ 
		for ($j = 0; $j <= $maxweight; $j++) 
		{ 
			if ($i == 0 || $j == 0) 
				$subset[$i][$j] = 0; 
			else if ($weights[$i - 1] <= $j) 
					$subset[$i][$j] = max($values[$i - 1] + 
									$subset[$i - 1][$j - 
									$weights[$i - 1]], 
									$subset[$i - 1][$j]); 
			else
					$K[$i][$j] = $K[$i - 1][$j]; 
		} 
	} 
	
	return $K[$n][$maxweight]; 
} 

	// Driver Code 
	// Test case for the program :
	$values = array(30, 20, 60, 80, 10); 
	$weights = array(10, 20, 30, 40, 50); 
	$MaxWeight = 80; 
	$n = count($val); 
	// Display Result
	echo knapSack($MaxWeight, $weights, $values, $n); 
	// Result is 170 for the test case given initially.
	
//  Happy Coding!
?> 

