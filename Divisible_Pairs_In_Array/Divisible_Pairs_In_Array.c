/*
        DIVISIBLE PAIRS IN AN ARRAY

        The problem is to find all pairs of numbers in an array, such that
        one of those numbers divides the other.
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
    printf("The following are the divisible pairs :\n");
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            if (a[i] % a[j] == 0 || a[j] % a[i] == 0) {
                printf("%d %d\n", a[i], a[j]);
            }
        }
    }
}

/*
Input :
num = 4
Array = [1, 4, 5, 20]

Output : 

The following are the divisible pairs :
1 4
1 5
1 20
4 20
5 20
*/
