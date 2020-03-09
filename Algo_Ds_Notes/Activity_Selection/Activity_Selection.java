/*
The problem statement for Activity Selection is that "Given a set of n activities with their start and finish times, we need to select maximum number of non-conflicting activities that can be performed by a single person, given that the person can handle only one activity
at a time." The Activity Selection problem follows a Greedy approach.
*/

class Activity_Selection
{
    // Function to compute the activities to be chosen
    public static void activities(int start[], int finish[], int n)
    {
        int i = 0, j;
        // Select the first activity
        System.out.print( i + " ");
        // if start time of current activity j is greater than or equal to previous activity chosen, select activity j
        for (j = 1; j < n; j++)
        {
            if (start[j] >= finish[i])
            {
                System.out.print( j + " ");
                i = j;
            }
        }
    }
	
    // Driver function
    public static void main(String args[])
    {
        // The array of n elements where start[i] denotes starting time of ith activity	
        int start[] = {1, 3, 1, 5, 6, 8};
        // The array of n elements where finish[i] denotes finishing time of ith activity
        int finish[] = {2, 6, 6, 7, 8, 10};
        int n = start.length;
        // Call to activities function
        Activity_Selection obj = new Activity_Selection();
        obj.activities(start, finish, n);
    }
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
