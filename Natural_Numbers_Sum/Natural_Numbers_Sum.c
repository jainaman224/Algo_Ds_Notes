/*
    Sum of First N Natural Numbers

    The task is to find sum of first n natural numbers, where n is 
    the number input to us. We use the well known formula,
    sum = n * (n + 1)/2 to compute the sum

*/

#include<stdio.h>

int main() {
    int num;
    printf("Enter N: ");
    scanf("%d", &num);
    int sum = num * (num + 1) / 2;
    printf("The sum of first %d natural numbers is : %d", num, sum);
}

/*
    Input : num = 6
    Output : The sum of first 6 natural numbers is : 21
*/
