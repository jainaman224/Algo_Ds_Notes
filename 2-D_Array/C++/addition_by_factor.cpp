#include<iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter dimensions of 2-D array: ";
    cin >> n >> m;

    int arr1[n][m], arr2[n][m], i, j;
    cout << "Enter factor of first and second array: ";

    int a, b;
    cin >> a >> b;

    cout << "Enter values of first array: ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin >> arr1[i][j];
        }
        cout << endl;   //to add a new line when elements of other rwo are added
    }

    cout << "Enter values of second array: ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cin >> arr2[i][j];
        }
        cout << endl;
    }

    int arr[n][m];
    //array in which answer i.e. a*arr1+b*arr2 is stored
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            arr[i][j]=a*arr1[i][j]+b*arr2[i][j];
        }
    }

    cout << "Added matrix is: ";
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

// Enter dimensions of 2-D array: 2 2
// Enter factor of first and second array: 1
// 2
// Enter values of first array: 1
// 2

// 3
// 4

// Enter values of second array: 1
// 3

// 5
// 7

// Added matrix is: 3 8
// 13 18
