#include <iostream>
#include <math.h>

using namespace std; 
int main()
{
    int arr[50], sum;
    int num, i;

    cout << "Enter number of elements in array: ";
    cin >> num;

    cout << "Enter your array: ";
    for (i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    float mean = 0, v = 0, sd = 0;    

    for (i = 0; i < num; i++)
    {
        // Calculating sum of the array
        mean = mean + float(arr[i]);
    }

    //  mean is the average of the numbers
    mean = mean / float(num);   

    for (i = 0; i < num; i++)
    {
        float(sum) = float(sum) + float((pow(float(arr[i]) - mean, 2)));
    }

    // Variance is the average of the squared differences from the Mean
    v = float(float(sum) / float(num));

    // Standard Deviation is a measure of how spread out numbers are, it is the square root of the Variance.
    float x = 0.5;
    sd = pow(v, x);

    cout << "Mean = " << mean;
    cout << "\nVariance = " << v;
    cout << "\nStandard Deviation = " << sd;
} 

/*
Enter number of elements in array: 5
Enter your array: 10
100
9
2
4
Mean = 25
Variance = 4.4
Standard Deviation = 2.09762*/
