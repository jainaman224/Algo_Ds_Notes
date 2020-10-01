/*
        LENGTH OF LONGEST ALTERNATING SUBARRAY

        Given an array of non-zero integers. We need to find the maximum 
        possible length of a subarray such that it has alternating positive
        and negative elements.
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
    int result = 1;
    int count = 1;
    printf("The length of longest alternating subarray is : ");
    for (int i = 1; i < num; i++) {
        if (a[i] * a[i - 1] < 0) {
            count = count + 1;
            if (count > result) {
                result = count;
            }
        }
        else {
            count = 1;
        }
    }
    printf("%d", result);
}

/*
Input :
num = 4
Array = [-1, -4, -5, 20]

Output :

The length of longest alternating subarray is : 2
*/
