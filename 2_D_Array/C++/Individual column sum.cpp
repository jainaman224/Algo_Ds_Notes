#include <iostream>

using namespace std;

int main()
{
    int n,m;
    cout << "Enter size of matrix :" << endl;
    cout << "Row :";
    cin >> m;
    cout <<"Column :";
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
    
    //for calculating each column sum.
    for(int j = 0; j < n; j++)                                              
    {
        int sum = 0;
        for(int i = 0; i < m; i++)
        {
            sum += a[i][j];
        }
        cout << "Sum of column " << j+1 << " : " << sum << endl;
    }
    return 0;
}

/*
Output

Enter size of matrix :
Row : 2
Column : 2
Enter Matrix :
4
5
6
7
Sum of column 1 : 10
Sum of column 2 : 12

*/
