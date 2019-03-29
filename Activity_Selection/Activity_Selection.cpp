/*
The problem statement for Activity Selection is that "Given a set of n
activities with their start and finish times, we need to select maximum number
of non-conflicting activities that can be performed by a single person, given
that the person can handle only one activity at a time." The Activity Selection
problem follows a Greedy approach.
*/

#include <iostream>
using namespace std;

// Function to compute the activities to be chosen
void Activity_Selection(int start[], int finish[], int n) 
{
    cout << "Following activities are selected" << endl;
    // Select the first activity
    int i = 0;
    cout<<i<<" ";
    // if start time of current activity j is greater than or equal to previous
    // activity chosen, select activity j
    for (int j = 1; j < n; j++) 
    {
	if (start[j] >= finish[i]) 
	{
	    cout << j << " ";
	    i = j;
	}
    }
}

// Driver Function
int main() 
{
    // The array of n elements where start[i] denotes starting time of ith activity
    int start[] = {1, 3, 1, 5, 6, 8};
    // The array of n elements where finish[i] denotes finishing time of ith activity
    int finish[] = {2, 6, 6, 7, 8, 10};
    int n = sizeof(start) / sizeof(start[0]);
    // Call to activities function
    Activity_Selection(start, finish, n);
    return 0;
}

/*
Input:
Start
1 3 1 5 6 8
Finish
2 6 6 7 8 10
Output:
Following activities are selected
 0 1 4 5
*/
