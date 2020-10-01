/*An integer x is said to be Noble given an array if the 
number of integers greater than x are equal to x. 
If there are many Noble integers, any of them is returned. 
If there is no noble integer, then return -1.*/

#include<stdio.h>
#include<stdlib.h>

int Noble(int n, int A[]) 
{
    int c;
    for (int i = 0; i < n; i++) { 
        c = 0; 
        for (int j = 0; j < n; j++) {  
            if (A[i] < A[j]) {
                c++;
            }
    }              
        if (c == A[i]) {
            return A[i];
        }
    } 
      
    return -1; 
}

int main () 
{
    int n;
    printf("Enter the size of array : ");
    scanf("%d", &n);
    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Noble Integer = %d", Noble(n, A));

    return 0;
}

/*
Input :
Enter the size of array : 6
3 2 5 6 1 4
Output :
Noble Integer = 3

Input : 
Enter the size of array : 3
2 2 2
Output :
Noble Integer = -1
*/
