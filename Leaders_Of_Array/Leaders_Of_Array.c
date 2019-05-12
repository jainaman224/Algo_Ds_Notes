/*
    LEADERS OF AN ARRAY

    The task is to find all leaders in an array, where
    a leader is an array element which is greater than all the elements
    on its right side
*/

#include<stdio.h>

int main() {
    int num;
    printf("Enter the size of array : ");
    scanf("%d", &num);
    int a[num];
    printf("Enter array elements");
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    int maximum = a[num - 1];
    printf("The following are the leaders of array : \n");
    printf("%d ", a[num - 1]);
    for (int i = num - 2; i >= 0; i--) {
        if (a[i] > maximum) {
            printf("%d ", a[i]);
        }
    }
}

/*
Input : num = 5
        Array = [13, 4, 12, 1, 5]
Output :
        The following are the leaders of array : 
		5 12 13
*/
