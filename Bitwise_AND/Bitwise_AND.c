#include<stdio.h>

// Function to find bitwise AND 
void AND(int array[], int num) 
{ 
    int ans = array[0]; 
    for (int i = 0; i < num; i++) 
        ans &= array[i]; 
    printf("%d", ans); 
} 

// Driver program 
int main() 
{ 
    int num;
    scanf("%d", &num);
    int array[num]; 
    for (int i = 0; i < num; i++)
        scanf("%d", &array[i]);
    AND(array, num); 
    return 0; 
} 

/*
Input: 
num = 3
array[] = {4, 5, 6}
Output:
4
Because 4 = 100, 5 = 101, 6 = 110 in binary .
AND of 4 and 5 is 100(4) in binary and
AND of 4(resultant of 4 and 5) and 6 is 100(4).
so, answer is 4.
*/
