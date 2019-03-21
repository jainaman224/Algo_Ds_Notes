#include <bits/stdc++.h>
using namespace std;

bool circle_sort_rec(int *arr,int n)
{
	bool swaped =false;
	if(n<=2)
	{
		if(arr[0]>arr[n-1])
		{
			swap(arr[0],arr[n-1]);
			swaped = true;
		}
		return swaped;
	}
	int mid = (n+1)/2;
	for(int i=0;i<mid;i++)
	{
		if(i == n-i-1)
		{
			if(arr[i]>arr[i+1])
			{
				swap(arr[i],arr[i+1]);
				swaped = true;
			}
		}
		else
		{
			if(arr[i]>arr[n-i-1])
			{
				swap(arr[i],arr[n-i-1]);
				swaped = true;
			}
		}
	}
	if(circle_sort_rec(arr,mid))
		swaped = true;
	if(circle_sort_rec(arr+mid,n-mid))
		swaped =true;
	return swaped;
}

void circle_sort(int *arr,int size)
{
	while(circle_sort_rec(arr,size))
	{
		;
	}
	return;
}

int main()
{
	int size;
	cout<<"Enter the length of array : ";
	cin>>size;

	//allocating heap memory for array
	int *arr = new int[size];

	cout<<"Enter the elements of array : ";
	for(int i=0;i<size;i++)
		cin>>arr[i];

	// calling circle circle sort function/algorithm
	circle_sort(arr,size);	

	// Printing sorted array
	for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";

	return 0;
}
