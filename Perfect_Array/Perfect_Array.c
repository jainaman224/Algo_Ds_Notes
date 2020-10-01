/*
    PERFECT ARRAY

    An array which is strictly increasing and then constant, and then strictly 
    decreasing is called a perfect array.
    There should be no variations in between.

*/

#include<stdio.h>

int perfect(int a[], int num) {
    int count = 1;
    while (count < num && a[count] > a[count - 1]) {
        count++;
    }
    while (count < num && a[count] == a[count - 1]) {
        count++;
    }
    while (count < num && a[count] < a[count - 1]) {
        count++;
    }
    if (count == num) {
        return 1;
    }
    return 0;
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
    if (perfect(a, num) == 1) {
        printf("It is a perfect array");
    }
    else {
        printf("It is not a perfect array");
    }
}

/*
    Input : num = 5
            Array : [1, 2, 3, 3, 6]
    Output : It is not a perfect array
*/
