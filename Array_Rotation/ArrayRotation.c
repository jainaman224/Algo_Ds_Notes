#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int a[1000000], int i, int j, int n, int d, int temp ;
    // n is the number of elements and d is the number of times rotation.
    scanf("%d %d", &n, &d);   
    // scanning elements
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);	
    }
    for(j = 0; j < d; j++)
    {
        temp = a[0];

        for(i = 0; i < n; i++)
        {
            a[i] = a[i + 1];
            a[n] = temp;
        }
    }
    //printing the elements of array
    for(i = 0; i < n; i++)
    {
        printf("%d", a[i]);      
    }
   return 0 ;
}

/*Test input
INPUT: 5 4 (number of elements and no. of times rotation)
       1 2 3 4 5 (the input array)

Output: 5 1 2 3 4 
*/

