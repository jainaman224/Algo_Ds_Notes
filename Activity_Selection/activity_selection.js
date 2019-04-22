/*
The problem statement for Activity Selection is that "Given a set of n activities with their start and finish times, we need to select maximum number of non-conflicting activities that can be performed by a single person, given that the person can handle only one activity
at a time." The Activity Selection problem follows a Greedy approach.
*/

// Function to compute the activities to be chosen
var activitySelection = function(start, finish, length) 
{
    i = 0;
    console.log( i + " ");
    // if start time of current activity j is greater than or equal to previous activity chosen, select activity j
    for (var j = 1; j < length; j++) 
    {
        if (start[j] >= finish[i]) 
        {
            console.log( j + " ");
            i = j;
        }
    }
}

// The array of n elements where start[i] denotes starting time of ith activity	
var start = [1, 3, 1, 5, 6, 8];
// The array of n elements where finish[i] denotes finishing time of ith activity
var finish = [2, 6, 6, 7, 8, 10];
// Call to activitySelection function
activitySelection(start, finish, start.length);

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
