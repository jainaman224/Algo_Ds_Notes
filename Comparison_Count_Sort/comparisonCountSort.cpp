#include <iostream>
using namespace std;


/*
Comparison Count Sort is a Sorting algorithm having time complexity O(n^2)
Every pair of elements is compared and a count is mainatined for each index. 
The count contains the number of elements that are smaller than the element at that particular index.
This count for each element determines its index in the sorted array.
This is not an inplace algorithm and is not stable
*/

void comparisoncountsort(int *a,int *b,int n);

int main()
{
    int n;
    cout<<"Enter number of elements"<<endl;
    cin>>n;
    int a[n],b[n];
    cout<<"Enter the elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    comparisoncountsort(a,b,n);

    cout<<"The sorted array is "<<endl;

    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";

    return 0;
}

void comparisoncountsort(int *a,int *b,int n)
{
    int count[n] = {0};
    for(int i = 0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                count[i]++;
            }else
            {
                count[j]++;
            }
            
        }
    }

    for(int i=0;i<n;i++)
    {
        b[count[i]] = a[i];
    }
}


/*

Output
$ g++ comparisonCountSort.cpp 
$ ./a.out

Enter number of elements
10
Enter the elements
23 1 4556 223 52 782 909 345 1234 11
The sorted array is 
1 11 23 52 223 345 782 909 1234 4556 

*/
