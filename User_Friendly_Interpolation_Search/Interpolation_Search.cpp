#include <iostream>

using namespace std;

int interpolation(int arr[], int N, int x)
{
    int flag = 0, pos, low = 0, high = N - 1, mid;

    if(x > arr[high] || x < arr[low])
        return -1;

    while(low < high)
    {
        mid = low + ((high - low) * (x - arr[low]) / (arr[high] - arr[low]));
        
        if(arr[mid] == x)
        {
            flag = 1;
            pos = mid + 1;
            return pos;
        }
        
        if(x > arr[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }
    
    return -1;
}

int main()
{
    int x;
    int arr[100];
    int N, pos;

    cout << "Enter the number of elements : ";
    cin >> N;
    cout << "Enter the elements in sorted order : ";
    
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    
    cout << "Enter the element to be searched : ";
    cin >> x;
    
    pos = interpolation(arr, N, x);
    
    if(pos != -1)
        cout << "Element found at position " << pos << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
