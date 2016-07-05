#include <iostream>

using namespace std;

int main()
{
    int x;
    int arr[100];
    int N;

    cout<<"\nEnter the number of elements:";
    cin>>N;
    cout<<"\nEnter the elements in sorted order:";
    for(int i=0;i<N;i++)
        cin>>arr[i];
    cout<<"\nEnter the element to be searched:";
    cin>>x;

    int flag=0,pos,low=0,high=N-1,mid;

    if(x>arr[high]||x<arr[low])
    {
        cout<<"\nElement not found";
        return 0;
    }

    while(low<high)
    {
        mid=low+((high-low)*(x-arr[low])/(arr[high]-arr[low]));
        if(arr[mid]==x)
        {
            flag=1;
            pos=mid+1;
            break;
        }
        if(x>arr[mid])
            low=mid+1;
        else
            high=mid-1;

    }
    if(flag==1)
        cout<<"\nElement found at position "<<pos;
    else
        cout<<"\nElement not found.";

    return 0;
}
