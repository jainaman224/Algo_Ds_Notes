#include <iostream>

using namespace std;
int main()
{
    int n,m;
    cout << "Enter size of matrix :"<< endl;
    cout << "Row : ";
    cin >> m;
    cout << "Column : ";
    cin >> n;
    int a[m][n];
    
    //for storing matrix.
    if(m == n)									
    {
        cout << "Enter Matrix :" << endl;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int sum = 0;			
        
        //for calculating sum both the diagonals.        
        for(int i = 0; i < m; i++)						
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j || i + j == n-1)
                {
                    sum += a[i][j];
                }
            }
        }
        sum -= a[n/2][n/2];
        cout << endl << "Diagonal Sum : " << sum;
    }
    else
    {
      cout << endl << "Diagonals are present in square matrix only.." << endl;
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

Diagonal Sum : 20

*/
