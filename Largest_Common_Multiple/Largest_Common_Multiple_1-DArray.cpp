/*This code is to find the Largest__common_multiple of an given array of elements*/ 

#include <iostream>

using namespace std;

int getLCM(int a, int b) 
{
    int m;
    m = (a > b) ? a : b;
    while (true) {
        if (m % a == 0 && m % b == 0)
            // returns the value to getLCMArray function
            return m;
        m++;
    }
}

int getLCMArray(int arr[], int n) 
{
    int lcm = getLCM(arr[0], arr[1]);
    for (int i = 2; i < n; i++) 
    {
        // calls function getLCM to compute the LCM of two numbers
        lcm = getLCM(lcm, arr[i]); 
    }
    // returns LCM to main.
    return lcm; 
}

int main() 
{
    int n, i;
    cout << "Enter the no. of elements of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array\n";
    for (i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    cout << "LCM of array elements: " << getLCMArray(a, n);
}

/*Enter the no. of elements of array
5
Enter the elements of array
4
6
12
24
30
LCM of array elements: 120*/
