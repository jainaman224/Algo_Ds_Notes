// Girlscript Summer Of Code
// Goldmine problem  in java

//Given a gold mine of a*b dimensions.
//Each field in this mine contains a positive integer which is the amount of gold in tons. 
//Initially the miner is at first column but can be at any row.
//He can move only (right->,right up /,right down) that is from a given cell,
//the miner can move to the cell diagonally up towards the right or right or diagonally down towards the right.
//Find out maximum amount of gold he can collect.

import java.util.*; 
  
class Hello
{ 
    static final int MAX = 100;
    static int getMaxGold(int gold[][], int m, int n){ 
        int goldTable[][] = new int[m][n]; 
        for(int[] rows:goldTable) 
            Arrays.fill(rows, 0); 
        for (int col = n-1; col >= 0; col--) 
        { 
            for (int row = 0; row < m; row++) 
            { 
                int right = (col == n-1) ? 0 : goldTable[row][col+1];
                int right_up = (row == 0 ||col == n-1) ? 0 :goldTable[row-1][col+1];
                int right_down = (row == m-1|| col == n-1) ? 0 :goldTable[row+1][col+1];
                goldTable[row][col] = gold[row][col]+ Math.max(right, Math.max(right_up,right_down)); 
            } 
        } 
        int res = goldTable[0][0];
        for (int i = 1; i < m; i++) 
            res = Math.max(res, goldTable[i][0]); 
        return res; 
    } 
    
    public static void main(String arg[]) 
    { 
       int m, n, i, j;
       int arr[][] = new int[10][10];
       Scanner scan = new Scanner(System.in);
       // enter row and column for array.
       System.out.print("Enter row for the array (max 10) : ");
       m = scan.nextInt();
       System.out.print("Enter column for the array (max 10) : ");
       n = scan.nextInt();
       // enter array elements.
       System.out.println("Enter " +(m*n)+ " Array Elements : ");
       for(i=0; i<m; i++)
       {    
            for(j = 0; j < n; j++)
            {
               arr[i][j] = scan.nextInt();
            }
       }
       System.out.print(getMaxGold(arr, m, n)); 
    } 
} 

//Input : mat[][] = {{5,4,2},
//                   {1,4,2},
//                  {1,7,3}};
//Output : 12
