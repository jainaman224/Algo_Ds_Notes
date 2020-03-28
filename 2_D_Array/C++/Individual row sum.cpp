#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cout << "Enter size of matrix :"<< endl;
    cout << "Row : ";
    cin >> m;
    cout << "Column : ";
    cin >> n;
    int a[m][n];
    cout << "Enter Matrix :" << endl;
    
     //for storing matrix.
    for(int i = 0; i < m; i++)                                                 
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    //for calculating each row sum.
    for(int i = 0; i < m; i++)                                                  
    {
        int sum = 0;
        for(int j = 0; j < n; j++)
        {
            sum += a[i][j];
        }
        cout << "Sum of row " << i+1 << " : " << sum << endl;
    }
    return 0;
}

/*
Output
Enter size of matrix :
Row : 3
Column : 3
Enter Matrix :
1
2
3
4
5
6
7
8
9
Sum of row 1 : 6
Sum of row 2 : 15
Sum of row 3 : 24

*/
