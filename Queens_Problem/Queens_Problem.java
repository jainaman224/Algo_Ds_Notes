import java.util.*;

class Queen
{
    //number of queens
    private static int N;
    //chessboard
    private static int[][] board = new int[100][100];

    //function to check if the cell is attacked or not
    private static boolean isAttack(int i,int j)
    {
        int k,l;
        //checking if there is a queen in row or column
        for(k=0;k<N;k++)
        {
            if((board[i][k] == 1) || (board[k][j] == 1))
                return true;
        }
        //checking for diagonals
        for(k=0;k<N;k++)
        {
            for(l=0;l<N;l++)
            {
                if(((k+l) == (i+j)) || ((k-l) == (i-j)))
                {
                    if(board[k][l] == 1)
                        return true;
                }
            }
        }
        return false;
    }

    private static boolean nQueen(int n)
    {
        int i,j;
        //if n is 0, solution found
        if(n==0)
            return true;
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
            {
                //checking if we can place a queen here or not
                //queen will not be placed if the place is being attacked
                //or already occupied
                if((!isAttack(i,j)) && (board[i][j]!=1))
                {
                    board[i][j] = 1;
                    //recursion
                    //wether we can put the next queen with this arrangment or not
                    if(nQueen(n-1)==true)
                    {
                        return true;
                    }
                    board[i][j] = 0;
                }
            }
        }
        return false;
    }

    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        //taking the value of N
        System.out.println("Enter the value of N for NxN chessboard");
        N = s.nextInt();

        int i,j;
        //calling the function
        nQueen(N);
        //printing the matix
        for(i=0;i<N;i++)
        {
            for(j=0;j<N;j++)
                System.out.print(board[i][j]+"\t");
            System.out.print("\n");
        }       
    }
}

// Enter the value of N for NxN chessboard
// 5
// 1       0       0       0       0                                                                                              
// 0       0       1       0       0                                                                                              
// 0       0       0       0       1                                                                                              
// 0       1       0       0       0                                                                                              
// 0       0       0       1       0

