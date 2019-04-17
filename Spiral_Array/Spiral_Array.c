//SPIRAL PRINTING 2-D matrix

#include <stdio.h>

int main()
{
    int m, n;
    int left, right, top, bottom;
    int i, j, count, dir;
    int arr[100][100];
    
    scanf("%d %d", &m, &n);  // Matrix of m*n

    left = 0;
    right = n-1;
    top = 0;
    bottom = m-1;

    count = m * n;        //no. of elements
    dir = 1;

    for (i=0; i<m; i++)	// Taking Inputs
    {
        for (j=0; j<n; j++)	
            scanf("%d", &arr[i][j]);
    }

    while (left <= right && top <= bottom && count > 0)
    {
        if (dir == 1)		//left to right
        {
            for (i = left; i <= right; i++)
            {
                printf("%d  ", arr[top][i]);	//Printing the topmost untraversed row  
                count--;
            }
            dir++;
            top++;
        }
        if (dir == 2)		//top to bottom
        {
            for (i = top; i <= bottom; i++)
            {
                printf("%d  ", arr[i][right]);	//Printing the rightmost untraversed column
                count--; 
            }
            dir++;
            right--;
        }
        if (dir == 3)		//left to right
        {
            for (i = right; i >= left; i--)
            {
                printf("%d  ", arr[bottom][i]);	//Printing the bottommost untraversed column
                count--;
            }
            dir++;
            bottom--;
        }
        if (dir == 4)		//bottom to top
        {
            for (i = bottom; i >= top; i--)
            {
                printf("%d  ", arr[i][left]);	//Printing the leftmost untraversed column
                count--;
            }
            dir = 1;
            left++;
        }
    }
    return 0;
}

/* SAMPLE I/O

Input

3 3
1 2 3
4 5 6 
7 8 9

Output

1 2 3 6 9 8 7 4 5
*/
