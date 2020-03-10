#include<iostream>
#include<cmath> //to use sqrt()
using namespace std;

int jump_search(int a[], int n, int key)
{
    int step = sqrt(n);
    int pre_step = 0;
    while (a[min(step, n) - 1]  < key) 
    { 
        pre_step = step; 
        step += sqrt(n); 
        if (pre_step >= n)
        {
            return -1;	
        } 
    }
    while(a[pre_step] < key)
    {
        pre_step++;
        if(pre_step == min(step,n))
        {
            return -1;
        }
    }
    if(a[pre_step] == key)
    {
        return pre_step;
    }
    else
    {
        return -1;
    }
}
int main()
{
    int no,ele;
    cout << "Enter no. of elements in an array: ";
    cin >> no;
    int arr[no];
    cout << "Enter elements in an array in increasing order: ";
    for(int i=0;i<no;i++)
    {
        cin >> arr[i];
    }
    cout << "Enter a number to be searched from array: ";
    cin >> ele;
    int result = jump_search(arr,no,ele);
    if(result == -1)
    {
        cout << ele << " is not present in array." << endl;
    }
    else
    {
        cout << ele << " is present at index no. " << result+1 << endl;
    }
    return 0;
}



/*
INPUT:
	N=12
	arr={0,1,4,8,9,13,17,26,32,42,46,50}
	key=15

OUTPUT:
	15 is not presen in array.
___________________________________________________		

INPUT:
	N=12
	arr={0,1,4,8,9,13,17,26,32,42,46,50}
	key=32
OUTPUT:
	32 is present at index no. 8
*/
