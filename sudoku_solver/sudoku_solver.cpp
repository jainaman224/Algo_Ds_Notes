#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[][9],int r,int c,int n)
{
  for(int i=0;i<9;i++)
  {
    if(arr[r][i]==n)
      return false;
    if(arr[i][c]==n)
      return false;
  }
  int sr=(r/3)*3;
  int sc=(c/3)*3;
  for(int i=sr;i<sr+3;i++)
  {
    for(int j=sc;j<sc+3;j++)
    {
      if(arr[i][j]==n)
        return false;
    }
  }
  return true;
}

bool solve(int arr[][9],int r,int c)
{
  if(r==9)
    return true;
  if(c==9)
    return solve(arr,r+1,0);
  if(arr[r][c]==0)
  {
    for(int i=1;i<=9;i++)
    {
      if(isPossible(arr,r,c,i))
      {
        arr[r][c]=i;
        bool ans=solve(arr,r,c+1);
        if(ans)
          return ans;
        arr[r][c]=0;
      }
    }
    return false;
  }
  else
    return solve(arr,r,c+1);  
}

bool sudokuSolver(int board[][9])
{
 return solve(board,0,0); 
}

void printSudoku(int sudoku[][9])
{
	cout<<"solved sudoku is : "<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout<<sudoku[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	int sudoku[9][9];
	cout<<"Provide the sudoku \n\'0\' represents blank space "<<endl;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cin>>sudoku[i][j];
	}
	bool ans = sudokuSolver(sudoku);
        if(ans)
            printSudoku(sudoku);
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