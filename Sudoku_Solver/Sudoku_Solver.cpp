#include <bits/stdc++.h>
using namespace std;

/* check wether number 'num' can be placed at in r'th row and
   c'th column of the given sudoku */
bool is_possible(int sudoku[][9],int row,int col,int num)
{
    for(int i=0;i<9;i++)
    {
        // check whether number 'num' is present in the r'th row
        if(sudoku[row][i]==num)
            return false;

        //check whether number 'num' is present in the c'th cloumn
        if(sudoku[i][col]==num)
            return false;
    }

    //check whether number 'num' is present in the corresponding 3*3 box
    int row_num_of_box =(row/3)*3;  // row number of first cell of the corresponding 3*3 box
    int col_num_of_box =(col/3)*3;  // column number of first cell of the corresponding 3*3 box

    for(int i=row_num_of_box;i<row_num_of_box+3;i++)
    {
        for(int j=col_num_of_box;j<col_num_of_box+3;j++)
        {
            if(sudoku[i][j]==num)
                return false;
        }
    }
    return true;
}

bool solve_sudoku(int sudoku[][9],int row,int col)
{
    if(row == 9)
        return true;
    if(col == 9)
        return solve_sudoku(sudoku,row+1,0);
    if(sudoku[row][col]==0)
    {
        for(int i=1;i<=9;i++)
        {
            if(is_possible(sudoku,row,col,i))
            {
                sudoku[row][col]=i;
                if(solve_sudoku(sudoku,row,col+1))
                    return true;
                sudoku[row][col]=0;
            }
        }
        return false;
    }
    else
        return solve_sudoku(sudoku,row,col+1);  
}

bool can_solve(int sudoku[][9])
{
    return solve_sudoku(sudoku,0,0); 
}

void print_sudoku(int sudoku[][9])
{
    cout<<"solved sudoku is : "<<endl;
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
	{
	    cout<<sudoku[i][j]<<" ";
	}
	cout<<endl;
    }
    return;
}

int main()
{
    int sudoku[9][9];
    cout<<"Provide the sudoku \n\'0\' represents blank space "<<endl;
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
        {
	    cin>>sudoku[i][j];
        }
    }
    if(can_solve(sudoku))
        print_sudoku(sudoku);
    else
        cout<<"Can't solve this sudoku \n";
    return 0;
}

/*
sample input :
(cpoied from https://dingo.sbs.arizona.edu/~sandiway/sudoku/examples.html)
0 0 0 2 6 0 7 0 1
6 8 0 0 7 0 0 9 0
1 9 0 0 0 4 5 0 0
8 2 0 1 0 0 0 4 0
0 0 4 6 0 2 9 0 0
0 5 0 0 0 3 0 2 8
0 0 9 3 0 0 0 7 4
0 4 0 0 5 0 0 3 6
7 0 3 0 1 8 0 0 0
*/

/*
this code is written by raghav dalmia
wwww.github.com/raghav-dalmia
*/

