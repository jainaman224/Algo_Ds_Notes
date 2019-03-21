import java.io.*;
import java.util.*;

public class Main {

    public static boolean isPossible(int [][]sudoku,int r,int c,int n)
    {
        for(int i=0;i<9;i++)
        {
            if(sudoku[r][i]==n)
                return false;
            if(sudoku[i][c]==n)
                return false;
        }
        int sr=(r/3)*3;
        int sc=(c/3)*3;
        for(int i=sr;i<sr+3;i++)
        {
            for(int j=sc;j<sc+3;j++)
            {
                if(sudoku[i][j]==n)
                    return false;
            }
        }
        return true;
    }

    public  static boolean solve(int [][]sudoku,int r,int c)
    {
        if(r==9)
            return true;
        if(c==9)
            return solve(sudoku,r+1,0);
        if(sudoku[r][c]==0)
        {
            for(int i=1;i<=9;i++)
            {
                if(isPossible(sudoku,r,c,i))
                {
                    sudoku[r][c]=i;
                    boolean ans=solve(sudoku,r,c+1);
                    if(ans)
                        return ans;
                    sudoku[r][c]=0;
                }
            }
            return false;
        }
        else
            return solve(sudoku,r,c+1);
    }

    public static boolean sudokuSolver(int [][]sudoku)
    {
        return solve(sudoku,0,0);
    }

    public static void printSudoku(int [][]sudoku)
    {
        System.out.print("solved sudoku is : \n");
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                System.out.print(sudoku[i][j] + " ");
            System.out.println();
        }
    }

    public static void main(String[] args) {
        int [][]sudoku = new int[9][9];
        Scanner sc = new Scanner(System.in);
        System.out.print("Provide the sudoku \n\'0\' represents blank space \n");
        for(int i=0;i<9;i++)
        {
            for (int j=0;j<9;j++)
            {
                int temp_num = sc.nextInt();
                sudoku[i][j] = temp_num;
            }
        }
        boolean ans = sudokuSolver(sudoku);
        if(ans)
            printSudoku(sudoku);
        else
            System.out.println("Can't solve this sudoku ");
    }
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
