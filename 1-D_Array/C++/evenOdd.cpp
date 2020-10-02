// C++ program to count even and odd numbers in an array
#include<iostream>
using namespace std;

// To count number of even elements
int no_of_even_elem(int arr[], int n)
{
    // Initialization
    int even_num = 0;

    // Finding even numbers in array
    for(int i = 0; i < n; i++)
    {
        if (arr[i] %2 == 0)
            even_num +=1 ;
    }

    return even_num;   
}

//--- main--- function
int main()
{
    // initialising variables
    int arrlength = 0, num = 0;
    int arr[50], n ;

    // number of elements of list 
    cout << "Enter number of elements : ";
    cin >> n;

    cout << "Enter your array : ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    num = no_of_even_elem(arr, n);
    cout << "Number of odd elements in array : " << n - num << endl;
    cout << "Number of even elements in array : " << num << endl;
    
    return 0;
}

/*
Sample Testcase
Enter number of elements : 4
2
1
67
43
Number of odd elements in array 3
Number of even elements in array 1
*/
