/* The Activity Selection Problem
You are given n activities with their start and finish times. 
Select the maximum number of activities that can be performed by a single person, 
assuming that a person can only work on a single activity at a time. 
*/
class ActivitySelection 
{
    void activities(List<int> start, List<int> finish, int n) 
    {
        int i = 0;
        print('$i ');
        for (int j = 1; j < n; j++) 
        {
            if (start[j] >= finish[i]) 
            {
                print('$j ');
                i = j;
            }
        }
    }
}

void main() 
{
    List<int> start = [0, 5, 5, 4, 5, 8]; // starting time of the activities
    List<int> finish = [2, 7, 6, 8, 9, 14]; // finishin time of the activities
    int n = start.length;
    ActivitySelection selection = new ActivitySelection();
    selection.activities(start, finish, n);
}
/*
	Sample input
	Start : 0 5 5 4 5 8
	Finish: 2 7 6 8 9 14

	Sample Output
	0 1 5
 */
