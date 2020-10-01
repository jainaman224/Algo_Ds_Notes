#include <stdio.h>
#include <math.h>

int main()
{
    int arr[50], sum;
    int num, i;

    printf("Enter number of elements in array: ");
    scanf("%d", &num);

    printf("Enter your array: ");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    float mean, v, sd;
    mean = 0;

    for (i = 0; i < num; i++)
    {
        // Calculating sum of the array
        mean = mean + arr[i];
    }

    //  mean is the average of the numbers
    mean = mean / num;

    sum = 0;

    for (i = 0; i < num; i++)
    {
        sum = sum + (pow(arr[i] - mean, 2));
    }

    // Variance is the average of the squared differences from the Mean
    v = sum / num;

    // Standard Deviation is a measure of how spread out numbers are, it is the square root of the Variance.
    sd = pow(v, 1/2);

    printf("Mean = %f \nVariance = %f \nStandard Deviation = %f \n", mean, v, sd);
} 

/*
Enter number of elements in array: 5
Enter your array: 1
2
3
4
5
Mean = 3.000000
Variance = 2.000000
Standard Deviation = 1.000000*/
