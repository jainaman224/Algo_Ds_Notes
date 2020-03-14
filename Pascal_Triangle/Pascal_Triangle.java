import java.util.Scanner;

class PascalsTriangle
{
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter number of rows");
        int n = s.nextInt(); 
        int i, j, k;
        int a[][] = new int[n][n]; //Create an array of n * n
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(j==0)
                    a[i][j] = 1; //for the first value in each row give the value 1
                else
                    a[i][j] = 0; // make the rest 0
            
            }
        }
        for(i = 1; i < n; i++)
        {
            for(j = 1; j <= i; j++)
            {
                a[i][j] = a[i - 1][j - 1] + a[i - 1][j]; // calculate the next value
            }
        }
        for(i = 0; i < n; i++)
        {
            
                for(k = 0; k < n - i; k++)
                {
                    System.out.print("  "); //give the required spaces
                }
            
                for(j = 0; j <= i; j++)
                {
                    System.out.printf(" %3d", a[i][j]); // print the value
                }
                System.out.println();
            
        }
    }
}
/*
INPUT:
Enter number of rows
5
OUTPUT:
             1
           1   1
         1   2   1
       1   3   3   1
     1   4   6   4   1
*/
