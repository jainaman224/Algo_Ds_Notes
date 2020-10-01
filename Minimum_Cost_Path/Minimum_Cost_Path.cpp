/*
Finding minimum cost path in 2-D array "array[][]" to reach a position (left, right)
in array[][] from (0, 0).
Total cost of a path to reach (left, right) is sum of all the costs on that 
path (including both source and destination).
*/

#include<iostream>
#include<limits.h>
using namespace std; 

const int x = 10;
  
// Finding minimum cost path in 2-D array  
int minimumCost(int array[][x], int left, int right) 
{ 
    int min;
    
    // For invalid left and right query
    if (left < 0 || right < 0) 
        return INT_MAX; 
    else if (left == 0 && right == 0) 
        return array[left][right]; 
    else
    {
        // Finding path with minimum cost i.e. which way to move down, right and diagonally lower cells 
        if (minimumCost(array, left - 1, right - 1) < minimumCost(array, left - 1, right))
            min = (minimumCost(array, left - 1, right - 1) < minimumCost(array, left, right - 1)) ?
                    minimumCost(array, left - 1, right - 1) : minimumCost(array, left, right - 1);
        else 
            min = (minimumCost(array, left - 1, right) <  minimumCost(array, left, right - 1)) ? 
                    minimumCost(array, left - 1, right) : minimumCost(array, left, right - 1);
                    
        return array[left][right] + min; 
    }
} 

int main() 
{ 
    int row, col, array[x][x];
    cin>>row;
    cin>>col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            cin>>array[i][j];
    int left, right;
    cin>>left;
    cin>>right;
    
    cout<<minimumCost(array, left, right); 
    return 0; 
} 

/*
Input:
row = 3
col = 3
array = {{1, 2, 3},
         {4, 5, 6},
         {7, 8, 9}}
left = 2
right = 2
Output:
15
Because to reach from (0, 0) to (2, 2)
the cost for minimum path is (0, 0) –> (1, 1) –> (2, 2); 1 + 5 + 9 = 15
*/
