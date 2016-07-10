#include<iostream>
using namespace std;
//Function 

int BinarySearch(int a[], int size, int item)
{
    int start = 0, end = size - 1, mid;
         
            while (start <= end)
            {
                mid = (start + end) / 2;
                if (item == a[mid])
                {
                   
                    return mid;}
                else if (item > a[mid])
                    start = mid + 1;
                else end = mid - 1;
            }
            return -1;
}
int  main()
{
	int arr[1000], size, find;
	cout<<"Enter the Size of Array ";
	cin>>size;
	cout<<"\nEnter Array  ";
	for(int i =0 ; i< size ;i++)
	cin>>arr[i];
	cout << "Enter the value to be Searched";
	cin>>find;
	int ans = BinarySearch(arr, size, find);
	
    if(ans != -1)
        cout << "Found at pos " <<ans+1<< endl;
    else
        cout << "Not Found" << endl;

	return 0;
}
