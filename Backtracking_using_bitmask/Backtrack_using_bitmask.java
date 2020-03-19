import java.util.*; 

class Solution 
{
    //Keeps track of the # of valid solutions
    static int ans = 0;

    public static int power(int x, int y) 
    { 
<<<<<<< HEAD
<<<<<<< HEAD
        if(y == 0)
            return 1;
        int result = power(x, y / 2); 
        if(y % 2 == 0)
            return result * result;
        else
            return x * result * result;
    }

    //Checks all possible board configurations
    public static void solveNQueens(int left, int col, int right, int n, int done)
    {
        //All columns are occupied, so the solution must be complete
        if(col == done)
=======
        if(y==0)
=======
        if(y == 0)
>>>>>>> d83e063... Update Backtrack_using_bitmask.py
            return 1;
        int result = power(x, y / 2); 
        if(y % 2 == 0)
            return result * result;
        else
            return x * result * result;
    }

    //Checks all possible board configurations
    public static void solveNQueens(int left, int col, int right, int n, int done)
    {
        //All columns are occupied, so the solution must be complete
<<<<<<< HEAD
        if(col==done)
>>>>>>> 42bb684... Backtracking using Bitmasking
=======
        if(col == done)
>>>>>>> d83e063... Update Backtrack_using_bitmask.py
        {
            ans++;
            return;
        }

        //Gets a bit sequence with "1"s where ever there is an open "slot"
<<<<<<< HEAD
<<<<<<< HEAD
        int pos = ~(left | col | right) & done;

        //Loops as long as there is a valid place to put another queen.
        while(pos > 0)
        {
            int bit = pos & (-pos);
            pos = pos - bit;
            solveNQueens((left | bit) >> 1, col | bit, (right | bit) << 1, n, done);
=======
        int pos = ~(left|col|right) & done;
=======
        int pos = ~(left | col | right) & done;
>>>>>>> d83e063... Update Backtrack_using_bitmask.py

        //Loops as long as there is a valid place to put another queen.
        while(pos > 0)
        {
            int bit = pos & (-pos);
            pos = pos - bit;
<<<<<<< HEAD
            solveNQueens((left|bit)>>1, col|bit, (right|bit)<<1, n, done);
>>>>>>> 42bb684... Backtracking using Bitmasking
=======
            solveNQueens((left | bit) >> 1, col | bit, (right | bit) << 1, n, done);
>>>>>>> d83e063... Update Backtrack_using_bitmask.py
        }
    }

    public static void main(String[] args)  
    { 
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        //Helps identify valid solutions
<<<<<<< HEAD
<<<<<<< HEAD
        int done = power(2, n) - 1;
        solveNQueens(0, 0, 0, n, done); 
=======
        int done = power(2,n)-1;
        solveNQueens(0,0,0,n,done); 
>>>>>>> 42bb684... Backtracking using Bitmasking
=======
        int done = power(2, n) - 1;
        solveNQueens(0, 0, 0, n, done); 
>>>>>>> d83e063... Update Backtrack_using_bitmask.py
        System.out.print(ans);
        input.close();
    }  
};
<<<<<<< HEAD
<<<<<<< HEAD

=======
>>>>>>> 42bb684... Backtracking using Bitmasking
=======

>>>>>>> d83e063... Update Backtrack_using_bitmask.py
/*
Sample Input: 
4
Sample Output: 
2
Sample Input: 
5
Sample Output: 
10
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 42bb684... Backtracking using Bitmasking
