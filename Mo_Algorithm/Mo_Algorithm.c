# include <stdio.h> 
# include <math.h>

int block;

struct Query 
{ 
    int start;
    int end; 
}; 

//Function to swap the query
void swap (int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() 
{   
    int arr[] = {1, 2, 3, 4, 5}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    struct Query q[] = {{0, 3}, {2, 4}}; 
    int no = sizeof(q) / sizeof(q[0]);

    // Find block size
    block = (int)sqrt(size); 

    /*sorting all queries so that all queries  
    of the same block are arranged together and within a block, 
    queries are sorted in increasing order of end values.*/
    for(int i = 0; i < no; i++)
    {
        int pos = i;
        int temp;
        for(int j = i + 1; j < no; j++)
        {
            if(q[j].end/block < q[pos].end/block)
                pos = j;
        }

        swap(&q[i].start, &q[pos].start);
        swap(&q[i].end, &q[pos].end);
    }

    int currentstart = 0, currentend = 0; 
    int currentsum = 0; 

    // Traverse through all queries
    for (int i = 0; i < no; i++) 
    { 
        int start = q[i].start, end = q[i].end; 

        // Remove extra elements of previous range.
        while (currentstart < start) 
        { 
            currentsum -= arr[currentstart]; 
            currentstart++; 
        } 

        // Add Elements of current Range
        while (currentstart > start) 
        { 
            currentsum += arr[currentstart-1]; 
            currentstart--; 
        } 

        while (currentend <= end-1) 
        { 
            currentsum += arr[currentend]; 
            currentend++; 
        } 

        // Remove elements of previous range
        while (currentend > end) 
        { 
            currentsum -= arr[currentend-1]; 
            currentend--; 
        } 

        printf("Sum of [%d][%d] is: %d.\n", start , end, currentsum); 
    } 
    return 0; 
} 

/*
Sum of [0][3] is: 6.
Sum of [2][4] is: 7.
*/
