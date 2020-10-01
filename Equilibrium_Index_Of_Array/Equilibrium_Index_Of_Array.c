/*
    EQUILIBRIUM INDEX OF AN ARRAY

    An equilibrium index is an index of an array, where the commulative sum 
    of all elements below it is equal to the commulative sum of all elements
    above it in that array.

*/

#include<stdio.h>

int eq_index(int a[], int num) {
    int sum = 0;
    int sum_left = 0;
    for (int i = 0; i < num; i++) {
        sum = sum + a[i];
    }
    for (int i = 0; i < num; i++) {
        sum = sum - a[i];
        if (sum_left == sum) {
            return i;
        }
        sum_left = sum_left + a[i];
    }
    return -1;
}

int main() {
    int num;
    printf("Enter length of array");
    scanf("%d", &num);
    printf("Enter array elements :");
    int a[num];
    for (int i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    printf("The equilibrium index is : %d", eq_index(a, num));
}

/*
    Input : num = 4
            Array : [12, 2, 6, 6]
    Output : The equilibrium index is : 1
*/
