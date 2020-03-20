// C program to find Largest_common_multiple of n elements
#include <stdio.h>
#include <stdlib.h>

// GCD of 'a' and 'b'
int gcd(int a, int b) 
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Returns LCM of array elements
long long int findlcm(int arr[], int n) 
{
    // Initialize result
    long long int ans = arr[0];

    // ans contains LCM of arr[0], ..arr[i]
    // after i'th iteration,
    int i;
    for (i = 1; i < n; i++)
        ans = (((arr[i] * ans)) / (gcd(arr[i], ans)));

    return ans;
}

// Driver Code
int main() 
{
    int n, i;
    printf("Enter the no of elements of the array\n");
    scanf("%d", & n);
    int arr[n];
    printf("Enter the elements of the array\n");
    for (i = 0; i < n; i++) {
        scanf("%d", & arr[i]);
    }
    printf("LCM : %lld", findlcm(arr, n));
    return 0;
}

/*Enter the no of elements of the array
5
Enter the elements of the array
4 6 12 24 30
LCM : 120*/
