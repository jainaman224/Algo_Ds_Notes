#include <iostream>

using namespace std;

int main()
{
    int m, n, k, l;
    cout << "Enter size of 1st array :" << endl;
    cout << "Row :";
    cin >> m;
    cout << "Column :";
    cin >> n;
    cout << "Enter size of 2nd array :" << endl;
    cout << "Row :";
    cin >> k;
    cout << "Column :";
    cin >> l;
    int a[m][n], b[k][l];
    if(m == k && n == l)
    {

	//for storing first matrix.
        cout << "Enter 1st array :" << endl;				
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }

	 //for storing second matrix.
        cout << "Enter 2nd array :" << endl;                            
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> b[i][j];
            }
        }
        int c[m][n];

	 //calculating sum of a and b matrices.
        for(int i = 0; i < m; i++)                                     
        {
            for(int j = 0; j < n; j++)
            {
                c[i][j] = a[i][j] + b[i][j];
            }
        }

	//for displaying output matrix.
        cout << "Added Array :" << endl;				
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << c[i][j] << "\t";
            }
            cout << "\n";
        }
    }
    else
    {
        cout << endl << "The two matrices cannot be added due to difference in size." << endl;
    }
    return 0;
}

/*
Ouptput
Enter size of 1st array :
Row :2
Column :3
Enter size of 2nd array :
Row :2
Column :3
Enter 1st array :
1
2
3
4
5
6
Enter 2nd array :
7
8
9
10
11
12
Added Array :
8       10      12
14      16      18
*/
