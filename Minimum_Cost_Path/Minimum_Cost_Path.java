/*
Finding minimum cost path in 2-D array "array[][]" to reach a position (left, right)
in array[][] from (0, 0).
Total cost of a path to reach (left, right) is sum of all the costs on that 
path (including both source and destination).
*/

import java.util.*;

class Min_Cost
{ 
    // Finding minimum cost path in 2-D array 
    static int minimumCost(int array[][], int left, int right)  
    { 
        int min;
        // For invalid left and right query
        if (left < 0 || right < 0) 
            return  Integer.MAX_VALUE;  
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

    public static void main(String args[])  
    { 
        Scanner sc = new Scanner(System.in); 
        int row = sc.nextInt();
        int col = sc.nextInt();
        int[][] array = new int[row][col];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) 
                array[i][j] = sc.nextInt();
        int left = sc.nextInt();
        int right = sc.nextInt();
        System.out.print(minimumCost(array, left, right)); 
    } 
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
