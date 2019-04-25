

import java.util.*; 
  
class Gold{ 
      
    static final int MAX = 100; 
      
    static int getMaxGold(int gold[][],  
                              int m, int n) 
    { 
          
        int goldTable[][] = new int[m][n]; 
          
        for(int[] rows:goldTable) 
            Arrays.fill(rows, 0); 
      
        for (int col = n-1; col >= 0; col--) 
        { 
            for (int row = 0; row < m; row++) 
            { 
                  
                int right = (col == n-1) ? 0 
                        : goldTable[row][col+1]; 
       
                int right_up = (row == 0 || 
                               col == n-1) ? 0 : 
                        goldTable[row-1][col+1]; 
      
                int right_down = (row == m-1 
                            || col == n-1) ? 0 : 
                          goldTable[row+1][col+1]; 
      
                goldTable[row][col] = gold[row][col] 
                 + Math.max(right, Math.max(right_up,  
                                       right_down)); 
                                                        
            } 
        } 
        int res = goldTable[0][0]; 
          
        for (int i = 1; i < m; i++) 
            res = Math.max(res, goldTable[i][0]); 
              
        return res; 
    } 
    public static void main(String arg[]) 
    { 
               int m,n, i, j;
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
           for(j=0; j<n; j++)
           {
               arr[i][j] = scan.nextInt();
           }
       } 
          
        System.out.print(getMaxGold(arr, m, n)); 
    } 
} 
