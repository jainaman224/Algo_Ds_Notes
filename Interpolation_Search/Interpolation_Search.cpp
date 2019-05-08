#include <iostream>
using namespace std;

int interpolation (int arr[100], int n, int val)
{
    //Starting and ending index of the array
    int high, low;

    // Rise is the difference between high index and low index
    // Run is the difference between value at high index and low index
    int rise, run;    
    
    high = n - 1;
    low = 0;

    while( low <= high && val >= arr[low] && val <= arr[high])
    {
        rise = high - low;
        run = arr[high] - arr[low];
        
        if (high == low)
            return 0;

        int x, pos;
        x = val - arr[low];
        
        //Probing the position with keeping 
        // uniform distribution in mind. 
        if (run != 0) 
            pos = low + (x * rise) / run ;
        else
            pos = low + (x * rise);

        if (arr[pos] == val)
            return pos;
            
        // If x is smaller, x is in the lower part
        else if (val < arr[pos])
            high = pos - 1;
            
        //If x is larger, x is in upper part 
        else
            low = pos + 1;
    }    
    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the sorted array: ";
    for(int i = 0; i < n; i++)
        cin >> arr[i];
        
    int val;
    cout << "Enter the value to be searched: ";
    cin >> val;

    int index;   
    index = interpolation(arr, n, val);
    cout << "The element is present at index: " << index;
    return 0;
}

/*Enter the number of elements: 6
Enter the sorted array: 2
4
6
8
10
12
Enter the value to be searched: 8
The element is present at index: 3*/
