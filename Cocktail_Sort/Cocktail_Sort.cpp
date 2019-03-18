#include <stdio.h> 
#include <string.h> 
#include<bits/stdc++.h>
using namespace std; 
 
// A function to swap values  
void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
 
// A function implementing cocktail sort.
void cocktailSort(int a[], int n)
{
	int i, j, k;
	for(i = 0; i < n;)
	{
		
		for(j = i+1; j < n; j++)
		{
			if(a[j] < a[j-1])
				swap(a[j], a[j-1]);
		}
	
		n--;
 
		
		for(k = n-1; k > i; k--)
		{
			if(a[k] < a[k-1])
				swap(a[k], a[k-1]);
		}
		
		i++;
	}
}
 
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
 
	int arr[n];
	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";
		cin>>arr[i];
	}
 
	coacktailSort(arr, n);
 
	// Printing the sorted data.
	cout<<"\nSorted Data ";
	for (i = 0; i < n; i++)
		cout<<" "<<arr[i];
        return 0;
}
