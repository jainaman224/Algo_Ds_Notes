#include<bits/stdc++.h>
using namespace std; 
char board[20][20];
bool isPossible(int n , int row , int col)
{
	/* This Function is used to find , if position of board 
		can be used for placing the queen or not 
		For this we check Three Condition , if these condition satisfies then we can't place Queen at this Position:-
		a) If queen lies in Same column
		b) If queen lies in Upper Left Diagonal
		c) If queen lies in Upper Right Diagonal
    */
    // Same Column
  for(int i=row-1;i>=0;i--)
  {
    if(board[i][col] == 'Q')
	{
      return false;
    }
  }
   //Upper Left Diagonal
  for(int i=row-1,j=col-1;i>=0 && j>=0 ; i--,j--)
  {
    if(board[i][j] =='Q')
	{
      return false;
    }
  }
   // Upper Right Diagonal

  for(int i=row-1,j=col+1;i>=0 && j<n ; i--,j++)
  {
    if(board[i][j] == 'Q')
	{
      return false;
    }
  }
     
  return true; // if these condition doesn't satsfies then Position Can be used.
}
void nQueenHelper(int n,int row){
  if(row==n){
    // We have reached some solution.
    // Print the board matrix
    // return
    for(int i=0;i<n;i++)
	{
      for(int j=0;j<n;j++)
	    {
            cout << board[i][j] << " ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;

  }
  // Place at all possible positions and move to smaller problem
  for(int j=0;j<n;j++)
  {
    if(isPossible(n,row,j))
	{
      board[row][j] = 'Q';
      nQueenHelper(n,row+1);
      board[row][j] = '-';
    }
  }
  return;

}
void placeNQueens( int n){

  memset(board,'-',n*n*sizeof(char)); // This function converts the value of a character to unsigned character and copies it into each of  n*n character of the object pointed by the given board[][].

  nQueenHelper(n,0);

}
int main(){
    int n;
    cin>>n;
    if(n<4 && n>1)
        {
  		    cout<<"Not Possible"<<endl;
        }
    else
        placeNQueens(n);
  return 0;
}
/*
Example
Input:

2

Output:

Not Possible
-------------------------------------------------------------
Input:

4

Output:
-   Q   -   -
-   -   -   Q
Q   -   -   -
-   -   Q   -

-   -   Q   -
Q   -   -   -
-   -   -   Q
-   Q   -   -
*/



