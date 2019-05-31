//program to find odd and even numbers from a array

#include <stdio.h>

void main(){
    int a[20], i, n;
    printf("Enter the array size ");
    scanf("%d", &n);
    printf("Enter the array elements\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    printf("Even numbers are\n");
    for(i = 0; i < n ; i++) {
        if(a[i] % 2 == 0) {
            printf("%d\t", a[i]);
        }
    }
    printf("\nOdd numbers are\n");
    for(i = 0; i < n; i++) {
        if(a[i] %2 != 0) {
            printf("%d\t", a[i]);
        }
    }
}

//output
//Enter the array size 5
//Enter the array elements
//2 5 15 6 9
//Even numbers are
//2 6
//Odd numbers are
//5 15 9

