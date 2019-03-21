// Girlscript Summer Of Code
// 0-1 Knapsack program in Python

/*
To know what Knapsack problem is, refer 0-1knapsack/knapsack.py of this repository.
What is Dynamic Programming?
Dynamic Programming is mainly an optimization over plain recursion. Wherever we see a recursive solution that has repeated calls for same inputs, we can optimize it using Dynamic Programming. The idea is to simply store the results of subproblems, so that we do not have to re-comupute them when needed later. This simple optimization reduces time complexities from exponential to polynomial. For example, if we write simple recursive solution for Fibonacci Numbers, we get exponential time complexity and if we optimize it by storing solutions of subproblems, time complexity reduces to linear.
[Refered from www.geeksforgeeks.com]
*/
#include<stdio.h> 

// Function to get maximum of two numbers: 
int max(int a, int b) 
{ 
    return (a > b)? a : b; 
} 

// Knapsack function based on Dynamic Programming 
/*
Variables:
mw-maximum weight
wt[]-Array of weights
val[]-Array of values
n-number of values
*/
int knapSack(int maxweight, int weights[], int values[], int n) 
{ 
    int i, j; 
    int subset[n+1][maxweight+1]; 


    for (i = 0; i <= n; i++) 
    { 
	for (j = 0; j <= maxweight; j++) 
	{ 
		if (i==0 || j==0) 
			subset[i][j] = 0; 
		else if (weights[i-1] <= j) 
				subset[i][j] = max(values[i-1] + subset[i-1][j-weights[i-1]], subset[i-1][j]); 
		else
				subset[i][j] = subset[i-1][j]; 
	} 
    } 

    return subset[n][maxweight]; 
} 

// Main function
int main() 
{ 
        // Test case for the program :
	int values[] = {30, 20, 60, 80, 10}; 
	int weights[] = {10, 20, 30, 40, 50}; 
        // Maximum Weight
	int MaxWeight = 80; 
	int n = sizeof(values)/sizeof(values[0]); 
        // Display Result
	printf("%d\n", knapSack(MaxWeight, weights, values, n)); 
        // Result is 170 for the test case given initially.

	return 0; 
} 
//  Happy Coding!
