// C++ program for weighted job scheduling using Dynamic Programming. 
#include <iostream> 
#include <algorithm> 
using namespace std; 

// A job has start time, finish time and profit. 
struct Job 
{ 
	int start, finish, profit; 
}; 

// A utility function that is used for sorting events 
// according to finish time 
bool jobComparataor(Job s1, Job s2) 
{ 
	return (s1.finish < s2.finish); 
} 

// Find the latest job (in sorted array) that doesn't 
// conflict with the job[i] 
int latestNonConflict(Job arr[], int i) 
{ 
	for (int j=i-1; j>=0; j--) 
	{ 
		if (arr[j].finish <= arr[i].start) 
			return j; 
	} 
	return -1; 
} 

// The main function that returns the maximum possible 
// profit from given array of jobs 
int findMaxProfit(Job arr[], int n) 
{ 
	// Sort jobs according to finish time 
	sort(arr, arr+n, jobComparataor); 

	// Create an array to store solutions of subproblems. table[i] 
	// stores the profit for jobs till arr[i] (including arr[i]) 
	int *table = new int[n]; 
	table[0] = arr[0].profit; 

	// Fill entries in M[] using recursive property 
	for (int i=1; i<n; i++) 
	{ 
		// Find profit including the current job 
		int inclProf = arr[i].profit; 
		int l = latestNonConflict(arr, i); 
		if (l != -1) 
			inclProf += table[l]; 

		// Store maximum of including and excluding 
		table[i] = max(inclProf, table[i-1]); 
	} 

	// Store result and free dynamic memory allocated for table[] 
	int result = table[n-1]; 
	delete[] table; 

	return result; 
} 

// Driver program 
int main() 
{ 
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	cout << "The optimal profit is " << findMaxProfit(arr, n); 
	return 0; 
} 
