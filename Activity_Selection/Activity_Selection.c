/*
The problem statement for Activity Selection is that "Given a set of n activities with their start and finish times, we need to select maximum number of non-conflicting activities that can be performed by a single person, given that the person can handle only one activity
at a time." The Activity Selection problem follows a Greedy approach.
*/

#include <stdio.h>

// Function to compute the activities to be chosen
void ActivitySelection(int start[], int finish[], int n)
{
    printf("Following activities are selected: ");
    // Select the first activity
    int i = 0;
    printf("\n%d  ", i);
    int j;
    // if start time of current activity j is greater than or equal to previous activity chosen, select activity j
    for (j = 1; j < n; j++) 
    {
        if (start[j] >= finish[i]) 
        {
            printf("%d  ", j);
            i = j;
        }
    }
}

// Driver function
int main() 
{
    // starting time of activities
    int start[] = {1, 3, 1, 5, 6, 8};
    // sorted finish time of activities
    int finish[] = {2, 6, 6, 7, 8, 10};
    // computing size of array
    int n = sizeof(start) / sizeof(start[0]);
    // call to Activity Selection function
    ActivitySelection(start, finish, n);
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
